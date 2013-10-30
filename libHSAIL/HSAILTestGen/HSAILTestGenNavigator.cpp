//===-- HSAILTestGenFilter.cpp - HSAIL Test Generator Navigator -----------===//
//
//===----------------------------------------------------------------------===//
//
// HSAIL Test Generator Navigator. (C) 2012 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/PathV2.h"

#include "HSAILItems.h"
#include "HSAILValidatorBase.h"
#include "HSAILTestGenOptions.h"
#include "HSAILTestGenNavigator.h"
#include "HSAILUtilities.h"
#include "HSAILItems.h"
#include "Brig.h"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <fstream>
#include <iomanip> 

using std::string;
using std::vector;
using std::ostringstream;
using std::ofstream;

using HSAIL_ASM::Inst;
using HSAIL_ASM::InstBasic;
using HSAIL_ASM::InstAtomic;
using HSAIL_ASM::InstAtomicImage;
using HSAIL_ASM::InstBar;
using HSAIL_ASM::InstLane;
using HSAIL_ASM::InstCmp;
using HSAIL_ASM::InstCvt;
using HSAIL_ASM::InstAddr;
using HSAIL_ASM::InstImage;
using HSAIL_ASM::InstMem;
using HSAIL_ASM::InstMod;
using HSAIL_ASM::InstBr;
using HSAIL_ASM::InstSourceType;
using HSAIL_ASM::InstSeg;

using HSAIL_ASM::OperandReg;
using HSAIL_ASM::OperandImmed;

using HSAIL_ASM::PropValidator;

using HSAIL_ASM::opcode2str;

// ============================================================================
// ============================================================================

namespace TESTGEN {

//=============================================================================
//=============================================================================
//=============================================================================

static const char* HSAIL_TESTLIST = "testlist.txt";

enum Category
{
    C_ART = 0, // Arithmetic
    C_MOV,
    C_MEM_ATM,
    C_MEM_NAT,
    C_IMG_ATM,
    C_IMG_NAT,
    C_SYNC,
    C_MSC,
    C_BR,
    C_GCN_ART,
    C_GCN_MEM_ATM,
    C_GCN_MEM_NAT,
    C_GCN_MSK,

    C_MAXID
};

static const char* categoryName[] =
{
    "arith",
    "arith",
    "mem/atomic",
    "mem/nonatomic",
    "image/atomic",
    "image/nonatomic",
    "sync",
    "special",
    "branch",
    "gcn/arith",
    "gcn/mem/atomic",
    "gcn/mem/nonatomic",
    "gcn/special"
};

static const char* operandName[] =
{
    "operand0",
    "operand1",
    "operand2",
    "operand3",
    "operand4",
};

struct CategoryDesc 
{
    unsigned categoryId;
    unsigned instOpcode;

    bool operator<(const CategoryDesc& c) const { return this->instOpcode < c.instOpcode; }
};

//F this list should be generated automatically from HDL
#include "HSAILTestGenCategories.h"

//=============================================================================
// Test Filtering
//=============================================================================
//
// Currently, each element of a filter may have one of the floowing formats:
//
//  -------------------------------------------------------------------------------------
//   Format          Meaning                                            Encoded as
//  -------------------------------------------------------------------------------------
//   "prop=value"    this string must present in test description       "prop=value"
//   "prop!=value"   "prop=value" must not present in test description  " prop=value"
//   "value"         equivalent to "opcode=value"                       "opcode=value"
//  -------------------------------------------------------------------------------------
//

#define OPCODE_PREF ("opcode=")

static string normalize(string s) 
{ 
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    
    if (s.find_first_of("=!") == string::npos) s = OPCODE_PREF + s;
    
    // Handling of negative conditions
    std::string::size_type pos = s.find("!=");
    if (pos != string::npos) {
        s = s.erase(pos, 1);    // erase '!'
        s = " " + s;
    }

    return s;
}

static bool eqChIgnoreCase(char c1, char c2) { return std::tolower(c1) == std::tolower(c2); }

static bool eqStrIgnoreCase(string s1, string s2) 
{ 
    return s1.length() == s2.length() && std::equal(s1.begin(), s1.end(), s2.begin(), eqChIgnoreCase); 
}

static bool isOpcodeProp(string s)
{
    const std::string::size_type len = strlen(OPCODE_PREF);
    return s.length() > len && eqStrIgnoreCase(s.substr(0, len), OPCODE_PREF);
}

//==========================================================================

class FilterComparator
{
private:
    unsigned index;
    const vector<string> &filter;

public:
    FilterComparator(const vector<string> &f) : index(0), filter(f) {}

    bool isEmpty()     const { return index == filter.size(); }
    bool isPositive()  const { return filter[index].length() == 0 || filter[index][0] != ' '; }
    string getFilter() const { return isPositive()? filter[index] : filter[index].substr(1); }
    void next()              { ++index; }

    bool operator()(const string& val) const { return eqStrIgnoreCase(val, getFilter()); }
};

//==========================================================================

class TestGenFilter
{
private:
    std::vector<std::string> filter;
    std::string opcode;

public:
    TestGenFilter()
    {
        std::transform(testFilter.begin(), testFilter.end(), back_inserter(filter), normalize);
        std::vector<std::string>::iterator result = find_if(filter.begin(), filter.end(), isOpcodeProp);
        if (result != filter.end()) opcode = *result;
    }

public:
    bool isTestEnabled(const std::vector<std::string> &testProps)
    {
        for (FilterComparator c(filter); !c.isEmpty(); c.next()) 
        {
            bool found = (find_if(testProps.begin(), testProps.end(), c) != testProps.end());
            if (found != c.isPositive()) return false; // ok == (found for positive) || (not found for negative)
        }
        return true;
    }
    bool isOpcodeEnabled(const std::string s) const { return opcode.empty() || eqStrIgnoreCase(s, opcode); }
};

//=============================================================================
//=============================================================================
//=============================================================================

#define DEFAULT_PROP_VAL_NAME    ("default")
#define NONDEFAULT_PROP_VAL_NAME ("nondefault")

class TestGenNavigatorImpl
{
private:
    string rootPath;
    string fullPath;
    string relPath;
    string testCategories;
    CategoryDesc* instCategoryTab;
    vector<string> testProps;
    TestGenFilter filter;
    const char* lastOpcode;
    ofstream osfs;

    //==========================================================================
public:
    TestGenNavigatorImpl(string path) : rootPath(path), instCategoryTab(0), lastOpcode(0) {}
    ~TestGenNavigatorImpl() { closeStream(); delete[] instCategoryTab; }

    //==========================================================================
public:
    bool isOpcodeEnabled(unsigned opcode)
    { 
        return filter.isOpcodeEnabled(makeProp(PROP_OPCODE, opcode));
    }

    bool isTestEnabled(Inst inst)
    { 
        registerTestProps(inst); 
        return filter.isTestEnabled(testProps);
    }

    bool startTest(Inst inst)
    { 
        registerTestProps(inst); 
        if (filter.isTestEnabled(testProps))
        {
            const char* instName = val2str(PROP_OPCODE, inst.opcode());
            assert(instName);

            unsigned baseCategoryId = getBaseCategoryId(inst);
            testCategories = getCategoryTags(inst, baseCategoryId);

            relPath = getCategoryName(inst, baseCategoryId, '/') + "/" + instName;
            fullPath = rootPath 
                     + getCategoryName(inst, baseCategoryId, getPathDelimiter()[0]) 
                     + getPathDelimiter() 
                     + instName;

            createPath(fullPath);
            return true;
        }
        return false;
    }
    
    void registerTest(unsigned opcode, unsigned idx)  
    { 
        writeTestInfo(opcode, idx);
    }

    string getTestPath()
    {
        return fullPath + getPathDelimiter();
    }

    static const char* val2str(unsigned propId, unsigned propVal) { return PropValidator::val2str(propId, propVal); }

