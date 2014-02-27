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
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stddef.h>

#ifdef _WIN32
#include <io.h>
#define BDG_OPEN             _open
#define BDG_CLOSE            _close
#define BDG_LSEEK            _lseek
#define BDG_UNLINK           _unlink
#define BDG_OPEN_FLAGS       _O_CREAT | _O_TRUNC | _O_BINARY | _O_RDWR
#define BDG_OPEN_PERMS       _S_IREAD | _S_IWRITE
#define BDG_READ(f, b, l)    _read((f), (b), (unsigned int)(l))
typedef long BdgLseekOff_t;
typedef int BdgReadSize_t;
#else
#include <unistd.h>
#define BDG_OPEN             open
#define BDG_CLOSE            close
#define BDG_LSEEK            lseek
#define BDG_UNLINK           unlink
#define BDG_OPEN_FLAGS       O_CREAT | O_TRUNC | O_RDWR
#define BDG_OPEN_PERMS       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define BDG_READ(f, b, l)    read((f), (b), (size_t)(l))
typedef off_t BdgLseekOff_t;
typedef size_t BdgReadSize_t;
#endif

#include <fcntl.h>
#include <sys/stat.h>

#include "BrigDwarfGenerator.h"
#include "SectionHeaderTable.h"

#include "HSAILBrigContainer.h"
#include "HSAILItems.h"
#include "HSAILBrigantine.h"

#include "libelf.h"
//#include "_libelf.h"
#include "libdwarf.h"
#include "dwarf.h"

#include "hsa_dwarf.h"    // HSA extenstions to DWARF

using std::cout;
using std::endl;


namespace BrigDebug
{

// Error is a utility class for wrapping an error message for use in 
// "throw"ing errors
//
class Error
{
public:
    Error( const std::string & errorMessage ) : m_errorMessage( errorMessage ) { }

    Error( const std::string & errorMessage, Dwarf_Error dwarfError )
        {
            std::stringstream ss;
            ss << errorMessage << ": " << dwarf_errmsg( dwarfError );
            m_errorMessage = ss.str();
        }

    std::string m_errorMessage;
};

static void error( const std::string & message )
{
    throw Error( message );
}

static void error( const std::string & message, Dwarf_Error dwarfError )
{
    throw Error( message, dwarfError );
}


/* MT-unsafe implementation of symbol table for BRIG DWARF */
class BRIGDwarfSymbolTable
{
private:
    /* pre-allocate memory for 10 items */
    static const unsigned initialSize = 10; 
    std::vector<Elf32_Sym> m_data;

    unsigned addSymbolTableEntry(const Elf32_Sym& sym)
    {
        m_data.push_back(sym);
        return m_data.size() - 1;
    }

public:

    BRIGDwarfSymbolTable()
    {
        Elf32_Sym sym0;
        /* reserve some items */
        m_data.reserve(initialSize);
        /* prepare entry #0, see 32-bit ELF spec, page 1-20 */
        ::memset(&sym0, 0, sizeof(sym0));
        sym0.st_shndx = SHN_UNDEF;
        (void)addSymbolTableEntry(sym0);
    }

    virtual ~BRIGDwarfSymbolTable() {}

    const void* rawSymbolTableData() const
    {
        return &m_data.at(0);
    }

    unsigned getNumberOfSymbols() const
    {
        return static_cast<unsigned>(m_data.size());
    }

    unsigned getSymbolTableSize() const
    {
        return static_cast<unsigned>(m_data.size()*sizeof(Elf32_Sym));
    }

    // not sure whether we want to change binding and offset fields
    unsigned addSectionSymbolEntry(unsigned index, unsigned char binding = STB_LOCAL, unsigned offset = 0)
    {
        Elf32_Sym sectionSym;
        sectionSym.st_name  = 0;
        sectionSym.st_value = offset;
        sectionSym.st_size  = 0;
        sectionSym.st_info  = ELF32_ST_INFO(binding, STT_SECTION);
        sectionSym.st_other = 0;
        sectionSym.st_shndx = index;
        return addSymbolTableEntry(sectionSym);
    }

    /* not implemented yet */
    unsigned addSymbol(const Elf32_Sym *sym)
    {
        return 0;
        //return addSymbolTableEntry(*sym);
    }
};

#if 0
class BRIGDwarfRelocationsTable
{
private:
    /* pre-allocate memory for 10 items */
    static const unsigned initialSize = 10; 
    std::vector<Elf32_Rel> m_data;

    unsigned addEntry(const Elf32_Rel& rel)
    {
        m_data.push_back(rel);
        return m_data.size() - 1;
    }

public:

    BRIGDwarfRelocationsTable(unsigned initialTableSize = BRIGDwarfRelocationsTable::initialSize)
    {
        /* reserve some items */
        m_data.reserve(initialTableSize);
    }

    virtual ~BRIGDwarfRelocationsTable() {}

    const void* rawRelocationTableData() const
    {
        return &m_data.at(0);
    }

    unsigned getNumberOfRelocations() const
    {
        return static_cast<unsigned>(m_data.size());
    }

    unsigned getRelocationsTableSize() const
    {
        return static_cast<unsigned>(m_data.size()*sizeof(Elf32_Rel));
    }

    unsigned addRelocationEntry(Elf32_Addr offset, Elf32_Word symbol, Elf32_Byte relType)
    {
        Elf32_Rel relRecord;
        relRecord.r_offset = offset;
        relRecord.r_info = ELF32_R_INFO(symbol, relType);
        return addEntry(relRecord);
    }

};
#endif

// class BrigDwarfGenerator_impl implements the BrigDwarfGenerator
// interface: 1) it generates DWARF format debug information for a specified
// BRIG container, and 2) it stores the that generated debug information into
// a given BRIG container in a manner specified in the document:
// HSA-Debug_Information-ADD.docx
//

class BrigDwarfGenerator_impl : public BrigDwarfGenerator
{
public:
    BrigDwarfGenerator_impl( const std::string & producer, 
                             const std::string & compilationDirectory,
                             const std::string & fileName );
    virtual ~BrigDwarfGenerator_impl() {}

    // create DWARF representation from the Brig container
    //
    bool generate( HSAIL_ASM::BrigContainer & c );

    // store the generated DWARF into a Brig container's .debug section
    // (write only, not read-modify-write, assumes the Brig container's 
    // .debug section has not ever been the subject of an earlier storeInBrig
    // call)
    //
    bool storeInBrig( HSAIL_ASM::BrigContainer & c ) const;

    int DwarfProducerCallback2( char * name,
                                int    size,
                                Dwarf_Unsigned type,
                                Dwarf_Unsigned flags,
                                Dwarf_Unsigned link,
                                Dwarf_Unsigned info,
                                Dwarf_Unsigned * sect_name_index );
private:
    // initialize the libdwarf library, create a Dwarf_P_Debug instance
    //
    void initializeDwarfProducer();

