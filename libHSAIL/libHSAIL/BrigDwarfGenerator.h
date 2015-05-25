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
#ifndef __BRIG_DWARF_GENERATOR_H__
#define __BRIG_DWARF_GENERATOR_H__

#include <string>
#include <ostream>

namespace HSAIL_ASM
{
	class BrigContainer;
}


namespace BrigDebug
{

// BrigDwarfGenerator generates debugging information from an existing
// BRIG container, and can store that generated information into a BRIG
// container
//

class BrigDwarfGenerator
{
public:
	virtual ~BrigDwarfGenerator() {}

	static BrigDwarfGenerator * Create( const std::string & producer,
                                      const std::string & compilationDirectory,
                                      const std::string & fileName,
                                      bool includeSource = false, const std::string& producerOptions = "");

        virtual void log(std::ostream* out) = 0;

	// generate debug info for a BRIG container
	//
	virtual bool generate( /*const*/ HSAIL_ASM::BrigContainer & c ) = 0;

	// store the generated debug info into a BRIG container
	//
	virtual bool storeInBrig( HSAIL_ASM::BrigContainer & c ) const = 0;

protected:
	explicit BrigDwarfGenerator() {}

};

} // end namespace BrigDebug

#endif // __BRIG_DWARF_GENERATOR_H__