    //==========================================================================
private:
    void addProp(const char* propName, string propVal) { addProp(propName, propVal.c_str()); }
    void addProp(const char* propName, const char* propVal, const char* defaultVal = "none")
    {
        if (!propVal || strlen(propVal) == 0) propVal = defaultVal;
        addProp(string(propName) + "=" + propVal);
    }

    void addProp(string prop)
    {
        testProps.push_back(prop);
    }

    void addProp(unsigned propId, unsigned propVal)
    {
        addProp(makeProp(propId, propVal));
    }

    void addPropEx(Inst inst, unsigned propId, unsigned propVal)
    {
        if (propId == PROP_EQCLASS)
        {
            ostringstream s;
            s << propVal;
            addProp(makeProp(propId, s.str()));
            addProp(makeDefaultProp(propId, propVal == 0));
        }
        else if (propId == PROP_WIDTH)
        {
            addProp(makeProp(propId, propVal));
            addProp(makeDefaultProp(propId, propVal == getDefWidth(inst)));
        }
    }

    string makeProp(unsigned propId, string propVal)
    {
        return PropValidator::prop2key(propId) + string("=") + propVal;
    }

    string makeProp(unsigned propId, unsigned propVal)
    {
        return makeProp(propId, PropValidator::val2str(propId, propVal));
    }

    string makeDefaultProp(unsigned propId, bool isDefault)
    {
        return makeProp(propId, isDefault? DEFAULT_PROP_VAL_NAME : NONDEFAULT_PROP_VAL_NAME);
    }

    //==========================================================================
private:
    void registerProps(InstBasic inst)
    {
        // nothing to do
    }

    void registerProps(InstAddr inst)
    {
        addProp(PROP_SEGMENT, PropValidator::getSegment(inst));
    }

    void registerProps(InstAtomic inst)
    {
        addProp(PROP_SEGMENT, PropValidator::getSegment(inst));
        addProp(PROP_MEMORD,  PropValidator::getMemord(inst));
        addProp(PROP_MEMSCP,  PropValidator::getMemscp(inst));
        addProp(PROP_ATMOP,   PropValidator::getAtmop(inst));
    }

    void registerProps(InstAtomicImage inst)
    {
        addProp(PROP_ITYPE, PropValidator::getItype(inst));
        addProp(PROP_CTYPE, PropValidator::getCtype(inst));
        addProp(PROP_ATMOP, PropValidator::getAtmop(inst));
        addProp(PROP_GEOM,  PropValidator::getGeom(inst));
    }

    void registerProps(InstBar inst)
    {
        addProp(PROP_MEMORD, PropValidator::getMemord(inst));
        addProp(PROP_MEMSCP, PropValidator::getMemscp(inst));
        addProp(PROP_MEMFNC, PropValidator::getMemfnc(inst));
        addPropEx(inst, PROP_WIDTH,  PropValidator::getWidth(inst));      
    }

    void registerProps(InstBr inst)
    {
        addPropEx(inst, PROP_WIDTH,  PropValidator::getWidth(inst));
    }

    void registerProps(InstCmp inst)
    {
        addProp(PROP_STYPE,    PropValidator::getStype(inst));
        addProp(PROP_OPERATOR, PropValidator::getOperator(inst));
        addProp(PROP_PACKING,  PropValidator::getPacking(inst));
        addProp(PROP_ROUNDING, PropValidator::getRounding(inst));
        addProp(PROP_FTZ,      PropValidator::getFtz(inst));
    }

    void registerProps(InstCvt inst)
    {
        addProp(PROP_STYPE,    PropValidator::getStype(inst));      
        addProp(PROP_ROUNDING, PropValidator::getRounding(inst));
        addProp(PROP_FTZ,      PropValidator::getFtz(inst));
    }

    void registerProps(InstLane inst)
    {
        addProp(PROP_STYPE, PropValidator::getStype(inst));
        addPropEx(inst, PROP_WIDTH, PropValidator::getWidth(inst));     
    }