    // populate all of the DWARF structures (entries tree, line number table)
    // from the data available in the BRIG container
    //
    void generateDwarfForBrig( HSAIL_ASM::BrigContainer & c );
    Dwarf_P_Die generateDwarfForBrigSymbol( HSAIL_ASM::Directive d, Dwarf_P_Die parent,
                                            unsigned dwarfTag );
    void generateDwarfForBrigKernelFunction( HSAIL_ASM::Directive d );

    // helpers for generateDwarfForBrigKernelFunction
    //
    HSAIL_ASM::Offset generateDwarfForBrigParameters( Dwarf_P_Die pSuborutineEntry,
                                                  HSAIL_ASM::Directive d,
                                                  HSAIL_ASM::DirectiveVariable firstInArg,
                                                  unsigned numInParams,
                                                  HSAIL_ASM::DirectiveVariable firstOutParam,
                                                  unsigned numOutParams );
    void generateDwarfForBrigSubprogramBody( HSAIL_ASM::Offset largestParamDirectiveOffset,
                                             Dwarf_P_Die pSuborutineEntry,
                                             HSAIL_ASM::Directive firstIn,
                                             HSAIL_ASM::Directive firstAfter );

    // convert DWARF structures to disk file format in a memory-resident ELF container
    //
    void buildElfContainer();

    // buidElfContainer helper routines
    //
    void initializeElf();
    void finalizeElf();
    void createDwarfElfSections();

#if 0
    unsigned createElfSymbolTable();
    unsigned createElfStringTable( unsigned strTabNameOffset );
    void dumpDwarfRelocations();
    // set proper types of relocations in DWARF
    //
    void processRelocations();
#endif

    void readElfBytesIntoContainer();
    
    // fills m_codeSymbol and m_directivesSymbol
    //
    void createCodeAndDirectivesSections();
    
    // initializes shstrtab section and returns shstrtab section number
    //
    unsigned initializeShStrTab( unsigned strTabNameOffset);
    
    // initializes symtab section returns symtab section number
    //
    unsigned initializeSymTab(unsigned strTab);

    // binds section headers string table data to .shstrtab section
    //
    unsigned finalizeShStrTab(unsigned shStrTab);
    
    // binds symbol table data to .symtab section
    //
    unsigned finalizeSymTab(unsigned symTab);

    // release libdwarf library objects, free memory
    //
    void finalizeDwarfProducer();

    // content of all relocations sections will be stored here
    //
    //std::vector<BRIGDwarfRelocationsTable>& m_relocationsTables;

    // handle to the DWARF producer in the libdwarf library
    //
    Dwarf_P_Debug m_pDwarfDebug;

    // the root of the debug entry tree
    //
    Dwarf_P_Die m_pCompileUnit;

    // dwarf line section file index of the input source file
    //
    unsigned m_srcFileLineTableIndex;

    std::string m_producerStr;
    std::string m_compilationDirectoryStr;

    // the filename being assembled
    //
    std::string m_fileNameStr;

    // holds all the ELF section name strings
    //
    SectionHeaderTable m_sectionHeaderTable;

    // holds all the ELF symbol name strings
    //
    SectionHeaderTable m_stringTable;

    // holds all symbols in the ELF
    // 
    BRIGDwarfSymbolTable m_symbolTable;

    // the index of fake code section in symbol table
    unsigned m_codeSymbol;

    // the index of fake data (directives) section in symbol table
    unsigned m_directivesSymbol;

    // the index of symbol table section
    unsigned m_symbolTableSection;

    Elf * m_pElf;
    Elf32_Ehdr * m_pElfHeader;

    // m_elfContainer holds the ELF file image byte stream, which we will
    // embed into the Brig container in storeInBrig()
    //
    std::vector<unsigned char> m_elfContainer;

    // file descriptor to tmp elf file
    //
    int m_elfFd;

