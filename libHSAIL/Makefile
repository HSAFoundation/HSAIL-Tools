#
# see README for information on building libHSAIL
#

all: libhsail hsailasm

ifeq ($(OS),Windows_NT)
_WINDOWS = 1
else
_GCC = 1
endif

LIBS := $(_LIBS)
LIBPATHS :=
ARFLAGS =

ifdef _WINDOWS
# windows (msvc or mingw)
MKDIR = cmd.exe /c "(md $(subst /,\,$(@D)) || echo whatever) >NUL 2>NUL"
CLEAN_BUILD_DIR=cmd.exe /c del /s /q $(subst /,\,$(BUILD_DIR))
EXE_SUFFIX := .exe
ifdef _GCC # & _WINDOWS
# windows, mingw
CONFIG := mingw
LIBS += dbghelp psapi
else # !_GCC & _WINDOWS
# windows, msvc
CONFIG := msvc
endif
else # !_WINDOWS
# linux
MKDIR = mkdir -p $(@D)
CLEAN_BUILD_DIR = rm -rf $(BUILD_DIR)
WITH_LIBBRIGDWARF=1
override CXXFLAGS += -fPIC -fno-rtti
LIBS +=  dl pthread
LLVMEXTRALIBS := tinfo
CONFIG := linux
EXE_SUFFIX :=
endif

ifdef _M64
ifdef _M32
$(error conflict between _M64 and _M32)
endif
endif

ifndef _GCC

# MSVC only

OBJ_SUFFIX = .obj
LIB_SUFFIX = .lib
LIB_PREFIX =

override CXXFLAGS += -nologo -c -EHsc

override CXXFLAGS += -D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE

ifdef _OPT
override CXXFLAGS += -DNDEBUG -O2
LLVM_SUBDIR = Release
CONFIG := $(CONFIG)_opt
else
LLVM_SUBDIR = Debug
endif

ifdef _STATIC
VCRT := -MT
else
VCRT := -MD
endif

ifdef _DBG
CONFIG := $(CONFIG)_dbg
override CXXFLAGS += -Z7 -Od -D_DEBUG $(VCRT)d
else
override CXXFLAGS += $(VCRT)
endif

ifdef _M64
VSFLAVOR := x64
else
VSFLAVOR := x86
endif

# MSVC auto-configuration via vshelper.bat

SHELL:=cmd.exe
.SHELLFLAGS:=/c
VSHELPER_OUT:=$(shell vshelper.bat $(VSFLAVOR))
include vsvars.inc

ifeq (,$(findstring Optimizing Compiler,$(VSHELPER_OUT)))
$(error MSVC version mismatch - $(VSHELPER_OUT))
endif

ifneq (,$(findstring for x86,$(VSHELPER_OUT))$(findstring for 80x86,$(VSHELPER_OUT)))
ifdef _M64
$(error MSVC version mismatch - $(VSHELPER_OUT))
else
_M32:=1
VSFLAVOR := x86
endif
endif

ifneq (,$(findstring for x64,$(VSHELPER_OUT)))
ifdef _M32
$(error MSVC version mismatch - $(VSHELPER_OUT))
else
_M64:=1
VSFLAVOR := x64
endif
endif

# end of MSVC auto-configuration

CONFIG := $(CONFIG)_$(VSFLAVOR)

LLVM_LIBDIR ?= $(LLVM_BUILD)/lib/$(LLVM_SUBDIR)

LIBS += shell32 advapi32

CXX = cl.exe
override CXXFLAGS += /Fo$@
AR = lib.exe
ARFLAGS += /nologo /out:"$@"
LD = link.exe

override LDFLAGS += /nologo /out:"$@" /debug /ignore:4098

override LDFLAGS += $(LIBPATHS:%=/LIBPATH:%)
LDFLAGS_LIBS = $(LIBS:%=%.lib)

else # _GCC
# this applies to both linux and mingw

OBJ_SUFFIX = .o
LIB_SUFFIX = .a
LIB_PREFIX = lib

override CXXFLAGS += -std=c++11

ifdef _OPT
override CXXFLAGS += -O3 -DNDEBUG
CONFIG := $(CONFIG)_opt
endif

ifdef _DBG
override CXXFLAGS += -g -D_DEBUG
CONFIG := $(CONFIG)_dbg
else
override LDFLAGS += -s
endif

ifdef _M64
override CXXFLAGS += -m64
override LDFLAGS += -m64
CONFIG := $(CONFIG)_m64
endif

ifdef _M32
override CXXFLAGS += -m32
override LDFLAGS += -m32
CONFIG := $(CONFIG)_m32
endif

LLVM_LIBDIR = $(LLVM_BUILD)/lib

#CXXFLAGS +=  -Wall -Wno-reorder -Wno-unused -Wno-deprecated -Werror -pipe  -fmerge-all-constants -fno-tree-vectorize -fno-strict-aliasing
override CXXFLAGS +=  -Wno-reorder -Wno-unused -Wno-deprecated -fno-strict-aliasing