    void registerProps(InstImage inst)
    {
        addProp(PROP_ITYPE, PropValidator::getItype(inst));
        addProp(PROP_CTYPE, PropValidator::getCtype(inst));
        addProp(PROP_GEOM,  PropValidator::getGeom(inst));
    }

    void registerProps(InstMem inst)
    {
        addProp(PROP_SEGMENT, PropValidator::getSegment(inst));
        addPropEx(inst, PROP_WIDTH,   PropValidator::getWidth(inst));
        addProp(PROP_ALIGN,   PropValidator::getAlign(inst));
        addPropEx(inst, PROP_EQCLASS, inst.equivClass());
    }

    void registerProps(InstMod inst)
    {
        addProp(PROP_PACKING,  PropValidator::getPacking(inst));
        addProp(PROP_ROUNDING, PropValidator::getRounding(inst));
        addProp(PROP_FTZ,      PropValidator::getFtz(inst));
    }

    void registerProps(InstSeg inst)
    {
        addProp(PROP_STYPE,   PropValidator::getStype(inst));
        addProp(PROP_SEGMENT, PropValidator::getSegment(inst));
    }

    void registerProps(InstSourceType inst)
    {
        addProp(PROP_STYPE,    PropValidator::getStype(inst));
    }

    void registerOperandProps(unsigned i, Operand opr)
    {
        if (!opr) 
        {
            addProp(operandName[i], "null");
            return;
        }

        addProp(operandName[i], PropValidator::operandKind2str(opr.kind()));
    }

    void registerOperandProps(Inst inst)
    {
        for (int i = 0; i < 5; ++i)
        {
            registerOperandProps(i, inst.operand(i));
        }
    }

    void registerTestProps(Inst inst)
    {
        testProps.clear();

        addProp(PROP_OPCODE, inst.opcode());
        addProp(PROP_TYPE,   PropValidator::getType(inst));

        switch (inst.brig()->kind)
        {
        case Brig::BRIG_INST_BASIC:        registerProps(InstBasic(inst));       break;
        case Brig::BRIG_INST_ADDR:         registerProps(InstAddr(inst));        break;
        case Brig::BRIG_INST_ATOMIC:       registerProps(InstAtomic(inst));      break;
        case Brig::BRIG_INST_ATOMIC_IMAGE: registerProps(InstAtomicImage(inst)); break;
        case Brig::BRIG_INST_BAR:          registerProps(InstBar(inst));         break;
        case Brig::BRIG_INST_BR:           registerProps(InstBr(inst));          break;
        case Brig::BRIG_INST_CMP:          registerProps(InstCmp(inst));         break;
        case Brig::BRIG_INST_CVT:          registerProps(InstCvt(inst));         break;
        case Brig::BRIG_INST_LANE:         registerProps(InstLane(inst));        break;
        case Brig::BRIG_INST_IMAGE:        registerProps(InstImage(inst));       break;
        case Brig::BRIG_INST_MEM:          registerProps(InstMem(inst));         break;
        case Brig::BRIG_INST_MOD:          registerProps(InstMod(inst));         break;
        case Brig::BRIG_INST_SEG:          registerProps(InstSeg(inst));         break;
        case Brig::BRIG_INST_SOURCE_TYPE:  registerProps(InstSourceType(inst));  break;
        default: 
            assert(false); 
            break;
        }

        registerOperandProps(inst);
    }

private:
    void initBaseCategoryTab();
    unsigned getBaseCategoryId(Inst inst);
    unsigned getBaseCategoriesNum() { return sizeof(baseCategories) / sizeof(CategoryDesc); }

    //==========================================================================
    //==========================================================================
    //==========================================================================
private:

    void openStream()
    {
        assert(!osfs.is_open());
        string testlist = string(rootPath) + HSAIL_TESTLIST;
        osfs.open(testlist.c_str());
        if (osfs.bad()) {
            throw TestGenError("Failed to create " + testlist);
        }
    }

    void closeStream()
    {
        if (!osfs.bad() && osfs.is_open()) {
            osfs.close();
        }
    }