    // shows whether we have already called dwarf_lne_set_address()
    //
    bool m_isDwarfLineSetAddressCalled;
};

BrigDwarfGenerator *
BrigDwarfGenerator::Create( const std::string & producer, 
                            const std::string & compilationDirectory,
                            const std::string & fileName )
{
    return new BrigDwarfGenerator_impl( producer, compilationDirectory,
                                        fileName );
}

BrigDwarfGenerator_impl::BrigDwarfGenerator_impl( const std::string & producer, 
                                                  const std::string & compilationDirectory,
                                                  const std::string & fileName ) : 
    m_pDwarfDebug( 0 ), 
    m_pCompileUnit( 0 ),
    m_producerStr( producer ), 
    m_compilationDirectoryStr( compilationDirectory ),
    m_fileNameStr( fileName ),
    m_codeSymbol( 0xC0DE ), /* something deliberately wrong */
    m_directivesSymbol( 0xDA7A ),
    m_symbolTableSection( 0x7AB1 ),
    m_pElf( 0 ), m_pElfHeader( 0 ), m_elfFd( -1 ),
    m_isDwarfLineSetAddressCalled(false)
{
}


bool BrigDwarfGenerator_impl::generate( HSAIL_ASM::BrigContainer & c )
{
    try
    {
        initializeDwarfProducer();
        initializeElf();
        generateDwarfForBrig( c );
        assert( m_pDwarfDebug );
        createDwarfElfSections();
        finalizeElf();
        readElfBytesIntoContainer();
        finalizeDwarfProducer();
    }
    catch ( const Error & e )
    {
        std::cerr << "BrigDwarfGenerator_impl: error: " << e.m_errorMessage << std::endl;
        return false;
    }
        
    return true;
}

// this callback is called from libdwarf when it wants to create an
// elf section, which occurs during dwarf_transform_to_disk_form()
//
// The return value is an integer associated with the ELF section, and 
// is used to identify the section returned to us when we later call 
// dwarf_get_section_bytes().   It can be any unique integer we map internally
// to an ELF section, but we just use the actual ELF section number directly
// 
// *sec_name_index is an OUT parameter, a pointer to the shared string table
// (.shrstrtab) offset for thte name of the section
//
static int DwarfProducerCallbackFunc( char * name,
                                      int    size,
                                      Dwarf_Unsigned type,
                                      Dwarf_Unsigned flags,
                                      Dwarf_Unsigned link,
                                      Dwarf_Unsigned info,
                                      Dwarf_Unsigned * sect_name_index,
                                      void * user_data,
                                      int  * error )
{
    BrigDwarfGenerator_impl * pBdig = (BrigDwarfGenerator_impl *) user_data;
    int rv = pBdig->DwarfProducerCallback2( name, size, type, flags, link,
                                            info, sect_name_index );
    return rv;
}

int 
BrigDwarfGenerator_impl::DwarfProducerCallback2( char * name,
                                                 int    size,
                                                 Dwarf_Unsigned type,
                                                 Dwarf_Unsigned flags,
                                                 Dwarf_Unsigned link,
                                                 Dwarf_Unsigned info,
                                                 Dwarf_Unsigned * sect_name_index )
{
    Elf_Scn * scn = elf_newscn( m_pElf );
    if ( ! scn )
    {
        std::stringstream ss;
        ss << "Error in elf_newscn(), name=" << name;
        error( ss.str() );
    }

    Elf32_Shdr * shdr = elf32_getshdr( scn );
    if ( ! shdr )
    {
        std::stringstream ss;
        ss << "Error in elf_getshdr(), name=" << name;
        error( ss.str() );
    }

    shdr->sh_name   = m_sectionHeaderTable.addHeaderName( name );
    shdr->sh_type   = type;
    shdr->sh_flags  = flags;
    shdr->sh_addr   = 0;
    shdr->sh_offset = 0;
    shdr->sh_size   = size;
    /* WORKAROUND:
     when libdwarf creates relocatable section, it does not know anything about corresponding symtab, and passes zero instead */
    shdr->sh_link   = (type == SHT_REL || type == SHT_RELA) ? m_symbolTableSection : link; 
    shdr->sh_info   = info;
    shdr->sh_addralign = 4;
    shdr->sh_entsize = 0;

    unsigned  sectionIndex = elf_ndxscn( scn );

    *sect_name_index = m_symbolTable.addSectionSymbolEntry(sectionIndex);

#if 0
    cout << "Section " << name 
         << " shstrab index = " << shdr->sh_name
         << " section header index = "   << sectionIndex 
         << " symtab index = " << *sect_name_index 
         << endl;
#endif

    return sectionIndex;
}


static void DwarfErrorHandler( Dwarf_Error theError, Dwarf_Ptr errarg)
{
    std::stringstream ss;
    ss << "dwarf error: " << dwarf_errmsg( theError );
    error( ss.str() );
}


void BrigDwarfGenerator_impl::initializeDwarfProducer()
{
    int pointerSize = DW_DLC_SIZE_32;
    Dwarf_Ptr errarg = 0;
    Dwarf_Error pErr  = 0;
    Dwarf_Error * nullError = 0;

    // DW_DLC_SYMBOLIC_RELOCATIONS means we do our own relocating.
    // We use DW_DLC_STREAM_RELOCATIONS, which means libdwarf generates all
    // relocations, but we tweak them to meet our needs (changing relocation type)
    //
    //unsigned initFlags = DW_DLC_WRITE | pointerSize | DW_DLC_SYMBOLIC_RELOCATIONS;
    unsigned initFlags = DW_DLC_WRITE | pointerSize | DW_DLC_STREAM_RELOCATIONS;
    Dwarf_Handler errorHandlerFunc = 0;
    void * userData = this;

    m_pDwarfDebug = dwarf_producer_init_c( initFlags,
                                           DwarfProducerCallbackFunc,
                                           DwarfErrorHandler, 
                                           0 /* errarg */, userData, &pErr );

    // only on the init call do we need to check the return value, for all
    // other calls we pass in a "nullError" so that the DwarfErrorHandler
    // is called
    //

    if ( pErr != 0 )
        error( "dwarf_producer_init_c", pErr );

    Dwarf_P_Die pParent = 0;
    Dwarf_P_Die pChild = 0;
    Dwarf_P_Die pLeftSibling = 0;
    Dwarf_P_Die pRightSibling = 0;

    // create the compile unit entry, which is the root of the tree of entriess
    //
    m_pCompileUnit = dwarf_new_die( m_pDwarfDebug, DW_TAG_compile_unit,
                                    pParent, pChild, pLeftSibling,
                                    pRightSibling, nullError );
    // set compile unit attributes
    //
    dwarf_add_AT_producer( m_pCompileUnit, (char *) m_producerStr.c_str(),
                           nullError );
    dwarf_add_AT_comp_dir( m_pCompileUnit,
                           (char *) m_compilationDirectoryStr.c_str(),
                           nullError );
    dwarf_add_AT_unsigned_const( m_pDwarfDebug, m_pCompileUnit, DW_AT_language,
                                 DW_LANG_HSA_Assembly, nullError );

    // declare to libdwarf that m_pCompileUnit is the root of the entries tree
    //
    dwarf_add_die_to_debug( m_pDwarfDebug, m_pCompileUnit, nullError );

    // add the assembly source filename to the line table 
    //
    unsigned defaultDirectoryIndex = 0;
    unsigned nullTimeModified = 0;
    unsigned nullFileLength = 0;
    m_srcFileLineTableIndex = dwarf_add_file_decl( m_pDwarfDebug,
                                                   (char *)m_fileNameStr.c_str(), 
                                                   defaultDirectoryIndex,
                                                   nullTimeModified,
                                                   nullFileLength, nullError );
}



void BrigDwarfGenerator_impl::generateDwarfForBrig( HSAIL_ASM::BrigContainer & c )
{
    assert( m_pDwarfDebug );
        
    HSAIL_ASM::Directive nextD;
    for ( HSAIL_ASM::Directive d = c.directives().begin(); d != c.directives().end(); d = nextD )
    {
        // cout << "offset 0x" << std::hex << d.brigOffset() << ": ";

        switch ( d.brig()->kind ) 
        {
         case Brig::BRIG_DIRECTIVE_VARIABLE:
         {
             // add this symbol's entry as a child of the compile unit
             // of type "variable"
             //
             generateDwarfForBrigSymbol( d, m_pCompileUnit, DW_TAG_variable );
             nextD = d.next();
             break;
         }

         case Brig::BRIG_DIRECTIVE_FUNCTION:
         {
             generateDwarfForBrigKernelFunction( d );
             HSAIL_ASM::DirectiveFunction dFunc( d );
             nextD = dFunc.nextTopLevelDirective();
             break;
         }

         case Brig::BRIG_DIRECTIVE_KERNEL:
         {
             generateDwarfForBrigKernelFunction( d );
             HSAIL_ASM::DirectiveKernel dKernel( d );
             nextD = dKernel.nextTopLevelDirective();
             break;
         }

         default:
            //cout << endl;
            nextD = d.next();
            break;
        }

        //if ( d.brig()->kind == Brig::BRIG_DIRECTIVE_VARIABLE_INIT )
        //    cout << "DirectiveVariableInit (dump skipped)" << endl;
        //else
        //    d.dump( cout );
    }
}


// given a top level BrigDirectiveSymbol, create a DWARRF entry for it and add it to
// the entries tree as the most recent child of the root
//
Dwarf_P_Die 
BrigDwarfGenerator_impl::generateDwarfForBrigSymbol( HSAIL_ASM::Directive d,
                                                     Dwarf_P_Die parent,
                                                     unsigned dwarfTag)
{
    HSAIL_ASM::DirectiveVariable dSym( d );
    Brig::BrigDirectiveVariable * pBds( dSym.brig() );
    Dwarf_Error * nullError( 0 );
    Dwarf_P_Die nullSibling( 0 );

    Dwarf_P_Die pVariableEntry = dwarf_new_die( m_pDwarfDebug, dwarfTag, parent, 
                                                nullSibling, nullSibling, nullSibling,
                                                nullError );
    // name attribute
    //
    std::string strCopy(HSAIL_ASM::SRef(dSym.name()));
    const char * name = strCopy.c_str();
    dwarf_add_AT_name( pVariableEntry, (char *) name, nullError );

    // location attribute.   The location of a brig symbol is the offset of 
    // the BRIGDirectiveSymbol directive from the start of the .directives section
    //
    Dwarf_P_Expr locationExpr = dwarf_new_expr( m_pDwarfDebug, nullError );

    dwarf_add_expr_addr( locationExpr, dSym.brigOffset(), m_directivesSymbol,
                         nullError );

    dwarf_add_AT_location_expr( m_pDwarfDebug, pVariableEntry, DW_AT_location,
                                locationExpr, nullError );

    // declared file, line, column numbers
    //
    const HSAIL_ASM::SourceInfo *pSrcInfo( dSym.container()->sourceInfo( dSym ) );

    // TBD handle .loc changing the current src file
    //
    dwarf_add_AT_unsigned_const( m_pDwarfDebug, pVariableEntry, DW_AT_decl_file,
                                 m_srcFileLineTableIndex, nullError );
    dwarf_add_AT_unsigned_const( m_pDwarfDebug, pVariableEntry, DW_AT_decl_line,
                                 pSrcInfo->line + 1, nullError );
    dwarf_add_AT_unsigned_const( m_pDwarfDebug, pVariableEntry, DW_AT_decl_column,
                                 pSrcInfo->column + 1, nullError );

    return pVariableEntry;
}

// Create a DW_TAG_subprogram entry for the function/kernel
// Include all formal parameters (both in and out)
// Include a lexical scope.  All non-arg variables defined belong to
//    the lexical scope.  Any arg variables defined belong to the enclosing 
//    arg scope.
// Output a warning for arg variables defined outside of an 
// argument scope.
//
void BrigDwarfGenerator_impl::generateDwarfForBrigKernelFunction( HSAIL_ASM::Directive d )
{
    Dwarf_P_Die nullSibling( 0 );
    Dwarf_Error * nullError( 0 );

    // gather attribute values common to functions and kernels
    //
    std::string subrName;
    unsigned startPC = 0, endPC = 0;
    HSAIL_ASM::Inst firstInstr;
        
    unsigned instrCount = 0;
    bool isKernel = true;
    unsigned declLine = 1;
    unsigned declColumn = 0;
    HSAIL_ASM::DirectiveVariable firstInArg;
    unsigned numInParams = 0;
    HSAIL_ASM::DirectiveVariable firstOutParam;
    unsigned numOutParams = 0;
    HSAIL_ASM::Directive firstDirectiveInSubprogram;
    HSAIL_ASM::Directive firstDirectiveAfterSubprogram;

    if ( d.brig()->kind == Brig::BRIG_DIRECTIVE_KERNEL )
    {
        // kernel definition
        //
        HSAIL_ASM::DirectiveKernel dKernel( d );

        subrName = HSAIL_ASM::SRef(dKernel.name());
        firstInstr = dKernel.code();
        instrCount = dKernel.instCount();
        const HSAIL_ASM::SourceInfo *pSrcInfo( dKernel.container()->sourceInfo( dKernel ) );
        declLine = pSrcInfo->line + 1;
        declColumn = pSrcInfo->column + 1;
        firstInArg = dKernel.firstInArg();
        numInParams = dKernel.inArgCount();
        firstDirectiveInSubprogram = dKernel.next();
        firstDirectiveAfterSubprogram = dKernel.nextTopLevelDirective();
    }
    else
    {
        // function definition
        //
        HSAIL_ASM::DirectiveFunction dFunction( d );

        subrName = HSAIL_ASM::SRef(dFunction.name());
        firstInstr = dFunction.code();
        instrCount = dFunction.instCount();
        isKernel = false;
        const HSAIL_ASM::SourceInfo *pSrcInfo( dFunction.container()->sourceInfo( dFunction ) );
        declLine = pSrcInfo->line + 1;
        declColumn = pSrcInfo->column + 1;
        firstInArg = dFunction.firstInArg();
        numInParams = dFunction.inArgCount();
        firstOutParam = dFunction.next();
        numOutParams = dFunction.outArgCount();
        firstDirectiveInSubprogram = dFunction.next();
        firstDirectiveAfterSubprogram = dFunction.nextTopLevelDirective();
    }

    // functions/kernels with no operations are forward declarations, we ignore these
    //
    if ( instrCount == 0 )
        return;

    startPC = firstInstr.brigOffset();
        
    // find the endPC value by first finding the last instruction
    // then calculate the offset of the following instruction
    // generate the line # mappings at the same time
    //
    HSAIL_ASM::Inst instr( firstInstr );
    HSAIL_ASM::Inst lastInstr;
    for ( unsigned i = 0; i < instrCount; ++i, instr = instr.next() )
    {
        lastInstr = instr;
        const HSAIL_ASM::SourceInfo *pSrcInfo( instr.container()->sourceInfo( instr ) );
        if (!pSrcInfo) continue;
        if ( !m_isDwarfLineSetAddressCalled )
        {
            Dwarf_Unsigned rv = dwarf_lne_set_address( m_pDwarfDebug, 
                                                       instr.brigOffset(), 
                                                       m_codeSymbol, 
                                                       nullError );
            // TBD: do we need this assert?
            //
            assert(rv == 0);
            m_isDwarfLineSetAddressCalled = true;
        }
        dwarf_add_line_entry( m_pDwarfDebug, 
                              m_srcFileLineTableIndex,
                              instr.brigOffset(),                // address
                              pSrcInfo->line + 1, pSrcInfo->column + 1,
                              true,                              // is src statement
                              false,                             // is basic block begin
                              nullError );
    }
    endPC = lastInstr.brigOffset() + lastInstr.brigSize();
    dwarf_lne_end_sequence( m_pDwarfDebug, endPC, nullError );

    Dwarf_P_Die pSubprogramEntry = dwarf_new_die( m_pDwarfDebug, 
                                                  DW_TAG_subprogram, m_pCompileUnit,
                                                  nullSibling, nullSibling, 
                                                  nullSibling, nullError );
    // name attribute
    //
    dwarf_add_AT_name( pSubprogramEntry, (char *) subrName.c_str(), nullError );

    // We may only need a single symbol for all code relocations since we don't
    // care about where the address is, we only care that it is a BRIG code address
    //

    // low and high PC
    //
    dwarf_add_AT_targ_address( m_pDwarfDebug, pSubprogramEntry, DW_AT_low_pc, 
                               startPC, m_codeSymbol, nullError );
    dwarf_add_AT_targ_address( m_pDwarfDebug, pSubprogramEntry, DW_AT_high_pc, 
                               endPC, m_codeSymbol, nullError );

    // declaration file, line, column
    // 
    dwarf_add_AT_unsigned_const( m_pDwarfDebug, pSubprogramEntry, DW_AT_decl_file,
                                 m_srcFileLineTableIndex, nullError );
    dwarf_add_AT_unsigned_const( m_pDwarfDebug, pSubprogramEntry, DW_AT_decl_line,
                                 declLine, nullError );
    dwarf_add_AT_unsigned_const( m_pDwarfDebug, pSubprogramEntry, DW_AT_decl_column,
                                 declColumn, nullError );

    // is kernel? attribute
    //
    if ( isKernel )
    {
        dwarf_add_AT_flag( m_pDwarfDebug, pSubprogramEntry, DW_AT_HSA_is_kernel, 1,
                           nullError );
    }

    // create subprogram parameter entries
    // (also, find the brig parameter directive with the largest offset.  This marks
    // the end of the parameter directives)
    //
    HSAIL_ASM::Offset largestParameterDirectiveOffset =
        generateDwarfForBrigParameters( pSubprogramEntry, d, firstInArg,
                                        numInParams, firstOutParam, numOutParams );

    // if there are no directives in the subprogram body we're done
    //
    if ( firstDirectiveInSubprogram == firstDirectiveAfterSubprogram )
        return;

    // there are directives -- search for symbol and argument/scope directives.
    // create entries for non-argument variables scoped in subprogram, and for
    // argument scopes with argument variables
    //

    generateDwarfForBrigSubprogramBody( largestParameterDirectiveOffset,
                                        pSubprogramEntry,
                                        firstDirectiveInSubprogram,
                                        firstDirectiveAfterSubprogram );
}


// given a DWARF subroutine entry, its BRIG directive, and the 
// first in and out parameter directives (and counts), generate the 
// formal parameter DWARF entries for the subprogram's formal parameters
//
HSAIL_ASM::Offset BrigDwarfGenerator_impl::generateDwarfForBrigParameters( 
    Dwarf_P_Die pSuborutineEntry,
    HSAIL_ASM::Directive d,
    HSAIL_ASM::DirectiveVariable firstInArg,
    unsigned numInParams,
    HSAIL_ASM::DirectiveVariable firstOutParam,
    unsigned numOutParams )
{
    Dwarf_Error * nullError( 0 );
    HSAIL_ASM::DirectiveVariable inParam( firstInArg );
    HSAIL_ASM::DirectiveVariable outParam( firstOutParam );
    HSAIL_ASM::Offset largestOffset = 0;

    // generate entries for outut parameters
    //
    for ( unsigned op = 0; op < numOutParams; ++op, outParam = outParam.next() )
    {
        Dwarf_P_Die pParamEntry = generateDwarfForBrigSymbol( outParam, pSuborutineEntry,
                                                              DW_TAG_formal_parameter );
        dwarf_add_AT_flag( m_pDwarfDebug, pParamEntry, DW_AT_HSA_is_outParam, 1,
                           nullError );
        if ( outParam.brigOffset() > largestOffset )
            largestOffset = outParam.brigOffset();
    }

    // generate entries for input parameters
    //
    for ( unsigned ip = 0; ip < numInParams; ++ip, inParam = inParam.next() )
    {
        generateDwarfForBrigSymbol( inParam, pSuborutineEntry, DW_TAG_formal_parameter );
        if ( inParam.brigOffset() > largestOffset )
            largestOffset = inParam.brigOffset();
    }

    return largestOffset;
}



void BrigDwarfGenerator_impl::generateDwarfForBrigSubprogramBody( 
    HSAIL_ASM::Offset largestParameterDirectiveOffset,
    Dwarf_P_Die pSuborutineEntry,
    HSAIL_ASM::Directive firstDirectiveInSubprogram,
    HSAIL_ASM::Directive firstDirectiveAfterSubprogram )
{
    HSAIL_ASM::Directive d( firstDirectiveInSubprogram );
    bool inArgScope = false;
    Dwarf_P_Die pArgScopeEntry( 0 );

    // find the first directive inside the subprogram following  the 
    // parameter declarations
    //
    while ( ( d.brigOffset() <= largestParameterDirectiveOffset ) &&
            ( d != firstDirectiveAfterSubprogram ) )
    {
        d = d.next();
    }

    while ( d != firstDirectiveAfterSubprogram )
    {
        switch ( d.brig()->kind )
        {
         case Brig::BRIG_DIRECTIVE_VARIABLE:
         {
             HSAIL_ASM::DirectiveVariable dSym( d );
             if ( inArgScope && ( dSym.segment() == Brig::BRIG_SEGMENT_ARG ) )
             {
                 // argument variable, parent entry is arg scope
                 //
                 if ( pArgScopeEntry == 0 )
                 {
                     pArgScopeEntry = dwarf_new_die( m_pDwarfDebug, 
                                                     DW_TAG_HSA_argument_scope,
                                                     pSuborutineEntry, 0, 0, 0, 0 );
                 }
                 generateDwarfForBrigSymbol( dSym, pArgScopeEntry, DW_TAG_variable );
             }
             else
             {
                 // non-argument variable, parent entry is subprogram
                 //
                 generateDwarfForBrigSymbol( dSym, pSuborutineEntry, 
                                             DW_TAG_variable );
             }
             break;
         }

         case Brig::BRIG_DIRECTIVE_ARG_SCOPE_START:
            inArgScope = true;
            break;

         case Brig::BRIG_DIRECTIVE_ARG_SCOPE_END:
            // We have reached the end of the current argument scope -- "forget" the 
            // current argscope entry (if there is one).
            // This is not a leak of pArgScopeEntry, dwarf tracks all allocations
            // and frees them in dwarf_producer_finish.  We must "forget" the 
            // current scope entry so that we'll create a new arg scope entry
            // for the next one we encounter
            //
            pArgScopeEntry = 0;
            inArgScope = false;
            break;

         default:
            // don't care about other directives
            //
            break;

        }
        d = d.next();
    }
}



bool BrigDwarfGenerator_impl::storeInBrig( HSAIL_ASM::BrigContainer & c ) const
{
    HSAIL_ASM::Brigantine b(c);
    b.storeDWARF(m_elfContainer);
    return true;
}

#if 0
void BrigDwarfGenerator_impl::dumpDwarfRelocations()
{
    Dwarf_Error err = 0;
    Dwarf_Unsigned reloc_sections_count = 0;
    int drd_version = 0;
    int res = dwarf_get_relocation_info_count(m_pDwarfDebug, &reloc_sections_count,
        &drd_version,&err);
    if( res != DW_DLV_OK) {
        cout << "Error getting relocation info count." << endl;
        return;

    }
    cout << "Relocations sections count= " << reloc_sections_count << 
        " relversion=" << drd_version << endl;

    for( Dwarf_Unsigned ct = 0; ct < reloc_sections_count ; ++ct) {
        // elf_section_index is the elf index of the relocations
        // themselves. 
        Dwarf_Signed elf_section_index = 0;
        // elf_section_index_link is the elf index of the section
        // the relocations apply to.
        Dwarf_Signed elf_section_index_link = 0;
        // relocation_buffer_count is the number of relocations
        // of this section.
        Dwarf_Unsigned relocation_buffer_count = 0;
        Dwarf_Relocation_Data reld;
        res = dwarf_get_relocation_info(m_pDwarfDebug, &elf_section_index,
            &elf_section_index_link,
            &relocation_buffer_count,
            &reld,&err);
        if (res != DW_DLV_OK) {
            cout << "Error getting relocation record " <<
                ct << "."  << endl;
            return;
        }
        cout << "Relocs for sec " << ct << " elf-sec=" << elf_section_index <<
            " link="      << elf_section_index_link <<
            " bufct="     << relocation_buffer_count << endl;

        for (Dwarf_Unsigned r = 0; r < relocation_buffer_count; ++r) {
            Dwarf_Relocation_Data rec = reld+r;
            cout << "\tRelocation record " << r << ":" << endl;
            cout << "\t\ttype:   " << (unsigned)rec->drd_type << endl;
            cout << "\t\tlength: " << (unsigned)rec->drd_length << endl;
            cout << "\t\toffset: " << (unsigned)rec->drd_offset << endl;
            cout << "\t\tsymidx: " << (unsigned)rec->drd_symbol_index << endl;
        }
    }
    return;
}
#endif

void BrigDwarfGenerator_impl::createCodeAndDirectivesSections()
{
    Dwarf_Unsigned bds, bcs;
    DwarfProducerCallback2((char*)".brigdirectives", 0, SHT_NOBITS, 0, 0, 0, &bds);
    DwarfProducerCallback2((char*)".brigcode", 0, SHT_NOBITS, 0, 0, 0, &bcs);
    m_codeSymbol = bcs;
    m_directivesSymbol = bds;
}

#if 0
unsigned BrigDwarfGenerator_impl::createElfSymbolTable( )
{
    Elf_Scn * strscn = elf_newscn( m_pElf );
    if ( ! strscn )
        error( "Error in elf_newscn in createElfSymbolTable" );

    Elf_Data * shstr = elf_newdata( strscn );
    if ( ! shstr )
        error( "Error in elf_newdata in createElfSymbolTable" );

    shstr->d_buf = const_cast<void *>(m_symbolTable.rawSymbolTableData()); /* WRONG */
    shstr->d_type =  ELF_T_SYM;
    shstr->d_size = m_symbolTable.getSymbolTableSize();
    shstr->d_off = 0;
    shstr->d_align = sizeof(Elf32_Sym);
    shstr->d_version = EV_CURRENT;

    Elf32_Shdr * strshdr = elf32_getshdr( strscn );
    if ( ! strshdr )
        error( "error in elf32_getshdr in createElfSymbolTable()" );

    strshdr->sh_name = m_sectionHeaderTable.addHeaderName( ".symtab" ); 
    strshdr->sh_type= SHT_SYMTAB;
    strshdr->sh_flags = 0;
    strshdr->sh_addr = 0;
    strshdr->sh_offset = 0;
    strshdr->sh_size = 0;
    strshdr->sh_link  = (Elf32_Word)(0xDEADBEEF); /* caller must provide exact value */
    strshdr->sh_info = m_symbolTable.getNumberOfSymbols();
    strshdr->sh_addralign = 4;
    strshdr->sh_entsize = 0;
    return  elf_ndxscn(strscn);
}
#endif

void BrigDwarfGenerator_impl::buildElfContainer()
{
    assert( m_pDwarfDebug );

    initializeElf();
    createDwarfElfSections();
    //dumpDwarfRelocations();
    finalizeElf();
    readElfBytesIntoContainer();
}

unsigned BrigDwarfGenerator_impl::initializeShStrTab( unsigned strTabNameOffset)
{
    Elf_Scn * strscn = elf_newscn( m_pElf );
    if ( ! strscn )
        error( "Error in elf_newscn in initializeShStrTab" );

    Elf32_Shdr * strshdr = elf32_getshdr( strscn );
    if ( ! strshdr )
        error( "error in elf32_getshdr in initializeShStrTab()" );

    strshdr->sh_name = strTabNameOffset; 
    strshdr->sh_type= SHT_STRTAB;
    strshdr->sh_flags = SHF_STRINGS;
    strshdr->sh_addr = 0;
    strshdr->sh_offset = 0;
    strshdr->sh_size = 0;
    strshdr->sh_link  = 0;
    strshdr->sh_info = 0;
    strshdr->sh_addralign = 1;
    strshdr->sh_entsize = 0;
    return  elf_ndxscn(strscn);

}
    
unsigned BrigDwarfGenerator_impl::initializeSymTab(unsigned strTab)
{
    Elf_Scn * strscn = elf_newscn( m_pElf );
    if ( ! strscn )
        error( "Error in elf_newscn in initializeSymTab()" );

    Elf32_Shdr * symtabshdr = elf32_getshdr( strscn );
    if ( ! symtabshdr )
        error( "error in elf32_getshdr in initializeSymTab()" );

    symtabshdr->sh_name = m_sectionHeaderTable.addHeaderName( ".symtab" ); 
    symtabshdr->sh_type= SHT_SYMTAB;
    symtabshdr->sh_flags = 0;
    symtabshdr->sh_addr = 0;
    symtabshdr->sh_offset = 0;
    symtabshdr->sh_size = 0;
    symtabshdr->sh_link  = (Elf32_Word)strTab; // link to strtab
    symtabshdr->sh_info = 0xDEADBEEF ; //finalizer will set exact value
    symtabshdr->sh_addralign = 4;
    symtabshdr->sh_entsize = 0;
    return  elf_ndxscn(strscn);
}

unsigned BrigDwarfGenerator_impl::finalizeShStrTab(unsigned shStrTab)
{
    Elf_Scn * strscn = elf_getscn( m_pElf, shStrTab );
    if ( ! strscn )
        error( "Error in elf_getscn in finalizeShStrTab" );

    Elf_Data * shstr = elf_newdata( strscn );
    if ( ! shstr )
        error( "Error in elf_newdata in finalizeShStrTab" );

    shstr->d_buf = (void *)const_cast<char *>(m_sectionHeaderTable.rawHeaderData());
    shstr->d_type =  ELF_T_BYTE;
    shstr->d_size = m_sectionHeaderTable.rawHeaderSize();
    shstr->d_off = 0;
    shstr->d_align = 1;
    shstr->d_version = EV_CURRENT;

    return 0;
}
    
unsigned BrigDwarfGenerator_impl::finalizeSymTab(unsigned symTab)
{
    Elf_Scn * strscn = elf_getscn( m_pElf, symTab );
    if ( ! strscn )
        error( "Error in elf_getscn in finalizeSymTab" );

    Elf_Data * shstr = elf_newdata( strscn );
    if ( ! shstr )
        error( "Error in elf_newdata in finalizeSymTab" );

    shstr->d_buf = const_cast<void *>(m_symbolTable.rawSymbolTableData()); /* TODO refactor const_cast */
    shstr->d_type =  ELF_T_SYM;
    shstr->d_size = m_symbolTable.getSymbolTableSize();
    shstr->d_off = 0;
    shstr->d_align = sizeof(Elf32_Sym);
    shstr->d_version = EV_CURRENT;

    Elf32_Shdr * strshdr = elf32_getshdr( strscn );
    if ( ! strshdr )
        error( "error in elf32_getshdr in finalizeSymTab()" );

    strshdr->sh_info = m_symbolTable.getNumberOfSymbols();
    return  0;
}

void BrigDwarfGenerator_impl::initializeElf()
{
	std::string outFileName( m_fileNameStr + ".dbg" );
	m_elfFd = BDG_OPEN( outFileName.c_str(), BDG_OPEN_FLAGS, BDG_OPEN_PERMS );

    if ( m_elfFd < 0 ) 
	{
		std::stringstream ss;
		ss << "Unable to open " << outFileName << " for writing";
        error( ss.str() );
	}

    if ( elf_version(EV_CURRENT) == EV_NONE ) 
        error( "Bad elf_version" );

//    m_pElf = elf_begin( m_elfFd, ELF_C_WRITE, 0, 0 );
    m_pElf = elf_begin( m_elfFd, ELF_C_WRITE, 0 );
    if ( ! m_pElf )
        error( "elf_begin() failed" );
    
    m_pElfHeader = elf32_newehdr( m_pElf );

    if ( ! m_pElfHeader )
        error( "Unable to elf_newehdr()" );

    m_pElfHeader->e_ident[EI_MAG0] = ELFMAG0; 
    m_pElfHeader->e_ident[EI_MAG1] = ELFMAG1; 
    m_pElfHeader->e_ident[EI_MAG2] = ELFMAG2; 
    m_pElfHeader->e_ident[EI_MAG3] = ELFMAG3; 
    m_pElfHeader->e_ident[EI_CLASS] = ELFCLASS32; 
    m_pElfHeader->e_ident[EI_DATA] = ELFDATA2LSB;
    m_pElfHeader->e_ident[EI_VERSION] = EV_CURRENT;

    m_pElfHeader->e_machine = EM_HSAIL; /* TODO: add HSAIL target support to both libelf and libdwarf */
    m_pElfHeader->e_type = ET_REL;      /* BRIG DWARF is a relocatable data */
    m_pElfHeader->e_version = EV_CURRENT;

    /* initialize shstrtab, obtain its number, store it in the ELF header */
    unsigned strTabNameOffset = m_sectionHeaderTable.addHeaderName(".shstrtab");
    unsigned shStrTabSectionNumber = initializeShStrTab( strTabNameOffset );
    m_pElfHeader->e_shstrndx = shStrTabSectionNumber;

    /* initialize symtab, link with shstrtab, remember its number to use in BrigDwarfCallback2 */
    m_symbolTableSection = initializeSymTab( shStrTabSectionNumber );
    /* create fake sections */
    createCodeAndDirectivesSections();
}

#if 0
void BrigDwarfGenerator_impl::processRelocations()
{
    Dwarf_Error err = 0;

    // Since we are emitting in final form sometimes, we may
    // do relocation processing here or we may
    // instead emit relocation records into the object file.
    // The following is for DW_DLC_SYMBOLIC_RELOCATIONS.
    Dwarf_Unsigned reloc_sections_count = 0;
    int drd_version = 0;
    int res = dwarf_get_relocation_info_count(m_pDwarfDebug, &reloc_sections_count,
        &drd_version,&err);
    if( res != DW_DLV_OK) {
        error( "Error getting relocation info count in processRelocations()" );
    }
    cout << "Relocations sections count= " << reloc_sections_count << 
        " relversion=" << drd_version << endl;

    // pre-allocate memory for vectors of relocation sections 
    m_relocationsTables.resize(reloc_sections_count);

    for( Dwarf_Unsigned ct = 0; ct < reloc_sections_count ; ++ct) {
        // elf_section_index is the elf index of the relocations
        // themselves. 
        Dwarf_Signed elf_section_index = 0;
        // elf_section_index_link is the elf index of the section
        // the relocations apply to.
        Dwarf_Signed elf_section_index_link = 0;
        // relocation_buffer_count is the number of relocations
        // of this section.
        Dwarf_Unsigned relocation_buffer_count = 0;
        Dwarf_Relocation_Data reld;
        res = dwarf_get_relocation_info(m_pDwarfDebug,&elf_section_index,
            &elf_section_index_link,
            &relocation_buffer_count,
            &reld,&err);
        if (res != DW_DLV_OK) {
            error( "Error getting relocation record in processRelocations()" );
        }
        cout << "Relocs for sec " << ct << " elf-sec=" << elf_section_index <<
            " link="      << elf_section_index_link <<
            " bufct="     << relocation_buffer_count << endl;
        Elf_Scn *scn =  elf_getscn(m_pElf, elf_section_index_link);
        if(!scn) {
            error( "Error in elf_getscn in processRelocations()" );
        }

        /* construct relocations table manually */
        BRIGDwarfRelocationsTable& bdrt = m_relocationsTables.at(ct);

        for (Dwarf_Unsigned r = 0; r < relocation_buffer_count; ++r) {
            Dwarf_Relocation_Data rec = &reld[r];
            if( rec->drd_type != dwarf_drt_data_reloc ) {
                error( "unexpected relocation type met in processRelocations()" );
            }
            if( rec->drd_length != 4 ) {
                error( "unexpected relocation record length met in processRelocations()" );
            }
            cout << "\tRR " << r 
                 << ": length = " << (unsigned)rec->drd_length
                 << ", offset = " << rec->drd_offset
                 << ", symidx = " << rec->drd_symbol_index 
                 << ", type = " << (unsigned)rec->drd_type << endl;
            bdrt.addRelocationEntry(rec->drd_offset, rec->drd_symbol_index, __R_HSA_DWARF_TO_BRIG32);
        }

        /* bind it to the corresponding elf section */
        // TODO complete this function if necessary, otherwise remove it completely
    }
}
#endif

void BrigDwarfGenerator_impl::createDwarfElfSections()
{
    Dwarf_Error * nullError = 0;
    Dwarf_Signed sectioncount = dwarf_transform_to_disk_form( m_pDwarfDebug, 0 );

    // cout << "created " << sectioncount << " sections" << endl;
    //    processRelocations();

    for ( int i = 0; i < sectioncount; ++i )
    {
        Dwarf_Signed elf_section_index = 0;
        Dwarf_Unsigned length = 0;
        Dwarf_Ptr bytes = dwarf_get_section_bytes( m_pDwarfDebug, i,  
                                                   &elf_section_index, &length,
                                                   nullError);

        Elf_Scn *scn =  elf_getscn( m_pElf, elf_section_index );
        Elf_Data* ed = elf_newdata(scn);
        if ( ! ed ) 
            error( "elf_newdata failed in createDwarfElfSections" );

        ed->d_buf = bytes;
        ed->d_size = length;
        ed->d_type =  ELF_T_BYTE;
        ed->d_off = 0;
        // Align debug sections to sizeof(Elf32_Sym). d_align is log2 of the
        // alignment. log2(sizeof(Elf32_Sym)) == 2
        ed->d_align = 2;
        ed->d_version = EV_CURRENT;

        // process relocations, if any
        Elf32_Shdr *sh = elf32_getshdr(scn);
        if (!sh)
        {
            error( "elf32_getshdr failed in createDwarfElfSections" );
        }
        if (sh->sh_type == SHT_REL)
        {
            unsigned char* relBytes = (unsigned char*)ed->d_buf;
            for(unsigned rrOffset = 0; rrOffset < length; rrOffset += sizeof(Elf32_Rel) )
            {
                Elf32_Rel *rr = static_cast<Elf32_Rel *>((void*)(relBytes + rrOffset));
                unsigned relSym  = ELF32_R_SYM(rr->r_info);
                unsigned relType = ELF32_R_TYPE(rr->r_info);
#if 0
                cout << "offset = " << rr->r_offset << ", sym = " << relSym << ", type = " << relType << endl;
#endif
                if(relSym == m_codeSymbol)
                {
                    rr->r_info = ELF32_R_INFO(relSym, __R_HSA_DWARF_TO_BRIG_CODE32);
                }
                else if(relSym == m_directivesSymbol)
                {
                    rr->r_info = ELF32_R_INFO(relSym, __R_HSA_DWARF_TO_BRIG_DIRECTIVES32);
                }
                else
                {
                    rr->r_info = ELF32_R_INFO(relSym, __R_HSA_DWARF_32);
                }
                
            }
        }
    }
}



void BrigDwarfGenerator_impl::finalizeElf()
{
    /* finalize symbol table */
    finalizeSymTab(m_symbolTableSection);

    /* finalize shstrtab */
    finalizeShStrTab(m_pElfHeader->e_shstrndx);

    off_t ures = elf_update( m_pElf, ELF_C_WRITE );
    if ( ures == (off_t)(-1LL) )
    {
        std::stringstream ss;
        ss << "error in elf_update(): " << elf_errno() << ": " << elf_errmsg( elf_errno() );
        error( ss.str() );
    }

    elf_end( m_pElf );

	// note!   We can not close the m_elfFd file until we read back
	// in the ELF disk image
	//
	
}


#if 0
unsigned BrigDwarfGenerator_impl::createElfStringTable( unsigned strTabNameOffset )
{
    Elf_Scn * strscn = elf_newscn( m_pElf );
    if ( ! strscn )
        error( "Error in elf_newscn in createElfStringTable" );

    Elf_Data * shstr = elf_newdata( strscn );
    if ( ! shstr )
        error( "Error in elf_newdata in createElfStringTable" );

    shstr->d_buf = (void *) m_sectionHeaderTable.rawHeaderData();
    shstr->d_type =  ELF_T_BYTE;
    shstr->d_size = m_sectionHeaderTable.rawHeaderSize();
    shstr->d_off = 0;
    shstr->d_align = 1;
    shstr->d_version = EV_CURRENT;

    Elf32_Shdr * strshdr = elf32_getshdr( strscn );
    if ( ! strshdr )
        error( "error in elf32_getshdr in createElfStringTable()" );

    strshdr->sh_name = strTabNameOffset; 
    strshdr->sh_type= SHT_STRTAB;
    strshdr->sh_flags = SHF_STRINGS;
    strshdr->sh_addr = 0;
    strshdr->sh_offset = 0;
    strshdr->sh_size = 0;
    strshdr->sh_link  = 0;
    strshdr->sh_info = 0;
    strshdr->sh_addralign = 1;
    strshdr->sh_entsize = 0;
    return  elf_ndxscn(strscn);
}
#endif


void BrigDwarfGenerator_impl::readElfBytesIntoContainer()
{
	BdgLseekOff_t fileSize = BDG_LSEEK( m_elfFd, 0, SEEK_END );
	if ( fileSize == (BdgLseekOff_t) -1 )
		error( "could not seek to end of debug output file" );

	if ( BDG_LSEEK( m_elfFd, 0, SEEK_SET ) == (BdgLseekOff_t) -1 )
		error( "could not seek to beginning of debug output file" );

	m_elfContainer.resize( fileSize );

	BdgLseekOff_t bytesRemaining = fileSize;
	BdgReadSize_t totalBytesRead = 0;
	while ( bytesRemaining > 0 )
	{
		BdgReadSize_t bytesRead = BDG_READ( m_elfFd, &m_elfContainer[ totalBytesRead ], bytesRemaining );
		if ( bytesRead == (BdgReadSize_t) -1 )
			error( "error reading from debug info file" );

		totalBytesRead += bytesRead;
		bytesRemaining -= bytesRead;
	}

	// now we can close the debug info elf file
	//
	BDG_CLOSE( m_elfFd );

	std::string outFileName( m_fileNameStr + ".dbg" );
	BDG_UNLINK( outFileName.c_str() );
}


void BrigDwarfGenerator_impl::finalizeDwarfProducer()
{
    assert( m_pDwarfDebug );
    Dwarf_Error * nullError = 0;

    dwarf_producer_finish( m_pDwarfDebug,  nullError );
}

} // end namespace BrigDebug

