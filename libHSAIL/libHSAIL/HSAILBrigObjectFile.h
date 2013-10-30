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
#ifndef INCLUDED_HSAIL_BRIG_OBJECT_FILE_H
#define INCLUDED_HSAIL_BRIG_OBJECT_FILE_H


/// This component provides its own simple hierarchy of I/O adapter classes,
/// adapter implementations for files and memory buffers, and implementation
/// of binary streaming in BRIG and BIF formats. The adapter implementations
/// are essentially independent from the rest of this component and may be 
/// factored out when necessary.

#include <iosfwd> // only forward dependencies from stdio
#include <memory> // auto_ptr

#include "HSAILBrigContainer.h"

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
    { 
    }
    virtual int write(const char* data, size_t numBytes) const = 0;

    virtual ~WriteAdapter() = 0;
};

/// read-only adapter
class ReadAdapter : public virtual IOAdapter {
public:
    ReadAdapter(std::ostream& errs_) 
        : IOAdapter(errs_) 
    {
    }

    virtual int pread(char* data, size_t numBytes, uint64_t ofs) const = 0;

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

    static std::auto_ptr<ReadAdapter> fileReadingAdapter(
                    const char*                 fileName,
                    std::ostream&               errs = defaultErrs());

    static std::auto_ptr<WriteAdapter> fileWritingAdapter(
                    const char*                 fileName,
                    std::ostream&               errs = defaultErrs());

    static std::auto_ptr<ReadAdapter> memoryReadingAdapter(
                    const char                 *buf, 
                    size_t                      size,
                    std::ostream&               errs = defaultErrs());

    static std::auto_ptr<WriteAdapter> memoryWritingAdapter(
                    char                       *buf, 
                    size_t                      size,
                    std::ostream&               errs = defaultErrs());

    // normal API using adapter references

    static int save(BrigContainer&              src,
                    int                         fmt,
                    WriteAdapter&               dst);
                                                
    static int load(BrigContainer&              dst,
                    int                         fmt,
                    ReadAdapter&                src);

    // API taking ownership of the adapters, to  be used with the factory
    // methods above                            

    static int save(BrigContainer&               src,
                    int                          fmt,
                    std::auto_ptr<WriteAdapter>  dst)
    {
        return !dst.get() || save(src, fmt, *dst);
    }

    static int load(BrigContainer&               dst,
                    int                          fmt,
                    std::auto_ptr<ReadAdapter>   src)
    {
        return !src.get() || load(dst, fmt, *src);
    }
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
};

typedef BinaryStreamer<FILE_FORMAT_BIF |FILE_FORMAT_ELF32>  Bif32Streamer;
typedef BinaryStreamer<FILE_FORMAT_BRIG|FILE_FORMAT_ELF32>  Brig32Streamer;
typedef BinaryStreamer<FILE_FORMAT_BIF |FILE_FORMAT_ELF64>  Bif64Streamer;
typedef BinaryStreamer<FILE_FORMAT_BRIG|FILE_FORMAT_ELF64>  Brig64Streamer;
typedef BinaryStreamer<FILE_FORMAT_AUTO>                    AutoBinaryStreamer;

typedef  Bif32Streamer BifStreamer;
typedef Brig32Streamer BrigStreamer;

}

#endif
