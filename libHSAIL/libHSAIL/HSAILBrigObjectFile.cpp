// University of Illinois/NCSA
// Open Source License
// 
// Copyright (c) 2013, Advanced Micro Devices, Inc.
// All rights reserved.
// 
// Developed by:
// 
//     HSA Team
// 
//     Advanced Micro Devices, Inc
// 
//     www.amd.com
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal with
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:
// 
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimers.
// 
//     * Redistributions in binary form must reproduce the above copyright notice,
//       this list of conditions and the following disclaimers in the
//       documentation and/or other materials provided with the distribution.
// 
//     * Neither the names of the LLVM Team, University of Illinois at
//       Urbana-Champaign, nor the names of its contributors may be used to
//       endorse or promote products derived from this Software without specific
//       prior written permission.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE
// SOFTWARE.
#include "HSAILBrigObjectFile.h"
#include "HSAILBrigContainer.h"

#include <errno.h>
#ifdef _WIN32
#include <io.h>
#define O_BINARY_ O_BINARY
#define LSEEK _lseeki64
#else
#include <unistd.h>
#define O_BINARY_ 0
#define LSEEK lseek64
#endif

#include <cstring>
#include <fcntl.h>
#include <sstream>
#include <iostream>
#include <cstdio>

#include "llvm/Support/ELF.h"
using namespace llvm::ELF;

namespace HSAIL_ASM {

enum {
    ELF_SECTION_STRTAB = -1,
    ELF_SECTION_SYMTAB = -2,
    ELF_SECTION_SHSTRTAB = -3
};

struct BrigIoImpl;

struct SectionDesc {
    int         sectionId;
    const char *brigName;
    const char *bifName;
    const char *symbolName;
    unsigned    type;
    unsigned    flags;
    unsigned    align;
} sectionDescs[] = {
    { BRIG_SECTION_DIRECTIVES, ".directives", ".brig_directives", "__BRIG__directives",   SHT_PROGBITS, 0,           4 },
    { BRIG_SECTION_CODE,       ".code",       ".brig_code",       "__BRIG__code",         SHT_PROGBITS, 0,           4 },
    { BRIG_SECTION_OPERANDS,   ".operands",   ".brig_operands",   "__BRIG__operands",     SHT_PROGBITS, 0,           4 },
    { BRIG_SECTION_DEBUG,      ".debug",      ".debug_hsa",       "__debug_brig__",       SHT_PROGBITS, 0,           4 },
    { BRIG_SECTION_STRINGS,    ".strtab",     ".brig_strtab",     "__BRIG__strtab",       SHT_PROGBITS, 0,           1 },
    { ELF_SECTION_STRTAB,      0,             ".strtab",          0,                      SHT_STRTAB,   SHF_STRINGS, 1 },
    { ELF_SECTION_SYMTAB,      0,             ".symtab",          0,                      SHT_SYMTAB,   0,           8 },
    { ELF_SECTION_SHSTRTAB,    ".shstrtab",   ".shstrtab",        0,                      SHT_STRTAB,   SHF_STRINGS, 1 },
};

const int NUM_PREDEFINED_ELF_SECTIONS = sizeof(sectionDescs)/sizeof(const SectionDesc*);

template<typename T> inline bool myEq(T a, T b) { return a == b; }
inline bool myEq(const char* a, const char* b) { 
    if (a==0 || b==0) return false;
    return 0 == strcmp(a, b); 
}

template<typename T>
inline const SectionDesc* descByKey(T SectionDesc::* field, T value) {
    static const int NUM_PREDEFINED_ELF_SECTIONS = sizeof(sectionDescs)/sizeof(sectionDescs[0]);
    for(int i=0; i<NUM_PREDEFINED_ELF_SECTIONS; ++i) {
        if (myEq(sectionDescs[i].*field,value)) return &sectionDescs[i];
    }
    return 0;
}

static const SectionDesc& descById(int sectionId) {
    const SectionDesc* dsc = descByKey(&SectionDesc::sectionId, sectionId);
    assert(dsc);
    return *dsc;
}

IOAdapter::~IOAdapter() {
}

WriteAdapter::~WriteAdapter() {
}

ReadAdapter::~ReadAdapter() {
}

ReadWriteAdapter::~ReadWriteAdapter() {
}

struct Elf32Policy {
    typedef Elf32_Ehdr Ehdr;
    typedef Elf32_Shdr Shdr;
    typedef Elf32_Sym Sym;
    typedef Elf32_Word ElfWord;
    typedef Elf32_Half ElfHalf;

