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
#include <map>

using std::map;

namespace HSAIL_ASM {

enum {
  EI_MAG0       = 0,
  EI_MAG1       = 1,
  EI_MAG2       = 2,
  EI_MAG3       = 3,
  EI_CLASS      = 4,
  EI_DATA       = 5,
  EI_VERSION    = 6,
  EI_OSABI      = 7,
  EI_ABIVERSION = 8,
  EI_PAD        = 9,
  EI_NIDENT     = 16
};

enum {
  SHT_NULL          = 0,
  SHT_PROGBITS      = 1,
  SHT_SYMTAB        = 2,
  SHT_STRTAB        = 3
};

enum {
  SHF_WRITE         = 0x1,
  SHF_ALLOC         = 0x2,
  SHF_EXECINSTR     = 0x4,
  SHF_MERGE         = 0x10,
  SHF_STRINGS       = 0x20,
  SHF_INFO_LINK     = 0x40,
  SHF_LINK_ORDER    = 0x80
};

enum {
  ET_NONE   = 0,
  ET_REL    = 1
};

enum {
  EM_NONE =   0
};

enum {
  STB_LOCAL = 0
};

enum {
  STT_NOTYPE  = 0,
  STT_OBJECT  = 1
};

enum {
  EV_NONE = 0,
  EV_CURRENT = 1
};

enum {
  ELFDATANONE = 0,
  ELFDATA2LSB = 1,
  ELFDATA2MSB = 2
};

static const char ElfMagic[] = { 0x7f, 'E', 'L', 'F', '\0' };

template<typename T>
struct ElfPolicyBase {
  typedef uint16_t    Half;
  typedef T           Off;
  typedef uint32_t    Word;
  typedef T           Addr;
  typedef T           Xword;

  struct Ehdr {
    unsigned char e_ident[EI_NIDENT];
    Half    e_type;
    Half    e_machine;
    Word    e_version;
    Addr    e_entry;
    Off     e_phoff;
    Off     e_shoff;
    Word    e_flags;
    Half    e_ehsize;
    Half    e_phentsize;
    Half    e_phnum;
    Half    e_shentsize;
    Half    e_shnum;
    Half    e_shstrndx;

    bool checkMagic() const {
      return (memcmp(e_ident, ElfMagic, strlen(ElfMagic))) == 0;
    }
  };

  struct Shdr {
    Word    sh_name;
    Word    sh_type;
    Xword   sh_flags;
    Addr    sh_addr;
    Off     sh_offset;
    Xword   sh_size;
    Word    sh_link;
    Word    sh_info;
    Xword   sh_addralign;
    Xword   sh_entsize;
  };

};

struct Elf32Policy : public ElfPolicyBase<uint32_t> {

  struct Sym {
    Word    st_name;
    Addr    st_value;
    Word    st_size;
    unsigned char st_info;
    unsigned char st_other;
    Half    st_shndx;
  };

  enum { ELFCLASS = 1, EM_HSAIL_ = 0xAF5A};
};

struct Elf64Policy : public ElfPolicyBase<uint64_t> {

  struct Sym {
    Word            st_name;
    unsigned char   st_info;
    unsigned char   st_other;
    Half            st_shndx;
    Addr            st_value;
    Xword           st_size;
  };

  enum { ELFCLASS = 2, EM_HSAIL_ = 0xAF5B};
};


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
    { BRIG_SECTION_INDEX_DATA,                   "hsa_data",    ".brig_strtab",   "__BRIG__strtab",   SHT_PROGBITS, 0,           4 },
    { BRIG_SECTION_INDEX_CODE,                   "hsa_code",    ".brig_code",     "__BRIG__code",     SHT_PROGBITS, 0,           4 },
    { BRIG_SECTION_INDEX_OPERAND,                "hsa_operand", ".brig_operands", "__BRIG__operands", SHT_PROGBITS, 0,           4 },
    { BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED, "hsa_debug",   ".debug_hsa",     "__debug_brig__",   SHT_PROGBITS, 0,           4 },
    { ELF_SECTION_STRTAB,                              0,             ".strtab",        0,                  SHT_STRTAB,   SHF_STRINGS, 1 },
    { ELF_SECTION_SYMTAB,                              0,             ".symtab",        0,                  SHT_SYMTAB,   0,           8 },
    { ELF_SECTION_SHSTRTAB,                            ".shstrtab",   ".shstrtab",      0,                  SHT_STRTAB,   SHF_STRINGS, 1 },
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

int WriteAdapter::writeAlignPad(unsigned pow2) {
    const char zeropad[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    size_t const p = (size_t)getPos();
    size_t const numBytesWrite = align(p, pow2) - p;
    if (numBytesWrite > 0) {
        assert(numBytesWrite <= sizeof zeropad);
        return write((const char*)zeropad, numBytesWrite);
    }
    return 0;
}

ReadAdapter::~ReadAdapter() {
}

ReadWriteAdapter::~ReadWriteAdapter() {
}


template<typename Policy>
class BrigIOImpl {
    typedef typename Policy::Ehdr Ehdr;
    typedef typename Policy::Shdr Shdr;
    typedef typename Policy::Sym Sym;
    typedef typename Policy::Word ElfWord;
    typedef typename Policy::Half ElfHalf;
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
            return 1;
        }
        if (!elfHeader.checkMagic()) {
            s->errs << "Invalid ELF header" << std::endl;
            return 1;
        }
        if (fmt == FILE_FORMAT_AUTO) {
            if (elfHeader.e_machine == Policy::EM_HSAIL_) {
                fmt = FILE_FORMAT_BIF;
            } else {
                fmt = FILE_FORMAT_BRIG;
            }
        }
        sectionHeaders.resize(elfHeader.e_shnum);
        for(int i=0; i < elfHeader.e_shnum; ++i) {
            if (s->pread((char*)&sectionHeaders[i], sizeof(Shdr),
                              elfHeader.e_shoff + i * elfHeader.e_shentsize))
            {
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
            
            bool includesHeader =
                  desc->sectionId < BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED;
            if (c.loadSection(desc->sectionId, data, includesHeader, s->errs)) {
                return 1;
            }
        }
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
            s->errs << "Section index " << index << " out of bounds" << std::endl;
            return 1;
        }
        Shdr &shdr = sectionHeaders[index];
        if (shdr.sh_size > (std::numeric_limits<unsigned>::max)()) {
            s->errs << "Section size more than 4GB is not supported" << std::endl;
            return 1;
        }
        if (preadVec(s, dst, static_cast<unsigned>(shdr.sh_size), shdr.sh_offset))
        {
            const char* name = sectionName(index);
            return 1;
        }
        return 0;
    }

    // Saving code

public:

    int writeContainer(WriteAdapter *s, const BrigContainer& c) {
        reset();
        for(int i = 0; i < c.getNumSections(); ++i) {
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
        bool includesHeader =
            desc.sectionId >= 0 &&
            desc.sectionId < BRIG_SECTION_INDEX_IMPLEMENTATION_DEFINED;
        if (!includesHeader) {
            BrigSectionHeader *header = (BrigSectionHeader*)data.begin;
            data.begin += header->headerByteCount;
        }
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
        if (alignFilePos(s, filePos, 4)) {
            return 1;
        }
        for(unsigned secIndex = 1; secIndex < sectionHeaders.size(); ++secIndex) {
            Shdr &shdr = sectionHeaders[secIndex];
            if (alignFilePos(s, filePos, shdr.sh_addralign)) {
                return 1;
            }
            shdr.sh_offset = filePos;
            if (s && s->write(sectionData[secIndex].begin, shdr.sh_size)) {
                return 1;
            }
            filePos += shdr.sh_size;
        }

        if (alignFilePos(s, filePos, 4)) {
            return 1;
        }
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
            elfHeader.e_flags = 0x1;
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

#if 0
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
            errs << " opening \"" << filename << "\"" << std::endl;
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
    virtual Position getPos() const {
        return ::LSEEK(fd, 0, SEEK_CUR);
    }
    virtual void setPos(Position ofs) {
        int64_t lrc = ::LSEEK(fd, ofs, SEEK_SET);
    }
    virtual int write(const char* data, size_t numBytes) const {
        int res = ::write(fd, data, (unsigned)numBytes);
        if (check1(res)) {
            errs << " writing" << std::endl;
            return 1;
        }
        if (res != (int)numBytes) {
            errs << "Wrote " << res << " bytes instead of " << numBytes << std::endl;
            return 1;
        }
        return 0;
    }
    virtual int pread(char* data, size_t numBytes, uint64_t offset) const {
        int64_t lrc = ::LSEEK(fd, offset, SEEK_SET);
        if (check1((int)lrc)) return 1;
        if ((uint64_t)lrc != offset) {
            errs << "Seeked to " << lrc << " instead of " << offset << std::endl;
            return 1;
        }
        int rc = ::read(fd, data, (unsigned)numBytes);
        if (check1(rc)) {
            errs << " reading" << std::endl;
            return 1;
        }
        if (rc != (int)numBytes) {
            errs << "Read " << rc << " bytes instead of " << numBytes << std::endl;
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
#else
struct FileAdapter : public ReadWriteAdapter {
    mutable FILE* fd;
    FileAdapter(std::ostream& errs_)
        : IOAdapter(errs_)
        , ReadWriteAdapter(errs_)
        , fd(nullptr)
    {
    }
    static void printErr(std::ostream& s) {
        s << "Error " << errno << " (" << strerror(errno) << ")";
    }
    int open(const char* filename, bool forWriting) {
        fd = fopen(filename, forWriting ? "wb+" : "rb");
        if (!fd) {
            printErr(errs);
            errs << " opening \"" << filename << "\"" << std::endl;
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
    virtual Position getSize() const {
        Position pos = getPos();
        if (((int64_t)pos) < 0) return (Position)-1;

        int ok = fseek(fd, (long)0, SEEK_END);
        if (ok != 0) return (Position)-1;
        
        Position size = getPos();
        if (((int64_t)size) < 0) return (Position)-1;

        ok = fseek(fd, (long)pos, SEEK_SET);
        if (ok != 0) return (Position)-1;

        return size;
    }

    virtual Position getPos() const {
        return (Position)ftell(fd);
    }
    virtual void setPos(Position ofs) {
        fseek(fd, 0, SEEK_SET);
    }
    virtual int write(const char* data, size_t numBytes) const {
        size_t const res = fwrite(data, 1, numBytes, fd);
        if (check1((int)res)) {
            errs << " writing" << std::endl;
            return 1;
        }
        if (res != numBytes) {
            errs << "Wrote " << res << " bytes instead of " << numBytes << std::endl;
            return 1;
        }
        return 0;
    }
    virtual int pread(char* data, size_t numBytes, uint64_t offset) const {
        if (check1(fseek(fd, (long)offset, SEEK_SET))) return 1;
        size_t const rc = fread(data, 1, numBytes, fd);
        if (check1((int)rc)) {
            errs << " reading" << std::endl;
            return 1;
        }
        if (rc != numBytes) {
            errs << "Read " << rc << " bytes instead of " << numBytes << std::endl;
            return 1;
        }
        return 0;
    }
    ~FileAdapter() {
        if (fd) {
            fclose(fd);
        }
    }
};
#endif

// MEMORY ADAPTER

struct VectorAdapter : public ReadWriteAdapter {
    std::vector<char> &buf;
    mutable size_t     pos;
    VectorAdapter(std::vector<char> &buf_, std::ostream &errs_)
        : IOAdapter(errs_)
        , ReadWriteAdapter(errs_)
        , buf(buf_)
        , pos(0)
    {
    }
    virtual Position getPos() const { 
        return pos;
    }
    virtual void setPos(Position p) {
        pos = (size_t)p;
    }
    virtual int write(const char* data, size_t numBytes) const {
        size_t newSize = pos + numBytes;
        if (newSize > buf.size()) {
            buf.resize(newSize);
        }
        std::copy(data, data + numBytes, buf.begin() + pos);
        pos += numBytes;
        return 0;
    }
    virtual int pread(char* data, size_t numBytes, uint64_t offset) const {
        if (offset + numBytes > buf.size()) {
            errs << "Reading beyond the end of the buffer" << std::endl;
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
    virtual Position getSize() const {
      return bufSize;
    }

    virtual Position getPos() const { 
        return pos;
    }
    virtual void setPos(Position p) {
        pos = (size_t)p;
    }
    virtual int write(const char* data, size_t numBytes) const {
        if (pos + numBytes > bufSize) {
            errs << "Writing beyond the end of the buffer" << std::endl;
            return 1;
        }
        memcpy(buf + pos, data, numBytes);
        pos += numBytes;
        return 0;
    }
    virtual int pread(char* data, size_t numBytes, uint64_t offset) const {
        if (offset + numBytes > bufSize) {
            errs << "Reading beyond the end of the buffer" << std::endl;
            return 1;
        }
        if (numBytes == 0) return 0;
        memcpy(data, buf + offset, numBytes);
        return 0;
    }
    ~MemoryAdapter() {
    }
};

struct istreamAdapter : public ReadAdapter {
    std::istream&   is;

    istreamAdapter(std::istream& is_, std::ostream &errs_)
        : IOAdapter(errs_)
        , ReadAdapter(errs_)
        , is(is_)
    {}
    ~istreamAdapter() {}

    virtual Position getPos() const {
        return (Position)is.tellg();
    }

    virtual void setPos(Position p) {
        is.seekg(static_cast<std::streamoff>(p), std::ios_base::beg);
    }

    virtual int pread(char* data, size_t numBytes, uint64_t offset) const {
        if ((offset + numBytes) > static_cast<uint64_t>((std::numeric_limits<std::streamoff>::max)())) {
            errs << "Reading beyond the end of the buffer" << std::endl;
            return 1;
        }
        is.seekg(static_cast<std::streamoff>(offset), std::ios_base::beg);
        if (is.fail()) {
            errs << "Stream seek error" << std::endl;
            return 1;
        }
        is.read(data, static_cast<std::streamsize>(numBytes));
        if (is.fail() || static_cast<size_t>(is.gcount()) < numBytes) {
            errs << "Error reading stream" << std::endl;
            return 1;
        }
        return 0;
    }
};

// TBD this is the only non-forward dependency on iostream
std::ostream& BrigIO::defaultErrs() {
    return std::cerr;
}

std::unique_ptr<ReadAdapter> BrigIO::fileReadingAdapter(
                const char* fileName,
                std::ostream& errs)
{
    std::unique_ptr<FileAdapter> theFile( new FileAdapter(errs) );
    if (theFile->open(fileName, false)) {
        theFile.release();
    }
    return std::move(theFile);
}

std::unique_ptr<WriteAdapter> BrigIO::fileWritingAdapter(
                const char* fileName,
                std::ostream& errs)
{
    std::unique_ptr<FileAdapter> theFile( new FileAdapter(errs) );
    if (theFile->open(fileName, true)) {
        theFile.release();
    }
    return std::move(theFile);
}

std::unique_ptr<WriteAdapter> BrigIO::memoryWritingAdapter(
                    char         *buf,
                    size_t        size,
                    std::ostream& errs)
{
    return std::unique_ptr<WriteAdapter>(
            new MemoryAdapter(buf, size, errs) );
}

std::unique_ptr<ReadAdapter> BrigIO::memoryReadingAdapter(
                    const char   *buf,
                    size_t        size,
                    std::ostream& errs)
{
    return std::unique_ptr<ReadAdapter>(
            new MemoryAdapter((char*)buf, size, errs) );
}

std::unique_ptr<ReadAdapter> BrigIO::istreamReadingAdapter(
                    std::istream& is,
                    std::ostream& errs)
{
    return std::unique_ptr<ReadAdapter>(
            new istreamAdapter(is, errs));
}

std::unique_ptr<WriteAdapter> BrigIO::vectorWritingAdapter(
                    std::vector<char>& v,
                    std::ostream&      errs) {
    return std::unique_ptr<WriteAdapter>(
            new VectorAdapter(v, errs));
}

int BrigIO::load(BrigContainer &dst,
                 int           fmt,
                 ReadAdapter&  src)
{
    if (validate(fmt, src)) return 1;

    unsigned char ident[16];
    if (0 != src.pread((char*)ident, 16, 0)) {
        return 1;
    }
    if (memcmp("HSA BRIG", ident, 8)==0) {
        return HSAIL_ASM::readContainer(src, dst) ? 0 : 1;
    }
    switch(ident[EI_CLASS]) {
    case Elf32Policy::ELFCLASS: {
        BrigIOImpl<Elf32Policy> impl(fmt);
        return impl.readContainer(dst, &src);
        }
    case Elf64Policy::ELFCLASS: {
        BrigIOImpl<Elf64Policy> impl(fmt);
        return impl.readContainer(dst, &src);
        }
    default:
        src.errs << "Unsupported file format" << std::endl;
        return 1;
    }
}

int BrigIO::save(BrigContainer &src,
                 int           fmt,
                 WriteAdapter& dst)
{
    if (fmt == FILE_FORMAT_BRIG) {
        return src.write(dst) ? 0 : 1;
    } 
    BrigIOImpl<Elf32Policy> impl(fmt);
    return impl.writeContainer(&dst, src);
}

// --------------------------------------------------------------------------------
// BRIG FORMAT VALIDATOR

#define MODULE_SIZE_ALIGNMENT               (16)
#define MODULE_SECTION_ALIGNMENT            (16)
#define MODULE_SECTION_SIZE_ALIGNMENT        (4)
#define MODULE_INDEX_ALIGNMENT               (8)
#define MAX_PREDEFINED_SECTION_NAME_LENGTH  (16)

#define VALIDATE(cond, msg) if (!(cond)) { fd.errs << msg << std::endl; return 1; }

typedef map<uint64_t, uint64_t> ModuleMap;

int BrigIO::validate(int            fmt,
                     ReadAdapter&   fd)
{
    BrigModuleHeader moduleHdr;
    ModuleMap map;

    if (fmt != FILE_FORMAT_AUTO && fmt != FILE_FORMAT_BRIG) return 0;

    uint64_t fileSize = (uint64_t)fd.getSize();
    VALIDATE(fileSize != (uint64_t)-1, "Filed to read file size");

    VALIDATE(fileSize > sizeof(BrigModuleHeader), "File is too small for BRIG or ELF");
    VALIDATE(fd.pread((char*)&moduleHdr, sizeof(BrigModuleHeader), 0) == 0, "Failed to read BrigModuleHeader");

    if (memcmp("HSA BRIG", moduleHdr.identification, sizeof(moduleHdr.identification)) != 0) {
        if (fmt == FILE_FORMAT_AUTO) return 0;
        VALIDATE(false, "Unsupported file format");
    }

    uint64_t secIdxSize = moduleHdr.sectionCount * sizeof(uint64_t);

    VALIDATE(moduleHdr.brigMajor == BRIG_VERSION_BRIG_MAJOR,        "Unsupported major BRIG version");
    VALIDATE(moduleHdr.brigMinor <= BRIG_VERSION_BRIG_MINOR,        "Unsupported minor BRIG version");
    VALIDATE(moduleHdr.byteCount == fileSize,                       "Invalid BrigModuleHeader.size: must be equal to BRIG size");
    VALIDATE(moduleHdr.byteCount % MODULE_SIZE_ALIGNMENT == 0,      "Invalid BRIG module size: must be a multiple of " << MODULE_SIZE_ALIGNMENT);
    VALIDATE(moduleHdr.reserved == 0,                               "Invalid BrigModuleHeader.reserved: must be zero");
    VALIDATE(secIdxSize > moduleHdr.sectionCount,                   "Invalid BrigModuleHeader.sectionCount: too large value"); // overflow
    VALIDATE(moduleHdr.sectionCount >= 3,                           "Invalid BrigModuleHeader.sectionCount: must be greater than or equal to 3");
    VALIDATE(moduleHdr.sectionIndex % MODULE_INDEX_ALIGNMENT == 0,  "Invalid BrigModuleHeader.sectionIndex: must be a multiple of " << MODULE_INDEX_ALIGNMENT);
    VALIDATE(moduleHdr.sectionIndex < fileSize,                     "Invalid BrigModuleHeader.sectionIndex: position of section index is outside of BRIG module");
    VALIDATE(secIdxSize <= fileSize - moduleHdr.sectionIndex,       "Invalid BrigModuleHeader.sectionIndex: section index does not fit into BRIG module");

    map[0]                      = sizeof(BrigModuleHeader);
    map[moduleHdr.sectionIndex] = secIdxSize;

    uint64_t sectionSize;
    uint64_t sectionOffset;
    for (unsigned idx = 0; idx < moduleHdr.sectionCount; ++idx)
    {
        VALIDATE(fd.pread((char*)&sectionOffset, sizeof(uint64_t), moduleHdr.sectionIndex + idx * sizeof(uint64_t)) == 0, "Failed to read section index");
        sectionSize = validateSection(fd, idx, sectionOffset, fileSize);
        if (sectionSize == 1) return 1;
        
        VALIDATE(map.count(sectionOffset) == 0, "BRIG module elements must not overlap");
        map[sectionOffset] = sectionSize;
    }

    uint64_t actualSize = 0;

    // Each section must start immediately after the previous one
    // Gaps between sections are only allowed to satisfy the required alignment
    for (ModuleMap::iterator it = map.begin(); it != map.end(); ++it)
    {
        uint64_t nextPos;
        uint64_t pos = it->first + it->second;
        assert(pos <= fileSize);

        for (nextPos = pos; nextPos - pos < MODULE_SECTION_ALIGNMENT && nextPos < fileSize && map.count(nextPos) == 0; ++nextPos);

        VALIDATE(nextPos == fileSize || map.count(nextPos) != 0, "BRIG module elements must follow each other without gaps and overlapping");
        VALIDATE(nextPos != moduleHdr.sectionIndex || 
                 nextPos - pos < MODULE_INDEX_ALIGNMENT,         "Gaps between BRIG module elements are only allowed to satisfy alignment requirements");

        actualSize += it->second + (nextPos - pos);

        for (; pos < nextPos; ++pos)
        {
            char pad;
            VALIDATE(fd.pread(&pad, 1, pos) == 0, "Failed to read section alignment bytes");
            VALIDATE(pad == 0,                    "Padding between BRIG module elements must be filled with zero");
        }
    }

    // This is to make sure there are no nested elements
    VALIDATE(actualSize == fileSize, "BRIG module elements must not overlap");

    return 0;
}

uint64_t BrigIO::validateSection(ReadAdapter&    fd, 
                                 unsigned        sectionIndex,
                                 uint64_t        sectionOffset,
                                 uint64_t        fileSize)
{
    BrigSectionHeader sectionHeader;

    VALIDATE(sectionOffset % MODULE_SECTION_ALIGNMENT == 0,                                         "Invalid section offset: must be a multiple of " << MODULE_SECTION_ALIGNMENT);
    VALIDATE(sectionOffset < fileSize,                                                              "Invalid section offset: section offset is outside of BRIG module");
    VALIDATE(fileSize - sectionOffset > sizeof(BrigSectionHeader),                            "Invalid section offset: section header does not fit into BRIG module");
    VALIDATE(fd.pread((char*)&sectionHeader, sizeof(BrigSectionHeader), sectionOffset) == 0,  "Failed to read section header");
    VALIDATE(sectionHeader.byteCount % MODULE_SECTION_SIZE_ALIGNMENT == 0,                          "Invalid section size: must be a multiple of " << MODULE_SECTION_SIZE_ALIGNMENT);
    VALIDATE(fileSize - sectionOffset >= sectionHeader.byteCount,                                   "Invalid section size: section does not fit into BRIG module");

    VALIDATE(sectionHeader.headerByteCount % MODULE_SECTION_SIZE_ALIGNMENT == 0,                    "Invalid section header size: must be a multiple of " << MODULE_SECTION_SIZE_ALIGNMENT);
    VALIDATE(sectionHeader.headerByteCount <= sectionHeader.byteCount,                              "Invalid section header size: header size must not exceed section size");

    VALIDATE(sectionHeader.headerByteCount - sizeof(BrigSectionHeader) >= sectionHeader.nameLength - 1, "Invalid section name: name does not fit into section header");

    const char* name = 0;
    switch (sectionIndex)
    {
    case BRIG_SECTION_INDEX_DATA:     name = "hsa_data";    break;
    case BRIG_SECTION_INDEX_CODE:     name = "hsa_code";    break;
    case BRIG_SECTION_INDEX_OPERAND:  name = "hsa_operand"; break;
    }

    if (name && strlen(name) > 0)
    {
        assert(strlen(name) < MAX_PREDEFINED_SECTION_NAME_LENGTH);
        char buf[MAX_PREDEFINED_SECTION_NAME_LENGTH];
        VALIDATE(fd.pread((char*)&buf, strlen(name), sectionOffset + offsetof(BrigSectionHeader, name)) == 0, "Failed to read section name");
        VALIDATE(sectionHeader.nameLength == strlen(name) && memcmp(name, buf, strlen(name)) == 0, "Invalid name of a standard section");
    }

    //NB: validation of other section requirements are performed by HSAILValidator

    return sectionHeader.byteCount;
}

}
