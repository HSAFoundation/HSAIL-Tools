//===-- HSAILTestGen.cpp - HSAIL Test Generator Backend -------------------===//
//
//===----------------------------------------------------------------------===//
//
// HSAIL Test Generator. (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#include "HSAILTestGenBackend.h"
#include "HSAILTestGenLuaBackend.h"

#include "llvm/Support/raw_ostream.h"

#include <iosfwd>
#include <sstream>
#include <iostream>
#include <iomanip>

using std::string;
using std::ostringstream;
using std::setbase;

namespace TESTGEN {

//=============================================================================
//=============================================================================
//=============================================================================

TestGenBackend *TestGenBackend::backend = 0;

TestGenBackend* TestGenBackend::get(string name)
{
    if (!backend)
    {
        TestDataProvider::init();

        if (name.length() == 0) //  default dummy backend
        {
            backend = new TestGenBackend();
        }
        else if (name == "LUA" || name == "lua")
        {
            backend = new LuaTestGen();
        }
        else
        {
            throw TestGenError("Unknown TestGen extension: " + name);
        }
    }
    return backend;
}

void TestGenBackend::dispose()
{
    if (backend)
    {
        TestDataProvider::clean();
        delete backend;
        backend = 0;
    }
}

//=============================================================================

} // namespace TESTGEN

