//=-  HSAILTestGenLuaTestData.h - HSAIL TestGen - Description of test data  -=//
//
//===----------------------------------------------------------------------===//
//
// (C) 2013 AMD Inc. All rights reserved.
//
//===----------------------------------------------------------------------===//

//=================================================================================================
//=================================================================================================
//==============================      DESCRIPTION OF TEST DATA      ===============================
//=================================================================================================
//=================================================================================================
//
// This file defines test data for each lua-supported HSAIL instruction.
// There are two parts in this description:
// 
//  1. Description of predefined test data for standard HSAIL types.
//  2. Description of test data for each supported HSAIL instruction. 
//

//=================================================================================================
//=================================================================================================
//==========================      BOUNDARY AND SPECIAL TEST VALUES      ===========================
//=================================================================================================
//=================================================================================================

static const u32_t MAX_U8  = 0xffU;
static const u32_t MAX_U16 = 0xffffU;
static const u32_t MAX_U32 = 0xffffffffU;
static const u64_t MAX_U64 = 0xffffffffffffffffULL;

static const u32_t MID_U8  = 0x7fU;
static const u32_t MID_U16 = 0x7fffU;
static const u32_t MID_U32 = 0x7fffffffU;
static const u64_t MID_U64 = 0x7fffffffffffffffULL;

static const s8_t MAX_S8 = 0x7f;
static const s8_t MIN_S8 = (s8_t)0x80;

static const s16_t MAX_S16 = 0x7fff;
static const s16_t MIN_S16 = (s16_t)0x8000;

static const s32_t MAX_S32 = 0x7fffffff;
static const s32_t MIN_S32 = 0x80000000;

static const s64_t MAX_S64 = 0x7fffffffffffffffLL;
static const s64_t MIN_S64 = 0x8000000000000000LL;

static const f32_t FLOAT_PI  = (f32_t) 3.14159265358979323846;
static const f64_t DOUBLE_PI = (f64_t) 3.14159265358979323846;

static const f32_t FLOAT_NAN  = numeric_limits<float>::quiet_NaN();
static const f64_t DOUBLE_NAN = numeric_limits<double>::quiet_NaN();

static const f32_t FLOAT_INF  = numeric_limits<float>::infinity();
static const f64_t DOUBLE_INF = numeric_limits<double>::infinity();

static const f32_t FLOAT_DENORM  = numeric_limits<float>::denorm_min();
static const f64_t DOUBLE_DENORM = numeric_limits<double>::denorm_min();

static f32_t extraTestsF32[] = {-10.00f, -10.25f, -10.50f, -10.75f, 10.00f,  10.25f,  10.50f,  10.75f};
static f64_t extraTestsF64[] = {-10.00,  -10.25,  -10.50,  -10.75,  10.00,   10.25,   10.50,   10.75};

static f32_t roundTestsF32[] = {-2.50f, -1.50f, -0.75f, -0.50000005f,        -0.50f, -0.25f, 0.25f, 0.50f, 0.50000005f,        0.75f, 1.50f, 1.5000001f,         2.5f };
static f64_t roundTestsF64[] = {-2.50,  -1.50,  -0.75,  -0.5000000000000001, -0.50,  -0.25,  0.25,  0.50,  0.5000000000000001, 0.75,  1.50,  1.5000000000000002, 2.5 };

static f32_t extraSubnormF32[] = {-FLOAT_DENORM  * 512, FLOAT_DENORM};
static f64_t extraSubnormF64[] = {-DOUBLE_DENORM * 512, DOUBLE_DENORM};

// Test values for Native Floating-Point Operations (should not include subnormals)
static f32_t nfpF32[] = {-FLOAT_INF,  -FLOAT_PI,  -1, -0.0, +0.0, 1, FLOAT_PI,  FLOAT_INF,  FLOAT_NAN};
static f64_t nfpF64[] = {-DOUBLE_INF, -DOUBLE_PI, -1, -0.0, +0.0, 1, DOUBLE_PI, DOUBLE_INF, DOUBLE_NAN};

//F make const
static u32_t classFlags[] = {0, 0xFFFFFFFF, 0x001, 0x002, 0x004, 0x008, 0x010, 0x020, 0x040, 0x080, 0x100, 0x200};

static s32_t s24Tests[] = {-0x400000, -0x3FFFFF, 0xABCDE, 0x3FFFFF};
static u32_t u24Tests[] = {0xABCDE, 0x7FFFFF};

//=================================================================================================
//=================================================================================================
//====================     PREDEFINED TEST DATA FOR STANDARD HSAIL TYPES      =====================
//=================================================================================================
//=================================================================================================

#define TEST_DATA_b1_t  {0, 1};
#define TEST_DATA_b8_t  {0, 1, 64, MID_U8,  MAX_U8};
#define TEST_DATA_b16_t {0, 1, 64, MID_U16, MAX_U16};
#define TEST_DATA_b32_t {0, 1, 64, MID_U32, MAX_U32};
#define TEST_DATA_b64_t {0, 1, 64, MID_U64, MAX_U64};
                        
#define TEST_DATA_u8_t  {0, 1, 64, MID_U8,  MAX_U8};
#define TEST_DATA_u16_t {0, 1, 64, MID_U16, MAX_U16};
#define TEST_DATA_u32_t {0, 1, 64, MID_U32, MAX_U32};
#define TEST_DATA_u64_t {0, 1, 64, MID_U64, MAX_U64};
                        
#define TEST_DATA_s8_t  {MIN_S8,  -64, -1, 0, 1, 64, MAX_S8};
#define TEST_DATA_s16_t {MIN_S16, -64, -1, 0, 1, 64, MAX_S16};
#define TEST_DATA_s32_t {MIN_S32, -64, -1, 0, 1, 64, MAX_S32};
#define TEST_DATA_s64_t {MIN_S64, -64, -1, 0, 1, 64, MAX_S64};
                        
#define TEST_DATA_f32_t {-FLOAT_INF,  -FLOAT_PI,  -1.0f, -0.0f, +0.0f, 1.0f, FLOAT_PI,  FLOAT_INF,  FLOAT_NAN,  -FLOAT_DENORM  * 256, FLOAT_DENORM  * 256};
#define TEST_DATA_f64_t {-DOUBLE_INF, -DOUBLE_PI, -1.0,  -0.0,  +0.0,  1.0,  DOUBLE_PI, DOUBLE_INF, DOUBLE_NAN, -DOUBLE_DENORM * 256, DOUBLE_DENORM * 256};

//=================================================================================================
//=================================================================================================
//==========================      TEST DATA FOR HSAIL INSTRUCTIONS      ===========================
//=================================================================================================
//=================================================================================================
//
// The following table specifies test data for HSAIL instructions.
//
// Each record describes one instruction and has the following format:
//
//     INST(<opcode>) TYPE(<type1>) SRC(<test data for type1>);
//                    TYPE(<type2>) SRC(<test data for type2>);
//                    TYPE(<type3>) SRC(<test data for type3>);
//                    ...
//
// TYPE and SRC_TYPE
//
//      These two macro specify type of arguments as encoded in the instruction. This type depends on 
//      instruction format and specifies either instruction type or source type.
//      (Note that these macro have identical semantics; the latter was added to improve readability.)
//
//          ----------------------------
//          Format      Type
//          ----------------------------
//          Basic       instruction type
//          Mod         instruction type
//          Atomic      instruction type
//          Cvt         source type
//          Cmp         source type
//          SourceType  source type
//          ----------------------------
//
//      See LuaTestGen::getProvider for details.
//
// SRC  
//
//  This macro specifies test data for HSAIL instruction, more specifically: 
//
//      - number of source operands;
//      - for each operand:
//          - type of test values;
//          - a set of test values.
//
//      NB: Type of test data for an operand IS REQUIRED to be the same as type of this operand.
//
//      Test data may be described using either SRCN or SRCT macro:
//         1) SRCN(<number of arguments>);
//         2) SRCT(<test data for 1st src argument>, <test data for 2d src argument>, ...);
//
//      SRCN(n) states the following:
//          - operation has 'n' source arguments;
//          - test data for all arguments have the same type specified by TYPE macro;
//          - use standard (predefined) test data for each argument based on its type.
//            (Standart sets of test data for each HSAIL type are defined in the previous section)
//
//      SRCT(T1, T2, ... Tn) states the following:
//          - operation has 'n' source arguments;
//          - test data type and values for i-th argument are specified by Ti macro.
//            There is one macro for each HSAIL type; their names are similar to HSAIL types as well.
//            Full list of currently supported macros follows:  
//
//                  B1T, B8T, B16T, B32T, B64T      - 'b' types
//                  U8T, U16T, U32T, U64T           - 'u' types
//                  S8T, S16T, S32T, S64T           - 's' types
//                  F32T, F64T                      - 'f' types
//
//            When used without modifiers, each macro provides a standard set of test values 
//            for its base type, as defined in the previous section. There are modifiers which
//            allow customization of standard values:
//
//                  ADD(val1, val2, ...) - add values val1, val2, ... to the test set
//                  ADDL(array)          - add values from array to the test set
//                  XCL(val1, val2, ...) - remove values val1, val2, ... from the test set
//                  NEW(val1, val2, ...) - create a new test set of the same type with 
//                                         values val1, val2, ...
//
//              Examples:
//
//                  SRCN(2);                 // 2 src arguments; default test data type and values
//                  SRCT(S32.ADD(7));        // 1 src argument with test set based on S32 
//                                           // with additional value "7"
//                  SRCT(S32.XCL(7));        // 1 src argument with test set based on S32 
//                                           // with value "7" excluded
//                  SRCT(S32.ADD(7).XCL(8)); // 1 src argument with test set based on S32
//                                           // with additional value "7" and value "8" excluded
//                  SRCT(S32.NEW(7).XCL(8)); // 1 source argument of type s32 with 1 value "7" 
//                                           // and value "8" excluded.
//
//=================================================================================================

