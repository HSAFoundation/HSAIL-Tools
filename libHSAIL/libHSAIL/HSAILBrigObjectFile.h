// University of Illinois/NCSA
// Open Source License
//
// Copyright (c) 2013-2015, Advanced Micro Devices, Inc.
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
#ifndef INCLUDED_HSAIL_BRIG_OBJECT_FILE_H
#define INCLUDED_HSAIL_BRIG_OBJECT_FILE_H


/// This component provides its own simple hierarchy of I/O adapter classes,
/// adapter implementations for files and memory buffers, and implementation
/// of binary streaming in BRIG and BIF formats. The adapter implementations
/// are essentially independent from the rest of this component and may be
/// factored out when necessary.

#include <iosfwd>
#include <memory> // unique_ptr
#include <map>

#include "HSAILBrigContainer.h"

using std::map;

namespace HSAIL_ASM {

enum BinaryFileFormat {
    FILE_FORMAT_AUTO = 0,
    FILE_FORMAT_BRIG = 1,
    FILE_FORMAT_BIF  = 2,
    FILE_FORMAT_MASK = 0xf,
    FILE_FORMAT_ELF32 = 0,
    FILE_FORMAT_ELF64 = 0x10
};

/// virtual base for the adapters
class IOAdapter {
public:
    std::ostream& errs;
    ///

    typedef uint64_t Position;

    virtual Position getPos() const = 0;
    virtual void setPos(Position) = 0;

    IOAdapter(std::ostream& errs_)
        : errs(errs_)
    {
    }

    virtual ~IOAdapter() = 0;
};

/// write-only adapter
class WriteAdapter : public virtual IOAdapter {
public:
    WriteAdapter(std::ostream& errs_)
        : IOAdapter(errs_)
    {}
    virtual ~WriteAdapter() = 0;
    virtual int write(const char* data, size_t numBytes) const = 0;

    int writeAlignPad(unsigned pow2);

    template <typename C>
    int write(const C& c,
               const typename std::enable_if<std::is_pod<C>::value>::type* x=nullptr) {
        return write((const char*)&c, sizeof c);
    }

    template <typename T, unsigned N>
    int write(const T (&a)[N], unsigned numElems = 0) {
        return write((const char*)a, sizeof a[0] * numElems? numElems : N);
    }
};

class NullWriteAdapter : public WriteAdapter {
    mutable Position pos;
public:
    NullWriteAdapter(std::ostream& errs_)
        : IOAdapter(errs_)
        , WriteAdapter(errs_)
        , pos(0)
    {}
    virtual Position getPos() const { return pos; }
    virtual void setPos(Position p) { pos = p; }
    virtual int write(const char* data, size_t numBytes) const {
        pos += (Position)numBytes;
        return 0;
    }
};

/// read-only adapter
class ReadAdapter : public virtual IOAdapter {
public:
    ReadAdapter(std::ostream& errs_)
        : IOAdapter(errs_)
    {
    }

    virtual int pread(char* data, size_t numBytes, uint64_t ofs) const = 0;
    virtual Position getSize() const { return (Position)-1; };

    virtual ~ReadAdapter() = 0;
};

/// read-write adapter you may (but do not have to) inherit from
class ReadWriteAdapter : public ReadAdapter, public WriteAdapter {
public:
    ReadWriteAdapter(std::ostream& errs_)
        : IOAdapter(errs_), ReadAdapter(errs_), WriteAdapter(errs_)
    {
    }

    virtual ~ReadWriteAdapter() = 0;
};

struct BrigIO {

    static std::ostream& defaultErrs();

    // factory methods for the adapters

    static std::unique_ptr<ReadAdapter> fileReadingAdapter(
                    const char*                 fileName,
                    std::ostream&               errs = defaultErrs());

    static std::unique_ptr<WriteAdapter> fileWritingAdapter(
                    const char*                 fileName,
                    std::ostream&               errs = defaultErrs());

    static std::unique_ptr<ReadAdapter> memoryReadingAdapter(
                    const char                 *buf,
                    size_t                      size,
                    std::ostream&               errs = defaultErrs());

    static std::unique_ptr<WriteAdapter> memoryWritingAdapter(
                    char                       *buf,
                    size_t                      size,
                    std::ostream&               errs = defaultErrs());

    static std::unique_ptr<ReadAdapter>  istreamReadingAdapter(
                    std::istream&               is,
                    std::ostream&               errs = defaultErrs());


    static std::unique_ptr<WriteAdapter> vectorWritingAdapter(
                    std::vector<char>& v,
                    std::ostream&               errs = defaultErrs());


    static std::unique_ptr<ReadAdapter> fragmentReadingAdapter(
                    ReadAdapter *r,
                    IOAdapter::Position size,
                    IOAdapter::Position offset = 0);

    // normal API using adapter references

    static int save(BrigContainer&              src,
                    int                         fmt,
                    WriteAdapter&               dst);

    static int load(BrigContainer&              dst,
                    int                         fmt,
                    ReadAdapter&                src,
                    bool                        writable = false);

    // API taking ownership of the adapters, to  be used with the factory
    // methods above

    static int save(BrigContainer&               src,
                    int                          fmt,
                    std::unique_ptr<WriteAdapter>  dst)
    {
        return !dst.get() || save(src, fmt, *dst);
    }

    static int load(BrigContainer&               dst,
                    int                          fmt,
                    std::unique_ptr<ReadAdapter> src,
                    bool                         writable = false)
    {
        return !src.get() || load(dst, fmt, *src, writable);
    }

    static int validateBrigBlob(ReadAdapter&         src);
};

// old style compatibility API

template<int FORMAT> class BinaryStreamer {
public: // Elf emitting

    static int save(BrigContainer &c, WriteAdapter &s) {
        return BrigIO::save(c, FORMAT, s);
    }

    static int save(BrigContainer &c, char* buf, size_t size) {
        return BrigIO::save(c, FORMAT, BrigIO::memoryWritingAdapter(buf, size));
    }

    static int save(BrigContainer &c, const char* fileName) {
        return BrigIO::save(c, FORMAT, BrigIO::fileWritingAdapter(fileName));
    }

public: // Elf reading

    static int load(BrigContainer &c, const char *buf, size_t size) {
        return BrigIO::load(c, FORMAT, BrigIO::memoryReadingAdapter(buf, size));
    }

    static int load(BrigContainer &c, ReadAdapter &s) {
        return BrigIO::load(c, FORMAT, s);
    }

    static int load(BrigContainer &c, const char *fileName) {
        return BrigIO::load(c, FORMAT, BrigIO::fileReadingAdapter(fileName));
    }

    static int load(BrigContainer &c, std::istream& is) {
        return BrigIO::load(c, FORMAT, BrigIO::istreamReadingAdapter(is));
    }
};

typedef BinaryStreamer<FILE_FORMAT_BIF |FILE_FORMAT_ELF32>  Bif32Streamer;
typedef BinaryStreamer<FILE_FORMAT_BRIG|FILE_FORMAT_ELF32>  Brig32Streamer;
typedef BinaryStreamer<FILE_FORMAT_BIF |FILE_FORMAT_ELF64>  Bif64Streamer;
typedef BinaryStreamer<FILE_FORMAT_BRIG|FILE_FORMAT_ELF64>  Brig64Streamer;
typedef BinaryStreamer<FILE_FORMAT_BRIG>                    BrigStreamer;
typedef BinaryStreamer<FILE_FORMAT_AUTO>                    AutoBinaryStreamer;

typedef Bif32Streamer BifStreamer;
typedef Brig32Streamer BrigStreamer;

class BrigBlobValidator
{
private:
    typedef map<uint64_t, uint64_t> ModuleMap;
    mutable string error;
    enum
    {
        MODULE_SIZE_ALIGNMENT               = 16,
        MODULE_SECTION_ALIGNMENT            = 16,
        MODULE_SECTION_SIZE_ALIGNMENT       =  4,
        MODULE_INDEX_ALIGNMENT              =  8,
        MAX_PREDEFINED_SECTION_NAME_LENGTH  = 16,
    };

public:
    bool validate() const;
    string getErrorMsg() const { return error; }

private:
    void validateBrig() const;

    uint64_t validateSection(BrigSectionIndex sectionIndex,
                             uint64_t sectionOffset,
                             uint64_t fileSize) const;

    void validate(bool cond, const char* msg) const;
    void validate(bool cond, const char* msg, unsigned val) const;

protected:
    virtual uint64_t size() const = 0;
    virtual bool read(char* dst, uint64_t numBytes, uint64_t offset) const = 0;
};

} // namespace

#endif