    void writeTestInfo(unsigned opcode, unsigned testIdx)
    {
        if (!osfs.is_open()) openStream();

        if (!osfs.bad()) 
        {
            if (dumpTestProps)              // dump full test description
            {
                ostringstream s;
                s << ":" << std::setw(5) << std::setfill('0') << testIdx;
                osfs << relPath << s.str() << " all";
                for (unsigned i = 0; i < testProps.size(); ++i) {
                    osfs << ',' << testProps[i];
                }
                osfs << testCategories << "\n";
            }
            else                            // dump only list of opcodes
            {
                const char* opcName = opcode2str(opcode);
                assert(opcName);
                if (lastOpcode == 0 || strcmp(opcName, lastOpcode) != 0) {
                    lastOpcode = opcName;
                    osfs << opcName << "\n";
                }
            }
        }
    }

    void createPath(string path)
    {
        bool existed = false;
        llvm::error_code ec;

        if (llvm::sys::fs::exists(path))
        {
            ec = llvm::sys::fs::is_directory(path, existed);
            if (ec != llvm::errc::success || !existed) {
                throw TestGenError(path + " must be a directory");
            }
        }

        existed = false;
        ec = llvm::sys::fs::create_directories(path, existed);
        if (ec != llvm::errc::success)
        {
            throw TestGenError(std::string("Failed to create ") + path);
        }
    }

    //==========================================================================
    //==========================================================================
    //==========================================================================
private:

    static string getCategoryName(Inst inst, unsigned category, char delim)
    {
        assert(category < C_MAXID);
        string res = categoryName[category];

        switch(category)
        {
        case C_ART:         // packed, type
        case C_GCN_ART:     // type
            if (getPacking(inst) != Brig::BRIG_PACK_NONE || HSAIL_ASM::isPackedType(getType(inst)))
            {
                res += getPackedCategory(inst);
            }
            else
            {
                res += getTypeCategory(inst);
            }
            break;
        case C_MOV: {       // type, vector
            string v = getVectorCategory(inst);
            res += (v.length() > 0)? v : getTypeCategory(inst);
            }
            break;
        case C_MEM_ATM:
        case C_GCN_MEM_ATM:
            break;
        case C_MEM_NAT:     // vector
        case C_GCN_MEM_NAT: // vector
            res += getVectorCategory(inst);
            break;
        case C_BR:          // direct, indirect
            res += getBranchCategory(inst);
            break;
        case C_IMG_ATM:
        case C_IMG_NAT:
        case C_SYNC:
        case C_MSC:
        case C_GCN_MSK:
            break;
        default:
            assert(false);
            return "";
        }

        if (delim != '/') std::replace(res.begin(), res.end(), '/', delim);

        return res;
    }