    enum { ELFCLASS = ELFCLASS32, EM_HSAIL_ = 0xAF5A};
};

struct Elf64Policy {
    typedef Elf64_Ehdr Ehdr;
    typedef Elf64_Shdr Shdr;
    typedef Elf64_Sym Sym;
    typedef Elf64_Word ElfWord;
    typedef Elf64_Half ElfHalf;

    enum { ELFCLASS = ELFCLASS64, EM_HSAIL_ = 0xAF5B};
};

template<typename Policy>
class BrigIOImpl {
    typedef typename Policy::Ehdr Ehdr;
    typedef typename Policy::Shdr Shdr;
    typedef typename Policy::Sym Sym;
    typedef typename Policy::ElfWord ElfWord;
    typedef typename Policy::ElfHalf ElfHalf;
    Ehdr elfHeader;
    std::vector<Shdr> sectionHeaders;
    std::vector<char> sectionNameTable;
    std::vector<char> symtabData;
    std::vector<char> strtabData;
    std::vector< SRef > sectionData;
    int fmt;

public:
    BrigIOImpl(int fmt_) 
        : fmt(fmt_)
    {
    }

    // Loading code
public:
    int readContainer(BrigContainer &c, ReadAdapter *s) {
        if (s->pread((char*)&elfHeader, sizeof(elfHeader), 0)) {
            s->errs << " reading ELF header";
            return 1;
        }
        if (!elfHeader.checkMagic()) {
            s->errs << "Invalid ELF header";
            return 1;
        }
        if (fmt == FILE_FORMAT_AUTO) {
            if (elfHeader.e_type != ET_NONE && elfHeader.e_machine == Policy::EM_HSAIL_) {
                fmt = FILE_FORMAT_BIF;
            } else if (elfHeader.e_type == ET_NONE && elfHeader.e_machine == EM_NONE) {
                fmt = FILE_FORMAT_BRIG;
            } else {
                s->errs << "Unable to detect format with type=" 
                          << elfHeader.e_type
                          << ", machine = "
                          << elfHeader.e_machine;
            }
        }
        sectionHeaders.resize(elfHeader.e_shnum);
        for(int i=0; i < elfHeader.e_shnum; ++i) {
            if (s->pread((char*)&sectionHeaders[i], sizeof(Shdr),
                              elfHeader.e_shoff + i * elfHeader.e_shentsize)) 
            {
                s->errs << " reading section headers";
                return 1;
            }
        };
        if (readSection(sectionNameTable, s, elfHeader.e_shstrndx)) return 1;
        // force nul termination of string table
        sectionNameTable.push_back(0);

        for(int i=1; i < elfHeader.e_shnum; ++i) {
            const char* name = sectionName(i);
            if (!name) continue;

            const SectionDesc* desc = descByKey(predefinedSectionName(), name);
            if (!desc) continue;
            if (desc->sectionId < 0) continue;

            std::vector<char> data;
            if (readSection(data, s, i)) return 1;

            if (!data.empty()) {
                c.sectionById(desc->sectionId).setData(&data[0],data.size()); // TBD095 replace with normal swap
            }
        };
        return 0;
    }
private:

    int preadVec(ReadAdapter *s, std::vector<char> &dst, unsigned size, uint64_t ofs) const {
        dst.resize(size);
        if (0 == size) return 0;
        return s->pread(&(dst[0]), size, ofs);
    };

    const char* sectionName(unsigned index) {
        if (index >= sectionHeaders.size()) {
            return 0;
        }
        unsigned ofs = sectionHeaders[index].sh_name;
        if (ofs >= sectionNameTable.size()) {
            return 0;
        }
        return &sectionNameTable[ofs];
    }

    const char* SectionDesc::* predefinedSectionName() {
        switch(fmt & FILE_FORMAT_MASK) {
        case FILE_FORMAT_BIF:
            return &SectionDesc::bifName;
        case FILE_FORMAT_BRIG:
            return &SectionDesc::brigName;
        default:
            assert(0);
            return 0;
        }
    }

