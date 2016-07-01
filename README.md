HSAIL-Tools
===========

[![build status](https://gitlab.com/hsafoundation-spb/HSAIL-Tools/badges/master/build.svg)](https://gitlab.com/HSAFoundation/HSAIL-Tools/commits/master)


### OVERVIEW

HSAIL-Tools are used for parsing, assembling, and disassembling HSAIL.

The following components are provided:

 * **libHSAIL** is the main library.
 * **libHSAIL-AMD** is the library with AMD HSAIL extensions.
 * **HSAILAsm** is command-line interface to libHSAIL.

The following branches are currently used:

 * **master** branch has libHSAIL for HSA PRM 1.0 (Final) specification.
 * **hsail1.0p** branch has libHSAIL for HSAIL 1.0 Provisional specification.

### BUILD PREREQUISITES

libHSAIL requires the following components:

 * CMake
 * libelf (if `BUILD_WITH_LIBBRIGDWARF=1`)
 * libdwarf (if `BUILD_WITH_LIBBRIGDWARF=1`)
 * LLVM (only Support and Object libraries, if `BUILD_HSAILASM=1`)
 * perl
 * re2c

libHSAIL CMake build will automatically find these dependencies if installed.

libHSAIL itself can be built without debug support and does not require libdwarf
in this case.


### BUILD (general)

We recommend to use out-of-source CMake build and create separate directory to run CMake.

To build libHSAIL without libBRIGDwarf (no debug support), specify
`-DBUILD_WITH_LIBBRIGDWARF=0` option to CMake.

To avoid building HSAILAsm, specify `-DBUILD_HSAILASM=0` option to CMake.


### BUILD (Linux)

    mkdir -p build/lnx64
    cd build/lnx64
    cmake ../..
    make -j

On modern Linux distributions libHSAIL dependencies are typically provided
by the distribution. For example, the following command can be used to install
them on Ubuntu 14.04 system:

    sudo apt-get install cmake libdwarf-dev libelf-dev llvm-dev ncurses-dev re2c perl

Building on Linux requires GCC 4.4+.

On Linux, CMake normally finds all dependencies automatically. However, it is also
possible to override it (see, for example, scripts in `bin/` subdirectory).


### BUILD (Windows)

Building on Windows requires MSVC (Visual Studio 2012 Update 4 or later).

CMake command line should specify compiler configuration:

    md build/win64
    cd build/win64
    cmake -G "Visual Studio 11 2012 Win64" ...

CMake will attempt to locate corresponding compiler and generate Visual Studio
solution file which can be opened and built in Visual Studio.

For Windows, it is possible to obtain dependencies from corresponding software sources:

* LLVM can be downloaded from http://llvm.org/releases/.
* re2c source, Windows binaries and some linux packages can be donwloaded from
  http://sourceforge.net/projects/re2c/.
* Perl for Windows can be obtained from any of the following sources:
  * Activestate ActivePerl : http://www.activestate.com/activeperl
  * Strawberry Perl : http://strawberryperl.com/
  * as a part of Cygwin: http://www.cygwin.com/

On Windows, cmake command line additionally might need to include the location
of dependencies.  Refer to scripts in `bin/` subdirectory for an example how to specify them.