    static string getCategoryTags(Inst inst, unsigned category)
    {
        assert(category < C_MAXID);
        string res = ',' + getCategoryName(inst, category, ',');

        if (isOperandCategory(inst, Brig::BRIG_OPERAND_WAVESIZE)) res += ",wavesize";

        if (isWidthCategory(inst)) res += ",width";
        if (isEquivCategory(inst)) res += ",equiv";

        unsigned type    = inst.type();
        unsigned srcType = getSrcType(inst);
        unsigned segment = getSegment(inst);
        unsigned opcode  = inst.opcode();

        if      (type == Brig::BRIG_TYPE_F16  || srcType == Brig::BRIG_TYPE_F16)  res += ",f16";
        else if (type == Brig::BRIG_TYPE_B128 || srcType == Brig::BRIG_TYPE_B128) res += ",b128";

        switch(opcode)
        {
        case Brig::BRIG_OPCODE_MIN:
        case Brig::BRIG_OPCODE_MAX:
            if (type == Brig::BRIG_TYPE_S64) res += ",min_max_s64";
            break;

        case Brig::BRIG_OPCODE_MUL24:
        case Brig::BRIG_OPCODE_MAD24:
            res += ",mul24_mad24";
            break;

        case Brig::BRIG_OPCODE_SAD:
        case Brig::BRIG_OPCODE_SADHI:
            res += ",sad";
            break;

        case Brig::BRIG_OPCODE_ST:
        case Brig::BRIG_OPCODE_GCNST:
            if (inst.operand(0) && inst.operand(0).kind() == Brig::BRIG_OPERAND_IMMED)
            {
                res += ",st_imm";
                OperandImmed imm = inst.operand(0);
                if (getBitSize(imm.type()) < 32)
                    res += ",st_imm_subword";
            }
            if (segment == Brig::BRIG_SEGMENT_GLOBAL &&
                (type == Brig::BRIG_TYPE_S8 || type == Brig::BRIG_TYPE_S16 || type == Brig::BRIG_TYPE_S32))
            {
                res += ",st_s8_s16_s32_global";
            }
            if (segment == Brig::BRIG_SEGMENT_READONLY) {
                res += ",st_readonly";
            }
            break;

        case Brig::BRIG_OPCODE_LASTBIT:
            if (type == Brig::BRIG_TYPE_B32 || type == Brig::BRIG_TYPE_B64) {
                res += ",lastbit_b";
            }
            break;

        case Brig::BRIG_OPCODE_BITINSERT:
            if (type == Brig::BRIG_TYPE_S64 || type == Brig::BRIG_TYPE_U64) {
                res += ",bitinsert_64";
            }
            break;

        case Brig::BRIG_OPCODE_CMP:
            if (type != Brig::BRIG_TYPE_B1)      res += ",cmp_non_b1";
            if (srcType == Brig::BRIG_TYPE_B32)  res += ",cmp_b32";
            if (HSAIL_ASM::isFloatType(srcType)) res += ",cmp_float";
            break;

        case Brig::BRIG_OPCODE_CVT:
            if ((srcType == Brig::BRIG_TYPE_F64 && (type == Brig::BRIG_TYPE_F32 || type == Brig::BRIG_TYPE_S64 || type == Brig::BRIG_TYPE_U64)) ||
                ((srcType == Brig::BRIG_TYPE_S64 || srcType == Brig::BRIG_TYPE_U64) && (type == Brig::BRIG_TYPE_F32 || type == Brig::BRIG_TYPE_F64)))
            {
                res += ",cvt_fsu";
            }
            break;

        case Brig::BRIG_OPCODE_SYSCALL:
            res += ",syscall";
            break;

        case Brig::BRIG_OPCODE_MASKLANE:
        case Brig::BRIG_OPCODE_COUNTUPLANE:
        case Brig::BRIG_OPCODE_SENDLANE:
        case Brig::BRIG_OPCODE_RECEIVELANE:
            res += ",crosslane";
            break;

        case Brig::BRIG_OPCODE_INITFBAR:
        case Brig::BRIG_OPCODE_JOINFBAR:
        case Brig::BRIG_OPCODE_WAITFBAR:
        case Brig::BRIG_OPCODE_ARRIVEFBAR:
        case Brig::BRIG_OPCODE_RELEASEFBAR:
        case Brig::BRIG_OPCODE_LEAVEFBAR:
        case Brig::BRIG_OPCODE_LDF:
            res += ",fbar";
            break;

        case Brig::BRIG_OPCODE_DEBUGTRAP:
            res += ",debugtrap";
            break;

        case Brig::BRIG_OPCODE_CLOCK:
        case Brig::BRIG_OPCODE_CUID:
        case Brig::BRIG_OPCODE_DISPATCHID:
        case Brig::BRIG_OPCODE_WAVEID:
        case Brig::BRIG_OPCODE_LANEID:
        case Brig::BRIG_OPCODE_MAXWAVEID:
        case Brig::BRIG_OPCODE_NOP:
        case Brig::BRIG_OPCODE_DIM:
        case Brig::BRIG_OPCODE_WORKGROUPID:
        case Brig::BRIG_OPCODE_WORKITEMFLATID:
        case Brig::BRIG_OPCODE_GRIDGROUPS:
        case Brig::BRIG_OPCODE_GRIDSIZE:
        case Brig::BRIG_OPCODE_WORKGROUPSIZE:
        case Brig::BRIG_OPCODE_WORKITEMID:
        case Brig::BRIG_OPCODE_WORKITEMABSID:
        case Brig::BRIG_OPCODE_WORKITEMFLATABSID:
        case Brig::BRIG_OPCODE_SETDETECTEXCEPT:
        case Brig::BRIG_OPCODE_CLEARDETECTEXCEPT:
        case Brig::BRIG_OPCODE_GETDETECTEXCEPT:
        case Brig::BRIG_OPCODE_DISPATCHPTR:
        case Brig::BRIG_OPCODE_NULLPTR:
        case Brig::BRIG_OPCODE_QPTR:
        case Brig::BRIG_OPCODE_MAXCUID:
        case Brig::BRIG_OPCODE_QID:

            res += ",special_op";
            break;

        case Brig::BRIG_OPCODE_GCNB4XCHG:
        case Brig::BRIG_OPCODE_GCNB32XCHG:
        case Brig::BRIG_OPCODE_GCNMQSAD4:
            res += ",gcn_xchg_mqsad";
            break;

        case Brig::BRIG_OPCODE_GCNSLEEP:
        case Brig::BRIG_OPCODE_GCNPRIORITY:
            res += ",gcn_sleep_priority";
            break;

        default:
            break;
        }

        switch(opcode)
        {
        case Brig::BRIG_OPCODE_FRACT:
        case Brig::BRIG_OPCODE_MIN:
        case Brig::BRIG_OPCODE_MAX:
        case Brig::BRIG_OPCODE_NEG:
            res += ",fract_min_max_neg";
            break;

        case Brig::BRIG_OPCODE_GCNATOMIC:
        case Brig::BRIG_OPCODE_GCNATOMICNORET:
            res += ",gcn_atomic";
            break;

        case Brig::BRIG_OPCODE_GCNLD:
        case Brig::BRIG_OPCODE_GCNST:
        case Brig::BRIG_OPCODE_GCNREGIONALLOC:
        case Brig::BRIG_OPCODE_GCNAPPEND:
        case Brig::BRIG_OPCODE_GCNCONSUME:
            res += ",gcn_region";
            break;

        default:
            break;
        }

        switch(segment)
        {
        case Brig::BRIG_SEGMENT_PRIVATE:
        case Brig::BRIG_SEGMENT_SPILL:
        case Brig::BRIG_SEGMENT_ARG:
        case Brig::BRIG_SEGMENT_READONLY:
            if (opcode == Brig::BRIG_OPCODE_ATOMIC || opcode == Brig::BRIG_OPCODE_ATOMICNORET) {
                res += ",atm_segments";
            }
            break;
        case Brig::BRIG_SEGMENT_FLAT:
            res += ",flat";
            break;
        default:
            break;
        }

        return res;
    }

    static bool isWidthCategory(Inst inst) //F autogenerate
    {
        switch (inst.opcode())
        {
        case Brig::BRIG_OPCODE_LD:
        case Brig::BRIG_OPCODE_GCNLD:
        case Brig::BRIG_OPCODE_BRN:
        case Brig::BRIG_OPCODE_CBR:
        case Brig::BRIG_OPCODE_BARRIER:
        case Brig::BRIG_OPCODE_CALL:
        case Brig::BRIG_OPCODE_JOINFBAR:
        case Brig::BRIG_OPCODE_WAITFBAR:
        case Brig::BRIG_OPCODE_ARRIVEFBAR:
        case Brig::BRIG_OPCODE_LEAVEFBAR:
        case Brig::BRIG_OPCODE_MASKLANE:
        case Brig::BRIG_OPCODE_COUNTLANE:
        case Brig::BRIG_OPCODE_COUNTUPLANE:
        case Brig::BRIG_OPCODE_SENDLANE:
        case Brig::BRIG_OPCODE_RECEIVELANE:
            return true;
        default:
            return false;
        }
    }

    static bool isEquivCategory(Inst inst) //F autogenerate
    {
        switch (inst.opcode())
        {
        case Brig::BRIG_OPCODE_LD:
        case Brig::BRIG_OPCODE_ST:
        case Brig::BRIG_OPCODE_GCNLD:
        case Brig::BRIG_OPCODE_GCNST:
            return true;
        default:
            return false;
        }
    }

    static bool isOperandCategory(Inst inst, unsigned kind)
    {
        for (unsigned idx = 0; idx < 5 && inst.operand(idx); ++idx)
        {
            if (inst.operand(idx).brig()->kind == kind) return true;
        }
        return false;
    }

    static string getTypeCategory(Inst inst)
    {
        return string("/") + val2str(PROP_TYPE, getType(inst));
    }

    static string getPackedCategory(Inst inst)
    {
        return "/packed";
    }

    static string getVectorCategory(Inst inst)
    {
        for (unsigned idx = 0; idx < 5 && inst.operand(idx); ++idx)
        {
            unsigned kind = inst.operand(idx).brig()->kind;
            if (kind == Brig::BRIG_OPERAND_REG_VECTOR) return "/vector";
        }
        return "";
    }

    static string getBranchCategory(Inst inst)
    {
        for (unsigned idx = 0; idx < 5 && inst.operand(idx); ++idx)
        {
            if (OperandReg reg = inst.operand(idx)) {
                if (reg.type() != Brig::BRIG_TYPE_B1) return "/indirect";
            }
        }
        return "/direct";
    }

    const char* getPathDelimiter() { return llvm::sys::path::is_separator('\\')? "\\" : "/"; }
};

void TestGenNavigatorImpl::initBaseCategoryTab()
{
    assert(!instCategoryTab);
    unsigned size = getBaseCategoriesNum();
    instCategoryTab = new CategoryDesc[size];
    std::copy(baseCategories, baseCategories + size, instCategoryTab);
    std::sort(instCategoryTab, instCategoryTab + size);
}

unsigned TestGenNavigatorImpl::getBaseCategoryId(Inst inst)
{
    if (!instCategoryTab) initBaseCategoryTab();

    CategoryDesc sample = {0, inst.opcode()};
    unsigned size = getBaseCategoriesNum();
    CategoryDesc* res = std::lower_bound(instCategoryTab, instCategoryTab + size, sample);

    if (res >= instCategoryTab + size || res->instOpcode != inst.opcode()) {
        ostringstream s;
        const char* name = HSAIL_ASM::opcode2str(inst.opcode());
        s << "Internal error: cannot get category for opcode " << inst.opcode() << " (" << (name? name : "UNKNOWN") << ')';
        throw TestGenError(s.str());
    } else if (res->categoryId >= C_MAXID) {
        ostringstream s;
        const char* name = HSAIL_ASM::opcode2str(inst.opcode());
        s << "Internal error: invalid category id for opcode " << inst.opcode() << " (" << (name? name : "UNKNOWN") << ')';
        throw TestGenError(s.str());
    }
    
    return res->categoryId;
}

//=============================================================================
// Interface definition
//=============================================================================

TestGenNavigator::TestGenNavigator(string path)
{
    impl = new TestGenNavigatorImpl(path);
}

TestGenNavigator::~TestGenNavigator()
{
    delete impl;
}

bool TestGenNavigator::isOpcodeEnabled(unsigned opcode) const
{
    return impl->isOpcodeEnabled(opcode);
}

bool TestGenNavigator::isTestEnabled(Inst inst)
{
    return impl->isTestEnabled(inst);
}

bool TestGenNavigator::startTest(Inst inst)
{
    return impl->startTest(inst);
}

void TestGenNavigator::registerTest(unsigned opcode, unsigned idx)
{
    impl->registerTest(opcode, idx);
}

string TestGenNavigator::getTestPath()
{
    return impl->getTestPath();
}

//=============================================================================
//=============================================================================
//=============================================================================

} // namespace TESTGEN