    int readSection(std::vector<char> &dst, ReadAdapter *s, unsigned index) {
        if (index >= sectionHeaders.size()) {
            s->errs << "Section index " << index << " out of bounds";
            return 1;
        }
        Shdr &shdr = sectionHeaders[index];
        if (shdr.sh_size > (std::numeric_limits<unsigned>::max)()) {
            s->errs << "Section size more than 4GB is not supported";
            return 1;
        }
        if (preadVec(s, dst, static_cast<unsigned>(shdr.sh_size), shdr.sh_offset))
        {
            const char* name = sectionName(index);
            s->errs << " reading section ";
            if (name) { s->errs << name; } else { s->errs << index; } 
            return 1;
        }
        return 0;
    }

    // Saving code

public:

    int writeContainer(WriteAdapter *s, const BrigContainer& c) {
        reset();
        for(int i = 0; i < NUM_BRIG_SECTIONS; ++i) {
            addSection(descById(i), c.sectionById(i).data());
        }
        unsigned strTabNdx = 0;
        unsigned symTabNdx = 0;
        if (fmt == FILE_FORMAT_BIF) {
            strTabNdx = addSection(descById(ELF_SECTION_STRTAB), strtabData);
            symTabNdx = addSection(descById(ELF_SECTION_SYMTAB), symtabData);
            sectionHeaders[symTabNdx].sh_link = strTabNdx;
            sectionHeaders[symTabNdx].sh_entsize = sizeof(Sym);
        }
        unsigned shStrTabNdx = addSection(descById(ELF_SECTION_SHSTRTAB), sectionNameTable);

        // string/symbol tables were resized/reallocated
        if (fmt == FILE_FORMAT_BIF) {
          updateSection(symTabNdx, symtabData);
          updateSection(strTabNdx, strtabData);
        }
        updateSection(shStrTabNdx, sectionNameTable);
        return writeElf(s);
    }
private:

    void reset() {
        sectionHeaders.clear();
        sectionNameTable.clear();
        symtabData.clear();
        strtabData.clear();
        sectionData.clear();
    }

    unsigned addString(std::vector<char> *strtab, const std::string &str) {
        if (strtab->empty()) {
            strtab->push_back(0);
        }
        unsigned pos = static_cast<unsigned>(strtab->size());
        strtab->insert(strtab->end(), str.begin(), str.end());
        strtab->push_back(0);
        return pos;
    }

    int alignFilePos(WriteAdapter *s, unsigned &pos, unsigned align) {
        const char *zeropad = "\0\0\0\0\0\0\0\0";
        assert(align > 0 && (0 == (align&(align-1))));
        int n = ((~pos+1) & (align-1));
        if (n == 0) { return 0; }
        if (s && s->write(zeropad, n)) {
            return 1;
        }
        pos += n;
        return 0;
    }

    void updateSection(unsigned shndx, SRef data) {
        sectionData[shndx] = data;
        sectionHeaders[shndx].sh_size = (ElfWord)data.length();
        for(size_t pos = sizeof(Sym); pos < symtabData.size(); pos += sizeof(Sym)) {
          Sym *pSym = (Sym*)(&symtabData[pos]);
          if (pSym->st_shndx == shndx) {
            pSym->st_size = (ElfWord)data.length();
            break;
          }
        }
    }

    unsigned addSection(const SectionDesc& desc, SRef data) {
        Shdr thisSec;
        memset(&thisSec, 0, sizeof(thisSec));
        if (sectionHeaders.empty()) {
            sectionHeaders.push_back(thisSec);
            sectionData.push_back("");
        }
        assert(data.length() < INT_MAX);
        unsigned shndx = (unsigned)sectionHeaders.size();
        thisSec.sh_type = desc.type;
        thisSec.sh_flags = desc.flags;
        thisSec.sh_addralign = desc.align;
        thisSec.sh_name = addString(&sectionNameTable, desc.*predefinedSectionName());
        thisSec.sh_size = (ElfWord)data.length();
        const char* symbolName = desc.symbolName;
        if (fmt == FILE_FORMAT_BIF && symbolName) {
            Sym sym;
            memset(&sym, 0, sizeof(sym));
            if (symtabData.empty()) {
                symtabData.insert(symtabData.end(), (char*)(&sym), (char*)(&sym+1));
            }
            sym.st_name = addString(&strtabData, symbolName);
            sym.st_value = 0; // Value or address associated with the symbol
            sym.st_size = (ElfWord)data.length(); // Size of the symbol
            sym.st_shndx = shndx; // Section's index
            sym.st_info = (STB_LOCAL << 4) | STT_OBJECT;
            symtabData.insert(symtabData.end(), (char*)(&sym), (char*)(&sym+1));
        }
        sectionHeaders.push_back(thisSec);
        sectionData.push_back(data);
        return shndx;
    }

    int writeContents(WriteAdapter *s) {
        unsigned filePos = sizeof(Ehdr);
        if (s && s->write((char*)&elfHeader, sizeof(Ehdr))) {
            return 1;
        }
        alignFilePos(s, filePos, 4);
        for(unsigned secIndex = 1; secIndex < sectionHeaders.size(); ++secIndex) {
            Shdr &shdr = sectionHeaders[secIndex];
            alignFilePos(s, filePos, shdr.sh_addralign);
            shdr.sh_offset = filePos;
            if (s && s->write(sectionData[secIndex].begin, shdr.sh_size)) {
                return 1;
            }
            filePos += shdr.sh_size;
        }

        alignFilePos(s, filePos, 4);
        elfHeader.e_shoff = filePos;
        if (s && s->write((char*)&sectionHeaders[0], elfHeader.e_shnum * elfHeader.e_shentsize)) {
            return 1;
        }
        return 0;
    }

    int writeElf(WriteAdapter *s) {
        memset(&elfHeader, 0, sizeof(elfHeader));
        memcpy(elfHeader.e_ident, ElfMagic, 4);
        elfHeader.e_ident[EI_CLASS] = Policy::ELFCLASS;
        elfHeader.e_ident[EI_DATA] = ELFDATA2LSB;
        elfHeader.e_ident[EI_VERSION] = EV_CURRENT;
        elfHeader.e_version = EV_CURRENT;
        if (fmt == FILE_FORMAT_BIF) {
            elfHeader.e_type = ET_REL;
            elfHeader.e_machine = Policy::EM_HSAIL_;
            elfHeader.e_flags = 0x16; // mimic objgen
        }

        elfHeader.e_ehsize = sizeof(elfHeader);
        elfHeader.e_shentsize = sizeof(Shdr);
        elfHeader.e_shnum = ElfHalf(sectionHeaders.size());
        elfHeader.e_shstrndx = elfHeader.e_shnum - 1; // must always be the last

        // dry run to calculate section offsets, then 
        return writeContents(0)
            || writeContents(s);
    };
};


// FILE ADAPTER

struct FileAdapter : public ReadWriteAdapter {
    mutable int fd;
    FileAdapter(std::ostream& errs_)
        : IOAdapter(errs_)
        , ReadWriteAdapter(errs_)
        , fd(-1)
    {
    }
    static void printErr(std::ostream& s) {
        s << "Error " << errno << " (" << strerror(errno) << ")";
    }
    int open(const char* filename, bool forWriting) {
        if (forWriting) {
            fd = ::open(filename, O_CREAT|O_TRUNC|O_RDWR|O_BINARY_, 0666);
        } else {
            fd = ::open(filename, O_RDONLY | O_BINARY_);
        }
        if (fd < 0) {
            printErr(errs);
            errs << " opening \"" << filename << "\"";
            return 1;
        }
        return 0;
    }
    int check1(int val) const {
        if (val < 0) {
            printErr(errs);
            return 1;
        } else {
            return 0;
        }
    }
    virtual int write(const char* data, size_t numBytes) const {
//        printf("write fd=%d data=%p size=%d\n", (int)fd, data, numBytes);
        int res = ::write(fd, data, (unsigned)numBytes);
        if (check1(res)) return 1;
        if (res != (int)numBytes) {
            errs << "Wrote " << res << " bytes instead of " << numBytes;
            return 1;
        }
        return 0;
    }
    virtual int pread(char* data, size_t numBytes, uint64_t offset) const {
        int64_t lrc = ::LSEEK(fd, offset, SEEK_SET);
        if (check1((int)lrc)) return 1;
        if ((uint64_t)lrc != offset) {
            errs << "Seeked to " << lrc << " instead of " << offset;
            return 1;
        }
        int rc = ::read(fd, data, (unsigned)numBytes);
        if (check1(rc)) return 1;
        if (rc != (int)numBytes) {
            errs << "Read " << rc << " bytes instead of " << numBytes;
            return 1;
        }
        return 0;
    }
    ~FileAdapter() {
        if (fd >= 0) {
            ::close(fd);
        }
    }
};

// MEMORY ADAPTER

struct VectorAdapter : public ReadWriteAdapter {
    std::vector<char> &buf;
    VectorAdapter(std::vector<char> &buf_, std::ostream &errs_)
        : IOAdapter(errs_)
        , ReadWriteAdapter(errs_)
        , buf(buf_)
    {
    }
    virtual int write(const char* data, size_t numBytes) const {
        buf.insert(buf.end(), data, data + numBytes);
        return 0;
    }
    virtual int pread(char* data, size_t numBytes, uint64_t offset) const {
        if (offset + numBytes > buf.size()) {
            errs << "Reading beyond the end of the buffer";
            return 1;
        }
        if (numBytes == 0) return 0;
        memcpy(data, &buf[static_cast<size_t>(offset)], numBytes);
        return 0;
    }
    ~VectorAdapter() {
    }
};

struct MemoryAdapter : public ReadWriteAdapter {
    char           *buf;
    size_t          bufSize;
    mutable size_t  pos;
    MemoryAdapter(char *buf_, size_t bufSize_, std::ostream &errs_)
        : IOAdapter(errs_)
        , ReadWriteAdapter(errs_)
        , buf(buf_)
        , bufSize(bufSize_)
        , pos(0)
    {
    }
    virtual int write(const char* data, size_t numBytes) const {
        if (pos + numBytes > bufSize) {
            errs << "Writing beyond the end of the buffer";
            return 1;
        }
        memcpy(buf + pos, data, numBytes);
        pos += numBytes;
        return 0;
    }
    virtual int pread(char* data, size_t numBytes, uint64_t offset) const {
        if (offset + numBytes > bufSize) {
            errs << "Reading beyond the end of the buffer";
            return 1;
        }
        if (numBytes == 0) return 0;
        memcpy(data, buf + offset, numBytes);
        return 0;
    }
    ~MemoryAdapter() {
    }
};

// TBD this is the only non-forward dependency on iostream
std::ostream& BrigIO::defaultErrs() {
    return std::cerr;
}

std::auto_ptr<ReadAdapter> BrigIO::fileReadingAdapter(
                const char* fileName, 
                std::ostream& errs)
{
    std::auto_ptr<FileAdapter> theFile( new FileAdapter(errs) );
    if (theFile->open(fileName, false)) {
        theFile.release();
    }
    return std::auto_ptr<ReadAdapter>(theFile);
}

std::auto_ptr<WriteAdapter> BrigIO::fileWritingAdapter(
                const char* fileName, 
                std::ostream& errs)
{
    std::auto_ptr<FileAdapter> theFile( new FileAdapter(errs) );
    if (theFile->open(fileName, true)) {
        theFile.release();
    }
    return std::auto_ptr<WriteAdapter>(theFile);
}

std::auto_ptr<WriteAdapter> BrigIO::memoryWritingAdapter(
                    char         *buf, 
                    size_t        size,
                    std::ostream& errs)
{
    return std::auto_ptr<WriteAdapter>(
            new MemoryAdapter(buf, size, errs) );
}

std::auto_ptr<ReadAdapter> BrigIO::memoryReadingAdapter(
                    const char   *buf, 
                    size_t        size,
                    std::ostream& errs)
{
    return std::auto_ptr<ReadAdapter>(
            new MemoryAdapter((char*)buf, size, errs) );
}

int BrigIO::load(BrigContainer &dst, 
                 int           fmt,
                 ReadAdapter&  src)
{
    unsigned char ident[16];
    if (!(src.pread((char*)ident, 16, 0))) {
			switch(ident[EI_CLASS]) {
			case ELFCLASS32: {
					BrigIOImpl<Elf32Policy> impl(fmt);
					return impl.readContainer(dst, &src);
					}
			case ELFCLASS64: {
					BrigIOImpl<Elf64Policy> impl(fmt);
					return impl.readContainer(dst, &src);
					}
			default:
					src.errs << "Invalid ELFCLASS";
					return 1;
			}
		} else {
			return 1;
		}
}

int BrigIO::save(BrigContainer &src, 
                 int           fmt,
                 WriteAdapter& dst)
{
    BrigIOImpl<Elf32Policy> impl(fmt);
    return impl.writeContainer(&dst, src);
}

}