// NB: The following list includes all standard HSAIL instructions and types of their operands.
// NB: Instructions and types not supported yet by LUA extension are commented out
//     (except for packed types, f16, b128, image and sampler types which are not shown). 

BEGIN_TEST_DATA

    INST(ADD)         TYPE(S32)
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64)
                      TYPE(F32)
                      TYPE(F64) SRCN(2);

    INST(SUB)         TYPE(S32)
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64)
                      TYPE(F32)
                      TYPE(F64) SRCN(2);

    INST(MAX)         TYPE(S32)
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64)
                      TYPE(F32)
                      TYPE(F64) SRCN(2);

    INST(MIN)         TYPE(S32)             
                      TYPE(S64)             
                      TYPE(U32)
                      TYPE(U64)
                      TYPE(F32)
                      TYPE(F64) SRCN(2);

    INST(MUL)         TYPE(S32)
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64)
                      TYPE(F32)
                      TYPE(F64) SRCN(2);

    INST(MULHI)       TYPE(S32)
                      TYPE(S64)
                      TYPE(U32) 
                      TYPE(U64) SRCN(2);

    INST(DIV)         TYPE(S32) SRCT( S32T.XCL(MIN_S32).ADD(-63, 127), S32T.XCL(0).ADD(-15, 30) );
                      TYPE(S64) SRCT( S64T.XCL(MIN_S64).ADD(-63, 127), S64T.XCL(0).ADD(-15, 30) );
                      TYPE(U32) SRCT( U32T.XCL(MIN_S32).ADD(     127), U32T.XCL(0).ADD(     30) );
                      TYPE(U64) SRCT( U64T.XCL(MIN_S64).ADD(     127), U64T.XCL(0).ADD(     30) );
                      TYPE(F32) 
                      TYPE(F64) SRCN(2);

    INST(REM)         TYPE(S32) SRCT( S32T.XCL(MIN_S32).ADD(-63, 127), S32T.XCL(0).ADD(-15, 30) );
                      TYPE(S64) SRCT( S64T.XCL(MIN_S64).ADD(-63, 127), S64T.XCL(0).ADD(-15, 30) );
                      TYPE(U32) SRCT( U32T.XCL(MIN_S32).ADD(     127), U32T.XCL(0).ADD(     30) );
                      TYPE(U64) SRCT( U64T.XCL(MIN_S64).ADD(     127), U64T.XCL(0).ADD(     30) );

    INST(CARRY)       TYPE(S32)             
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64) SRCN(2);

    INST(BORROW)      TYPE(S32)             
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64) SRCN(2);

    INST(NEG)         TYPE(S32)
                      TYPE(S64)
                      TYPE(F32)
                      TYPE(F64) SRCN(1);

    INST(ABS)         TYPE(S32)
                      TYPE(S64)
                      TYPE(F32)
                      TYPE(F64) SRCN(1);

    INST(COPYSIGN)    TYPE(F32)
                      TYPE(F64) SRCN(2);

    INST(FRACT)       TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(roundTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(roundTestsF64) );

    INST(SQRT)        TYPE(F32) SRCT( F32T.ADDL(extraTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64) );

    INST(CEIL)        TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(roundTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(roundTestsF64) );

    INST(FLOOR)       TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(roundTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(roundTestsF64) );

    INST(RINT)        TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(roundTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(roundTestsF64) );

    INST(TRUNC)       TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(roundTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(roundTestsF64) );

    INST(MUL24)       TYPE(S32) SRCT( S32T.ADDL(s24Tests), S32T.ADDL(s24Tests) );
                      TYPE(U32) SRCT( U32T.ADDL(u24Tests), U32T.ADDL(u24Tests) );
    
    INST(MUL24HI)     TYPE(S32) SRCT( S32T.ADDL(s24Tests), S32T.ADDL(s24Tests) );
                      TYPE(U32) SRCT( U32T.ADDL(u24Tests), U32T.ADDL(u24Tests) );
    
    INST(MAD24)       TYPE(S32) SRCT( S32T.ADDL(s24Tests), S32T.ADDL(s24Tests), S32T.ADDL(s24Tests) );
                      TYPE(U32) SRCT( U32T.ADDL(u24Tests), U32T.ADDL(u24Tests), U32T.ADDL(u24Tests) );
    
    INST(MAD24HI)     TYPE(S32) SRCT( S32T.ADDL(s24Tests), S32T.ADDL(s24Tests), S32T.ADDL(s24Tests) );
                      TYPE(U32) SRCT( U32T.ADDL(u24Tests), U32T.ADDL(u24Tests), U32T.ADDL(u24Tests) );

    INST(MAD)         TYPE(S32)
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64)
                      TYPE(F32)
                      TYPE(F64) SRCN(3);

    INST(FMA)         TYPE(F32)
                      TYPE(F64) SRCN(3);

    INST(SHL)         TYPE(S32) SRCT( S32T, U32T.ADD(2, 31, 32, 33) ); // NB: src2 is always u32
                      TYPE(S64) SRCT( S64T, U32T.ADD(2, 63, 64, 65) );
                      TYPE(U32) SRCT( U32T, U32T.ADD(2, 31, 32, 33) );
                      TYPE(U64) SRCT( U64T, U32T.ADD(2, 63, 64, 65) );

    INST(SHR)         TYPE(S32) SRCT( S32T, U32T.ADD(2, 31, 32, 33) ); // NB: src2 is always u32
                      TYPE(S64) SRCT( S64T, U32T.ADD(2, 63, 64, 65) );
                      TYPE(U32) SRCT( U32T, U32T.ADD(2, 31, 32, 33) );
                      TYPE(U64) SRCT( U64T, U32T.ADD(2, 63, 64, 65) );

    INST(AND)         TYPE(B1)
                      TYPE(B32) 
                      TYPE(B64) SRCN(2);

    INST(OR)          TYPE(B1)
                      TYPE(B32)
                      TYPE(B64) SRCN(2);

    INST(XOR)         TYPE(B1)
                      TYPE(B32)
                      TYPE(B64) SRCN(2);

    INST(NOT)         TYPE(B1)
                      TYPE(B32)
                      TYPE(B64) SRCN(1);

    INST(POPCOUNT)    SRC_TYPE(B32) SRCT( B32T.ADD(0x7,    0x80,    0x40000000,            0x80000000,            0x90000000           ) );
                      SRC_TYPE(B64) SRCT( B64T.ADD(0x7ULL, 0x80ULL, 0x4000000000000000ULL, 0x8000000000000000ULL, 0x9000000000000000ULL) );

    INST(BITMASK)     TYPE(B32) SRCT( B32T.ADD(2, 31, 32), B32T.ADD(2, 31, 32) ); // source operands are always u32
                      TYPE(B64) SRCT( B32T.ADD(2, 63, 64), B32T.ADD(2, 63, 64) ); // source operands are always u32

    INST(BITSELECT)   TYPE(B32) SRCT( B32T.ADD(0xF0F0F0F0, 0xF0F0F0F, 0xFF00FF00, 0xFF00FF), 
                                      B32T.ADD(0xA251C468), 
                                      B32T.ADD(0xA251C468));
                      TYPE(B64) SRCT( B64T.ADD(0xF0F0F0F0F0F0F0F0ULL, 0xF0F0F0F0F0F0F0FULL, 0xFF00FF00FF00FF00ULL, 0xFF00FF00FF00FFULL), 
                                      B64T.ADD(0xA251C468A251C468ULL), 
                                      B64T.ADD(0xA251C468A251C468ULL));

    INST(BITREV)      TYPE(B32) SRCT( B32T.ADD(0xA251C468)            );
                      TYPE(B64) SRCT( B64T.ADD(0xA251C468A251C468ULL) );

    INST(BITEXTRACT)  TYPE(S32) SRCT( S32T.ADD(0xA251C468), 
                                      U32T.ADD(16, 31, 32), 
                                      U32T.ADD(8, 16, 31, 32));
                      TYPE(S64) SRCT( S64T.ADD(0xA251C468A251C468ULL), 
                                      U32T.ADD(32, 63, 64), 
                                      U32T.ADD(16, 32, 63, 64));
                      TYPE(U32) SRCT( U32T.ADD(0xA251C468), 
                                      U32T.ADD(16, 31, 32), 
                                      U32T.ADD(8, 16, 31, 32));
                      TYPE(U64) SRCT( U64T.ADD(0xA251C468A251C468ULL), 
                                      U32T.ADD(32, 63, 64), 
                                      U32T.ADD(16, 32, 63, 64));

    //NB: Due to 4 arguments, there are lots of test value combinations, so add new values with care!
    INST(BITINSERT)   TYPE(S32) SRCT( S32T.NEW(0xF0F0F0F0, 0xFF00FF),  
                                      S32T.NEW(0xA251C468, 0xF0F0F0F), 
                                      U32T.NEW(0, 1, 2, 31, 32),              // NB: src3 and src4 are always u32
                                      U32T.NEW(0, 1, 2, 31, 32)
                                    );
                      TYPE(S64) SRCT( S64T.NEW(0xF0F0F0F0F0F0F0F0ULL, 0xFF00FF00FF00FFULL),  
                                      S64T.NEW(0xA251C468A251C468ULL, 0xF0F0F0F0F0F0F0FULL), 
                                      U32T.NEW(0, 1, 2, 63, 64),              // NB: src3 and src4 are always u32
                                      U32T.NEW(0, 1, 2, 63, 64)
                                    );
                      TYPE(U32) SRCT( U32T.NEW(0xF0F0F0F0, 0xFF00FF),  
                                      U32T.NEW(0xA251C468, 0xF0F0F0F), 
                                      U32T.NEW(0, 1, 2, 31, 32),              // NB: src3 and src4 are always u32
                                      U32T.NEW(0, 1, 2, 31, 32)
                                    );
                      TYPE(U64) SRCT( U64T.NEW(0xF0F0F0F0F0F0F0F0ULL, 0xFF00FF00FF00FFULL),  
                                      U64T.NEW(0xA251C468A251C468ULL, 0xF0F0F0F0F0F0F0FULL), 
                                      U32T.NEW(0, 1, 2, 63, 64),              // NB: src3 and src4 are always u32
                                      U32T.NEW(0, 1, 2, 63, 64)
                                    );

    INST(FIRSTBIT)    SRC_TYPE(S32) SRCT( S32T.ADD(0x7FFFFFFF,            0x1FFFFFFF,            -2) );
                      SRC_TYPE(S64) SRCT( S64T.ADD(0x7FFFFFFFFFFFFFFFULL, 0x1FFFFFFFFFFFFFFFULL, -2) );
                      SRC_TYPE(U32) SRCT( U32T.ADD(0x7FFFFFFF,            0x1FFFFFFF               ) );
                      SRC_TYPE(U64) SRCT( U64T.ADD(0x7FFFFFFFFFFFFFFFULL, 0x1FFFFFFFFFFFFFFFULL    ) );

    INST(LASTBIT)     SRC_TYPE(S32) SRCT( S32T.ADD(0x8, 0xA, -2) );
                      SRC_TYPE(S64) SRCT( S64T.ADD(0x8, 0xA, -2) );
                      SRC_TYPE(U32) SRCT( U32T.ADD(0x8, 0xA    ) );
                      SRC_TYPE(U64) SRCT( U64T.ADD(0x8, 0xA    ) );

    INST(COMBINE)     SRC_TYPE(B32) SRCN(1);
                    //SRC_TYPE(B64) SRCN(1); // NB: require b128 which is not supported yet
                      
    INST(EXPAND)      SRC_TYPE(B64)  SRCN(1);
                    //SRC_TYPE(B128) SRCN(1); // NB: require b128 which is not supported yet

    INST(MOV)         TYPE(B1)
                      TYPE(B32)
                      TYPE(B64) 
                    //TYPE(B128) 
                      TYPE(S32) 
                      TYPE(S64) 
                      TYPE(U32) 
                      TYPE(U64) 
                      TYPE(F32) 
                      TYPE(F64) SRCN(1);

  //INST(LDA)         // NB: not testable
  //INST(LDC)         // NB: not testable

  //INST(SHUFFLE)     // NB: packed types
  //INST(UNPACKLO)    // NB: packed types
  //INST(UNPACKHI)    // NB: packed types

  //INST(PACK)        // NB: packed types
  //INST(UNPACK)      // NB: packed types

    INST(CMOV)        TYPE(B1)  SRCT(B1T, B1T, B1T);
                      TYPE(B32) SRCT(B1T, B32T, B32T);
                      TYPE(B64) SRCT(B1T, B64T, B64T);

    INST(CLASS)       SRC_TYPE(F32) SRCT(F32T, U32T.ADDL(classFlags));
                      SRC_TYPE(F64) SRCT(F64T, U32T.ADDL(classFlags));

    // --------------------------------------------------------------------------------------------------------
    // NB: Test values for Native Floating-Point Operations should not include subnormal values!

    INST(NSIN)        TYPE(F32) SRCT( F32T.NEWL(nfpF32).ADD(-FLOAT_PI  / 2, FLOAT_PI  / 4, (f32_t)(512 * 3.14)) );

    INST(NCOS)        TYPE(F32) SRCT( F32T.NEWL(nfpF32).ADD(-FLOAT_PI  / 2, FLOAT_PI  / 4, (f32_t)(512 * 3.14)) );

    INST(NLOG2)       TYPE(F32) SRCT( F32T.NEWL(nfpF32).ADDL(extraTestsF32) );
                      
    INST(NEXP2)       TYPE(F32) SRCT( F32T.NEWL(nfpF32).ADDL(extraTestsF32) );
                      
    INST(NSQRT)       TYPE(F32) SRCT( F32T.NEWL(nfpF32).ADDL(extraTestsF32) );
                      TYPE(F64) SRCT( F64T.NEWL(nfpF64).ADDL(extraTestsF64) );

    INST(NRSQRT)      TYPE(F32) SRCT( F32T.NEWL(nfpF32).ADDL(extraTestsF32) );
                      TYPE(F64) SRCT( F64T.NEWL(nfpF64).ADDL(extraTestsF64) );

    INST(NRCP)        TYPE(F32) SRCT( F32T.NEWL(nfpF32).ADDL(extraTestsF32) );
                      TYPE(F64) SRCT( F64T.NEWL(nfpF64).ADDL(extraTestsF64) );

    INST(NFMA)        TYPE(F32) SRCT( F32T.NEWL(nfpF32).ADDL(extraTestsF32), F32T.NEWL(nfpF32).ADDL(extraTestsF32), F32T.NEWL(nfpF32).ADDL(extraTestsF32) );
                      TYPE(F64) SRCT( F64T.NEWL(nfpF64).ADDL(extraTestsF64), F64T.NEWL(nfpF64).ADDL(extraTestsF64), F64T.NEWL(nfpF64).ADDL(extraTestsF64) );

    // --------------------------------------------------------------------------------------------------------

    INST(BITALIGN)    SRC_TYPE(B32) SRCT( B32T.NEW(0xFFFFFFFF, 0xF0F0F0F0, 0xA0A0A0A),
                                          B32T.NEW(0xFFFFFFFF, 0xF0F0F0F0, 0xA0A0A0A),
                                          B32T.NEW(0, 1, 7, 8, 15).ADD(16, 31, 33, -1)  
                                        );

    INST(BYTEALIGN)   SRC_TYPE(B32) SRCT( B32T.NEW(0xFFFFFFFF, 0xF0F0F0F0, 0xA0A0A0A),
                                          B32T.NEW(0xFFFFFFFF, 0xF0F0F0F0, 0xA0A0A0A),
                                          B32T.NEW(0, 1, 3, 4, 7).ADD(8, 12, -1)    
                                        );

  //INST(LERP)        // NB: packed types
  //INST(SAD)         // NB: packed types
  //INST(SADHI)       // NB: packed types
  //INST(PACKCVT)     // NB: packed types
  //INST(UNPACKCVT)   // NB: packed types

  //INST(SEGMENTP)    // NB: not testable
  //INST(FTOS)        // NB: not testable
  //INST(STOF)        // NB: not testable

    INST(CMP)         SRC_TYPE(B1)
                      SRC_TYPE(B32)
                      SRC_TYPE(B64)
                      SRC_TYPE(S32)
                      SRC_TYPE(S64)
                      SRC_TYPE(U32)
                      SRC_TYPE(U64) SRCN(2);
                      SRC_TYPE(F32) SRCT( F32T.ADDL(extraSubnormF32), F32T.ADDL(extraSubnormF32) );
                      SRC_TYPE(F64) SRCT( F64T.ADDL(extraSubnormF64), F64T.ADDL(extraSubnormF64) );

    INST(CVT)         SRC_TYPE(B1)
                      SRC_TYPE(S8)
                      SRC_TYPE(S16)
                      SRC_TYPE(S32)
                      SRC_TYPE(S64)
                      SRC_TYPE(U8)
                      SRC_TYPE(U16)
                      SRC_TYPE(U32)
                      SRC_TYPE(U64) SRCN(1);
                      SRC_TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(extraSubnormF32) );
                      SRC_TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(extraSubnormF64) );

    INST(LD)          TYPE(S8)  SRCT(  S8T.NEW (0, MAX_S8,  -1, MIN_S8 )   );
                      TYPE(S16) SRCT(  S16T.NEW(0, MAX_S16, -1, MIN_S16)   );
                      TYPE(S32) SRCT(  S32T.NEW(0, MAX_S32             )   );
                      TYPE(S64) SRCT(  S64T.NEW(0, MAX_S64             )   );
                      TYPE(U8)  SRCT(  U8T.NEW (0, MAX_U8              )   );
                      TYPE(U16) SRCT(  U16T.NEW(0, MAX_U16)   );
                      TYPE(U32) SRCT(  U32T.NEW(0, MAX_U32)   );
                      TYPE(U64) SRCT(  U64T.NEW(0, MAX_U64)   );
                      TYPE(F32) SRCT(  F32T.NEW(0, FLOAT_PI)  );
                      TYPE(F64) SRCT(  F64T.NEW(0, DOUBLE_PI) );
                    //TYPE(B128)

    INST(ST)          TYPE(S8)  SRCT(0, S8T.NEW (0, MAX_S8,  -1), S8T.NEW(1, MIN_S8)      );
                      TYPE(S16) SRCT(0, S16T.NEW(0, MAX_S16, -1), S16T.NEW(1, MIN_S16)    );
                      TYPE(S32) SRCT(0, S32T.NEW(0, MAX_S32),     S32T.NEW(1, MIN_S32)    );
                      TYPE(S64) SRCT(0, S64T.NEW(0, MAX_S64),     S64T.NEW(1, MIN_S64)    );
                      TYPE(U8)  SRCT(0, U8T.NEW (0, MAX_U8),      U8T.NEW(1, MID_U8)      );
                      TYPE(U16) SRCT(0, U16T.NEW(0, MAX_U16),     U16T.NEW(1, MID_U16)    );
                      TYPE(U32) SRCT(0, U32T.NEW(0, MAX_U32),     U32T.NEW(1, MID_U32)    );
                      TYPE(U64) SRCT(0, U64T.NEW(0, MAX_U64),     U64T.NEW(1, MID_U64)    );
                      TYPE(F32) SRCT(0, F32T.NEW(0, FLOAT_PI),    F32T.NEW(1, FLOAT_NAN)  );
                      TYPE(F64) SRCT(0, F64T.NEW(0, DOUBLE_PI),   F64T.NEW(1, DOUBLE_NAN) );
                    //TYPE(B128)

    INST(ATOMIC)      TYPE(B32)
                      TYPE(B64)
                      TYPE(S32)
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64) SRCN(srcNum);

    INST(ATOMICNORET) TYPE(B32)
                      TYPE(B64)
                      TYPE(S32)
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64) SRCN(srcNum, 0);

  //INST(RDIMAGE)
  //INST(LDIMAGE)
  //INST(STIMAGE)
  //INST(ATOMICIMAGE)
  //INST(ATOMICIMAGENORET)
  //INST(QUERY*)

  //INST(CBR)
  //INST(BRN)

  //INST(BARRIER)
  //INST(FBAR*)

  //INST(SYNC)
  //INST(*LANE)
  //INST(CALL)
  //INST(RET)
  //INST(SYSCALL)
  //INST(ALLOCA)
  //INST(*)

    END_TEST_DATA