CXX ?= g++
override CXXFLAGS += -fno-rtti -c -o $@
AR ?= ar
ARFLAGS += rv $@
LD = $(CXX)
override LDFLAGS += -o $@ $(LIBPATHS:%=-L%)
LDFLAGS_LIBS = $(LIBS:%=-l%)

endif # _GCC

BUILD_DIR ?= build_$(CONFIG)

INCLUDES = -I$(LIBHSAIL_DIR)/generated -I$(LIBHSAIL_DIR) $(LLVM_INCFLAGS) -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS

ifdef LLVM_CONFIG
LLVM_INCFLAGS = -I$(shell $(LLVM_CONFIG) --includedir)
LLVM_LIBDIR = $(shell $(LLVM_CONFIG) --libdir)
endif

ifdef BUILD_OWN_LLVM_LIBS

# this will not invoke cmake so it still needs LLVM_BUILD pointing to a pre-configured build dir

LLVM_LIB = $(BUILD_DIR)/$(LIB_PREFIX)llvm$(LIB_SUFFIX)
LLVM_DIR = $(LLVM_SRC)/lib/Support $(LLVM_SRC)/lib/Object
LLVM_SRCS = $(wildcard $(LLVM_DIR:%=%/*.cpp))
LLVM_OBJS = $(LLVM_SRCS:$(LLVM_SRC)/lib/%.cpp=$(BUILD_DIR)/o_%$(OBJ_SUFFIX))
LIBS := llvm $(LIBS)
VPATH = $(LLVM_SRC)/lib

$(LLVM_OBJS) : | $(BUILD_DIR)/o_Support/.dummy $(BUILD_DIR)/o_Object/.dummy

$(LLVM_LIB): $(LLVM_OBJS)
	$(AR) $(ARFLAGS) $^

else

# pre-built llvm

$(info LLVM_LIBDIR=$(LLVM_LIBDIR))
LLVM_LIB = $(LLVM_LIBDIR)/$(LIB_PREFIX)LLVMSupport$(LIB_SUFFIX) $(LLVM_LIBDIR)/$(LIB_PREFIX)LLVMObject$(LIB_SUFFIX)
LIBPATHS += $(LLVM_LIBDIR)
LIBS := LLVMSupport LLVMObject $(LLVMEXTRALIBS) $(LIBS)
endif

LLVM_INCFLAGS ?= -I$(LLVM_SRC)/include -I$(LLVM_BUILD)/include

LIBS := hsail $(LIBS)
LIBPATHS += $(BUILD_DIR)

llvm: $(LLVM_LIB)

###########################

LIBHSAIL_DIR  = libHSAIL
LIBHSAIL_LIB  = $(BUILD_DIR)/$(LIB_PREFIX)hsail$(LIB_SUFFIX)
LIBHSAIL_SRCS = $(wildcard $(LIBHSAIL_DIR)/*.cpp)
LIBHSAIL_OBJS = $(LIBHSAIL_SRCS:%.cpp=$(BUILD_DIR)/o_%$(OBJ_SUFFIX))

ifdef _GCC
-include $(LIBHSAIL_SRCS:%.cpp=$(BUILD_DIR)/o_%.d)
endif

$(LIBHSAIL_OBJS) : | $(BUILD_DIR)/o_$(LIBHSAIL_DIR)/.dummy

$(LIBHSAIL_LIB): $(LIBHSAIL_OBJS)
	$(AR) $(ARFLAGS) $^

libhsail: $(LIBHSAIL_LIB)
###########################

ifdef WITH_LIBBRIGDWARF

# check if elf.h, dwarf.h, libdwarf.h is present
ifdef _WINDOWS
# WINDOWS
else # linux
ifneq (0,$(shell echo "\#include<elf.h>" | $(CXX) $(CXXFLAGS) $(INCLUDES) -xc++ -c -o /dev/null - ; echo $$?;))
$(error elf.h is missing ..)
endif

ifneq (0,$(shell echo "\#include<dwarf.h>" | $(CXX) $(CXXFLAGS) $(INCLUDES) -xc++ -c -o /dev/null -; echo $$?;))
$(error dwarf.h is missing ..)
endif

ifneq (0,$(shell echo "\#include<libdwarf.h>" | $(CXX) $(CXXFLAGS) $(INCLUDES) -xc++ -c -o /dev/null -; echo $$?;))
$(error libdwarf.h is missing ..)
endif
endif

override CXXFLAGS += -DWITH_LIBBRIGDWARF
LIBS := brigdwarf dwarf elf $(LIBS)
INCLUDES += -I$(LIBBRIGDWARF_DIR)

LIBBRIGDWARF_DIR  = libBRIGdwarf
LIBBRIGDWARF_LIB  = $(BUILD_DIR)/$(LIB_PREFIX)brigdwarf$(LIB_SUFFIX)
LIBBRIGDWARF_SRCS = $(wildcard $(LIBBRIGDWARF_DIR)/*.cpp)
LIBBRIGDWARF_OBJS = $(LIBBRIGDWARF_SRCS:%.cpp=$(BUILD_DIR)/o_%$(OBJ_SUFFIX))

ifdef _GCC
-include $(LIBBRIGDWARF_SRCS:%.cpp=$(BUILD_DIR)/o_%.d)
endif

$(LIBBRIGDWARF_OBJS) : | $(BUILD_DIR)/o_$(LIBBRIGDWARF_DIR)/.dummy

$(LIBBRIGDWARF_LIB): $(LIBBRIGDWARF_OBJS)
	$(AR) $(ARFLAGS) $^

libbrigdwarf: $(LIBBRIGDWARF_LIB)
.PHONY: libbrigdwarf
else
LIBBRIGDWARF_LIB =
endif

###########################

HSAILASM_DIR  = HSAILAsm
HSAILASM_EXE  = $(BUILD_DIR)/hsailasm$(EXE_SUFFIX)
HSAILASM_SRCS = $(wildcard $(HSAILASM_DIR)/*.cpp)
HSAILASM_OBJS = $(HSAILASM_SRCS:%.cpp=$(BUILD_DIR)/o_%$(OBJ_SUFFIX))

ifdef _GCC
-include $(HSAILASM_SRCS:%.cpp=$(BUILD_DIR)/o_%.d)
endif

$(HSAILASM_OBJS) : | $(BUILD_DIR)/o_$(HSAILASM_DIR)/.dummy

$(HSAILASM_EXE): $(HSAILASM_OBJS) $(LLVM_LIB) $(LIBHSAIL_LIB) $(LIBBRIGDWARF_LIB)
	$(LD) $(LDFLAGS) $(HSAILASM_OBJS) $(LDFLAGS_LIBS)

hsailasm: $(HSAILASM_EXE)
#############################################
# universal rule for dependencies
$(BUILD_DIR)/o_$(LIBHSAIL_DIR)/%.d: $(LIBHSAIL_DIR)/%.cpp | $(BUILD_DIR)/o_$(LIBHSAIL_DIR)/.dummy
	@set -e; rm -f $@; \
	$(CXX) -MM $(INCLUDES) $(CXXFLAGS) $< > $@.$$$$; \
	sed -e 's,\([a-Az-Z0-9]*\)\.o[ :]*,\$$\(BUILD_DIR\)/o_\$$\(LIBHSAIL_DIR\)/\1.o \$$\(BUILD_DIR\)/o_\$$\(LIBHSAIL_DIR\)/\1.d : ,g' \
	    -e 's,$(LLVM_SRC)/include,\$$\(LLVM_SRC\)/include, g' \
	    -e 's,$(LLVM_BUILD)/include,\$$\(LLVM_BUILD\)/include, g' \
	    < $@.$$$$ > $@; \
	rm -f $@.$$$$;

$(BUILD_DIR)/o_$(LIBBRIGDWARF_DIR)/%.d: $(LIBBRIGDWARF_DIR)/%.cpp | $(BUILD_DIR)/o_$(LIBBRIGDWARF_DIR)/.dummy
	@set -e; rm -f $@; \
	$(CXX) -MM $(INCLUDES) $(CXXFLAGS) $< > $@.$$$$; \
	sed -e 's,\([a-Az-Z0-9]*\)\.o[ :]*,\$$\(BUILD_DIR\)/o_\$$\(LIBBRIGDWARF_DIR\)/\1.o \$$\(BUILD_DIR\)/o_\$$\(LIBBRIGDWARF_DIR\)/\1.d :,g' \
	    -e 's,$(LLVM_SRC)/include,\$$\(LLVM_SRC\)/include, g' \
	    -e 's,$(LLVM_BUILD)/include,\$$\(LLVM_BUILD\)/include, g' \
	    < $@.$$$$ > $@; \
	rm -f $@.$$$$;

$(BUILD_DIR)/o_$(HSAILASM_DIR)/%.d: $(HSAILASM_DIR)/%.cpp | $(BUILD_DIR)/o_$(HSAILASM_DIR)/.dummy
	@set -e; rm -f $@; \
	$(CXX) -MM $(INCLUDES) $(CXXFLAGS) $< > $@.$$$$; \
	sed -e 's,\([a-Az-Z0-9]*\)\.o[ :]*,\$$\(BUILD_DIR\)/o_\$$\(HSAILASM_DIR\)/\1.o \$$\(BUILD_DIR\)/o_\$$\(HSAILASM_DIR\)/\1.d : ,g' \
	    -e 's,$(LLVM_SRC)/include,\$$\(LLVM_SRC\)/include, g' \
	    -e 's,$(LLVM_BUILD)/include,\$$\(LLVM_BUILD\)/include, g' \
	    < $@.$$$$ > $@; \
	rm -f $@.$$$$;
#############################################
# universal rule for object files
$(BUILD_DIR)/o_%$(OBJ_SUFFIX): %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $<

# universal rule for object file dirs
$(BUILD_DIR)/%/.dummy :
	@$(MKDIR)
	@echo . >$@

clean:
	@$(CLEAN_BUILD_DIR)

.PHONY: clean all hsailasm libhsail llvm

.SUFFIXES:
