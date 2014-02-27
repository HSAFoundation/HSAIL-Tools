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
// This file defines test data for each HSAIL instruction.
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

static const f32_t FLOAT_MIN  = numeric_limits<float>::min();
static const f64_t DOUBLE_MIN = numeric_limits<double>::min();

static const f32_t extraTestsF32[] = {-10.00f, -10.25f, -10.50f, -10.75f, 10.00f,  10.25f,  10.50f,  10.75f};
static const f64_t extraTestsF64[] = {-10.00,  -10.25,  -10.50,  -10.75,  10.00,   10.25,   10.50,   10.75};

static const f32_t roundTestsF32[] = {-2.50f, -1.50f, -0.75f, -0.50000005f,        -0.50f, -0.25f, 0.25f, 0.50f, 0.50000005f,        0.75f, 1.50f, 1.5000001f,         2.5f };
static const f64_t roundTestsF64[] = {-2.50,  -1.50,  -0.75,  -0.5000000000000001, -0.50,  -0.25,  0.25,  0.50,  0.5000000000000001, 0.75,  1.50,  1.5000000000000002, 2.5 };

static const f32_t extraSubnormF32[] = {-FLOAT_DENORM  * 512, FLOAT_DENORM};
static const f64_t extraSubnormF64[] = {-DOUBLE_DENORM * 512, DOUBLE_DENORM};

// Test values for Native Floating-Point Operations (should not include subnormals)
static const f32_t nfpF32[] = {-FLOAT_INF,  -FLOAT_PI,  -1, -0.0, +0.0, 1, FLOAT_PI,  FLOAT_INF,  FLOAT_NAN};
static const f64_t nfpF64[] = {-DOUBLE_INF, -DOUBLE_PI, -1, -0.0, +0.0, 1, DOUBLE_PI, DOUBLE_INF, DOUBLE_NAN};

static const u32_t classFlags[] = {0, 0xFFFFFFFF, 0x001, 0x002, 0x004, 0x008, 0x010, 0x020, 0x040, 0x080, 0x100, 0x200};

static const s32_t s24Tests[] = {-0x400000, -0x3FFFFF, 0xABCDE, 0x3FFFFF};
static const u32_t u24Tests[] = {0xABCDE, 0x7FFFFF};

// Values to test ftz with dst (applies to add, sub, mul, div, fma, cvt)
static const f32_t dstFtzF32[] = {FLOAT_MIN  * 1.001f, FLOAT_MIN  * 1.002f, -FLOAT_MIN  * 1.003f, -FLOAT_MIN  * FLOAT_PI,  2.0f, 5.0f, 0.5f, 0.2f};
static const f64_t dstFtzF64[] = {DOUBLE_MIN * 1.001,  DOUBLE_MIN * 1.002,  -DOUBLE_MIN * 1.003,  -DOUBLE_MIN * DOUBLE_PI, 2.0,  5.0,  0.5,  0.2};

// Normalized value that gets subnormal after conversion form f64 to f32
static const f64_t ftzCvt64to32 = DOUBLE_MIN * 1.0e+265; // 2.22507e-43 (min_float is 1.17549e-038)

//=================================================================================================
//=================================================================================================
//=========================     PACKED TEST DATA FOR SPECIAL CASES      ===========================
//=================================================================================================
//=================================================================================================

// Create a test value that look like this:
//
//        s8x4 (   4,   3,   2,   1)    // sign = 1
//        s8x4 (  -4,  -3,  -2,  -1)    // sign = -1
//
#define ITESTBITS1(type, sign) NEW(fill_##type(1 * sign))
#define FTESTBITS1(type, sign) NEW(fill_##type(1.111f * sign))

// Create a pair of test values that look like this:
//
//        s8x4 (  -4,  -3,  -2,  -1), s8x4 (   4,   3,   2,   1) 
//
#define ITESTBITS2(type) NEW(fill_##type(-1),      fill_##type(1)     )
#define FTESTBITS2(type) NEW(fill_##type(-1.111f), fill_##type(0.111f))

// Create 16 test values for selecting elements. These values will look like this:
//
//        s8x4 (   0,   0,   0,   0) 
//        s8x4 (  -1,  -1,  -1,  -1), 
//        ...
//        s8x4 (   0,   0,   0,   1) 
//        s8x4 (   0,   0,   1,   0) 
//        s8x4 (   0,   1,   0,   0) 
//        s8x4 (   1,   0,   0,   0) 
//
// NB: depending on type, this list may include identical values. They will be removed automatically.
//
#define ICTLBITS(type)    NEW(fill_##type(-1, 0x00000000), fill_##type(-1, 0xFFFFFFFF)) \
                         .ADD(fill_##type(-1, 0x1248), fill_##type(-1, 0x36FA), fill_##type(-1, 0xC576), fill_##type(-1, 0xD9BE)) \
                         .ADD(fill_##type(-1, 0x0001), fill_##type(-1, 0x0002), fill_##type(-1, 0x0004), fill_##type(-1, 0x0008)) \
                         .ADD(fill_##type(-1, 0x0010), fill_##type(-1, 0x0020), fill_##type(-1, 0x0040), fill_##type(-1, 0x0080)) \
                         .ADD(fill_##type(-1, 0x0100), fill_##type(-1, 0x0200), fill_##type(-1, 0x0400), fill_##type(-1, 0x0800)) \
                         .ADD(fill_##type(-1, 0x1000), fill_##type(-1, 0x2000), fill_##type(-1, 0x4000), fill_##type(-1, 0x8000))


// Values to test ftz with dst (applies to add, sub, mul, div)
//
#define dstFtzF32x2 f32x2(FLOAT_MIN * 1.001f, -FLOAT_MIN * FLOAT_PI * 1.001f), \
                    f32x2(FLOAT_MIN * 1.002f,  FLOAT_MIN * FLOAT_PI * 1.002f), \
                    f32x2(              2.0f,                           5.0f), \
                    f32x2(              0.5f,                           0.2f)
                            
#define dstFtzF32x4 f32x4(FLOAT_MIN * 1.001f, -FLOAT_MIN * FLOAT_PI * 1.001f, FLOAT_MIN * 1.001f, -FLOAT_MIN * FLOAT_PI * 1.001f), \
                    f32x4(FLOAT_MIN * 1.002f,  FLOAT_MIN * FLOAT_PI * 1.002f, FLOAT_MIN * 1.003f,  FLOAT_MIN * FLOAT_PI * 1.003f), \
                    f32x4(              2.0f,                           5.0f,               0.5f,                           0.2f)

#define dstFtzF64x2 f64x2(DOUBLE_MIN * 1.001, -DOUBLE_MIN * DOUBLE_PI * 1.001), \
                    f64x2(DOUBLE_MIN * 1.002,  DOUBLE_MIN * DOUBLE_PI * 1.002), \
                    f64x2(               2.0,                             5.0), \
                    f64x2(               0.5,                             0.2)

//=================================================================================================
//=================================================================================================
//====================     PREDEFINED TEST DATA FOR REGULAR HSAIL TYPES      ======================
//=================================================================================================
//=================================================================================================

#define TEST_DATA_b1_t   {0, 1};
#define TEST_DATA_b8_t   {0, 1, 64, MID_U8,  MAX_U8,  (b8_t)wavesize};
#define TEST_DATA_b16_t  {0, 1, 64, MID_U16, MAX_U16, (b16_t)wavesize};
#define TEST_DATA_b32_t  {0, 1, 64, MID_U32, MAX_U32, (b32_t)wavesize};
#define TEST_DATA_b64_t  {0, 1, 64, MID_U64, MAX_U64, (b64_t)wavesize};
#define TEST_DATA_b128_t {b128(0, 0), b128(0, MAX_U64), b128(MAX_U64, 0), b128(MAX_U16, MAX_U8), b128(wavesize, 0)};
                        
#define TEST_DATA_u8_t   {0, 1, 64, MID_U8,  MAX_U8,  (u8_t)wavesize};
#define TEST_DATA_u16_t  {0, 1, 64, MID_U16, MAX_U16, (u16_t)wavesize};
#define TEST_DATA_u32_t  {0, 1, 64, MID_U32, MAX_U32, (u32_t)wavesize};
#define TEST_DATA_u64_t  {0, 1, 64, MID_U64, MAX_U64, (u64_t)wavesize};
                         
#define TEST_DATA_s8_t   {MIN_S8,  -64, -1, 0, 1, 64, MAX_S8,  (s8_t)wavesize};
#define TEST_DATA_s16_t  {MIN_S16, -64, -1, 0, 1, 64, MAX_S16, (s16_t)wavesize};
#define TEST_DATA_s32_t  {MIN_S32, -64, -1, 0, 1, 64, MAX_S32, (s32_t)wavesize};
#define TEST_DATA_s64_t  {MIN_S64, -64, -1, 0, 1, 64, MAX_S64, (s64_t)wavesize};
                         
#define TEST_DATA_f32_t  {-FLOAT_INF,  -FLOAT_PI,  -1.0f, -0.0f, +0.0f, 1.0f, FLOAT_PI,  FLOAT_INF,  FLOAT_NAN,  -FLOAT_DENORM  * 256, FLOAT_DENORM  * 256};
#define TEST_DATA_f64_t  {-DOUBLE_INF, -DOUBLE_PI, -1.0,  -0.0,  +0.0,  1.0,  DOUBLE_PI, DOUBLE_INF, DOUBLE_NAN, -DOUBLE_DENORM * 256, DOUBLE_DENORM * 256};

//=================================================================================================
//=================================================================================================
//====================     PREDEFINED TEST DATA FOR PACKED HSAIL TYPES      =======================
//=================================================================================================
//=================================================================================================

#define TEST_DATA_s8x4_t  { s8x4(    0,   63,   30,  127), \
                            s8x4(   -1,    1,   64,    1), \
                            s8x4( -128, -128,   -1,   -3), \
                            s8x4(  -15,   -1,   15,    5), \
                            s8x4(    1,  127,    0,  -70), \
                            s8x4(  -63,   50,   -3,   70)  };
                            
#define TEST_DATA_s8x8_t  { s8x8 (    0,    7,   64,  127, -128,   -9,   -1,   -3), \
                            s8x8 (   -1,    1,   21,    1,   -1,   -1,   15,    5), \
                            s8x8 ( -128,  127, -127,   64,   63,   10,   33,  -70), \
                            s8x8 (    1,   -1,  127,  -64,  -63,  -10,   70,   70)  };
                                                                              
#define TEST_DATA_s8x16_t { s8x16(   20,  -11,  104,  127,    9,   11,   71,    9,    0,    1,   64,  127, -128,   -1,   -1,   -3), \
                            s8x16(  -11,   15,   -9,  -18,   17,   76,   -7,  -55,   -1,    7,   63,    1,   -1,  -19,   15,    5), \
                            s8x16( -100,   98, -113,   21,  101,   19,   91,   12, -128,  127, -127,   64,   63,   10,  117,  -70), \
                            s8x16(   -1,   13,   27,  -11,  -93,  -11,  -37,   79,    1,   -1,  127,  -64,  -63,  -10,   73,   70)  };
                            
#define TEST_DATA_s16x2_t { s16x2(      0,  16383), \
                            s16x2(     -1,      1), \
                            s16x2( -32768, -32768), \
                            s16x2(    -15,     -1), \
                            s16x2(      1,   -769), \
                            s16x2( -32767,  32767), \
                            s16x2(   5973,  -2751), \
                            s16x2(  16384,     11), \
                            s16x2(    -19,     -3), \
                            s16x2(    113,      5), \
                            s16x2(      0, -20000), \
                            s16x2(     -3,   6945)  };

#define TEST_DATA_s16x4_t { s16x4(      0,  16383,  16384,  32767), \
                            s16x4(     -1,      1,   7411,      1), \
                            s16x4( -32768, -32768,     -1,     -9), \
                            s16x4(    -15,     -1,    115,      5), \
                            s16x4(      1,    111,      0, -20000), \
                            s16x4( -32767,  32767,     -3,   3491)  };

#define TEST_DATA_s16x8_t { s16x8(      0,    119,   1791,  32767, -32768,   -117,     -1,     -3), \
                            s16x8(     -1,      1,  16384,      1,     -1,     -1,     15,     55), \
                            s16x8( -32768,  32767, -32767,  16384,  16383,     10,    811, -20000), \
                            s16x8(      1,     -1,  32767, -16384, -16383,    -10,  20199,  20000)  };

#define TEST_DATA_s32x2_t { s32x2(          0, 0x3FFFFFFF), \
                            s32x2(         -1,          1), \
                            s32x2( 0x89ABCDEF, 0x80000000), \
                            s32x2(        -15,         -1), \
                            s32x2(          1,     0x789F), \
                            s32x2( 0x80000000, 0xF9876543), \
                            s32x2(    0x45678, 0x7FFFFFFF), \
                            s32x2( 0x40000000,       2871), \
                            s32x2(      -9171,         -3), \
                            s32x2(         15,        276), \
                            s32x2(          0, 0x70000000), \
                            s32x2(         -3, 0x90000000)  };

#define TEST_DATA_s32x4_t { s32x4(          0, 0x3FFFFFFF, 0x40000000, 0x7FFFFFFF), \
                            s32x4(         -1,          1,      62765,          1), \
                            s32x4( 0x80000000, 0x80000000,         -1,         -3), \
                            s32x4(        -15,         -1,         15,          5), \
                            s32x4(          1, 0xFFFF1234,          0, 0x90000000), \
                            s32x4(      0x7FF, 0x7FFFFFFF,         -3, 0x70000000)  };

#define TEST_DATA_s64x2_t { s64x2(                    0, 0x3FFFFFFFFFFFFFFFLL), \
                            s64x2(                   -1,                26573), \
                            s64x2( 0x8000000ABCDEF000LL, 0x8000000000000000LL), \
                            s64x2(                  -15,                   -1), \
                            s64x2(                    1, 0x7FFFFFFFFFFFFFFFLL), \
                            s64x2( 0x8000000000000000LL, 0xF123456789012345LL), \
                            s64x2( 0x4134256789162653LL,              0x7FFLL), \
                            s64x2( 0x4000000000000000LL,                    1), \
                            s64x2(           -365476781,                   -3), \
                            s64x2(                   15,                    5), \
                            s64x2(                 2271, 0x7187364755267483LL), \
                            s64x2(                   -3, 0x90000000FFFFFFFFLL)  };
                            
#define TEST_DATA_u8x4_t  { u8x4 (   0,   5, 128, 127), \
                            u8x4 ( 128, 255,  15,  16), \
                            u8x4 ( 255,   1,  64,  63), \
                            u8x4 (   1,   0,  16,  15), \
                            u8x4 ( 127, 130, 128,  70), \
                            u8x4 (  16,  15,   5, 176)  };
                            
#define TEST_DATA_u8x8_t  { u8x8 ( 128,   5,  64, 127, 255,  65,  15,  16), \
                            u8x8 ( 255,   1,  63,  63,   1,   0,  16,  15), \
                            u8x8 ( 127,  70,   1,   5,  55,  63, 255, 176)  };
                            
#define TEST_DATA_u8x16_t { u8x16(   5, 128, 164,   7, 127,  21,  15,  16,   0,   5,  64, 127, 255,  65,  15,  16), \
                            u8x16(  55,  21,   4,  63,  21,   9, 116, 215, 255,   1,  31,  63,   1,   0,  16,  15), \
                            u8x16(  17, 127, 111,  15, 127,  63, 200,  76, 127,  70,   1,   5,  35,  63, 255, 176)  };

#define TEST_DATA_u16x2_t { u16x2(      0,      5), \
                            u16x2( 0x8000, 0xFFFF), \
                            u16x2( 0xFFFF,      1), \
                            u16x2(      1,      0), \
                            u16x2( 0x7FFF, 0x8500), \
                            u16x2(     16,     15), \
                            u16x2( 0x8FFF, 0x7FFF), \
                            u16x2(     15,     16), \
                            u16x2( 0x4000, 0x3FFF), \
                            u16x2(    919,    215), \
                            u16x2( 0x8000, 0x5000), \
                            u16x2(     75, 0xC000)  };

#define TEST_DATA_u16x4_t { u16x4(      0,      5, 0x8000, 0x7FFF), \
                            u16x4( 0x8000, 0xFFFF,     15,     16), \
                            u16x4( 0xFFFF,      1, 0x4000, 0x3FFF), \
                            u16x4(      1,      0,     16,     15), \
                            u16x4( 0x7FFF, 0x8500, 0x8FFF, 0x5000), \
                            u16x4(     16,     15,      5, 0xC000)  };

#define TEST_DATA_u16x8_t { u16x8(      0,   0x80,  0x800,   0x7F,      0,      5, 0x8000, 0x7FFF), \
                            u16x8( 0x7FFF,   0xFF,    150,     16, 0x8000, 0xFFFF,     15,     16), \
                            u16x8( 0x8000,      1,  0x400,   0x3F, 0xFFFF,      1, 0x4000, 0x3FFF), \
                            u16x8( 0x8FFF,      0,    160,     15,      1,      0,     16,     15), \
                            u16x8( 0x7FFF, 0x8500,  0xABC,   0x50, 0x7FFF, 0x8500, 0x1234, 0x5000), \
                            u16x8(     16,   0xF1,      5,   0xC0,     16,     15,      5, 0xC000)  };

#define TEST_DATA_u32x2_t { u32x2(          0,          5), \
                            u32x2( 0x80000000, 0xFFFFFFFF), \
                            u32x2( 0xFFFFFFFF,          1), \
                            u32x2(          1,          0), \
                            u32x2( 0x7FFFFFFF, 0x85000000), \
                            u32x2(         16,         15), \
                            u32x2( 0x8FFFFFFF, 0x7FFFFFFF), \
                            u32x2(         15,         16), \
                            u32x2( 0x40000000, 0x3FFFFFFF), \
                            u32x2(      0x567,     0x9876), \
                            u32x2( 0xF1234567, 0x50000000), \
                            u32x2(          5, 0xC0000000)  };

#define TEST_DATA_u32x4_t { u32x4(          0,          5, 0x80000000, 0x7FFFFFFF), \
                            u32x4( 0x80000000, 0xFFFFFFFF,         15,         16), \
                            u32x4( 0xFFFFFFFF,          1, 0x40000000, 0x3FFFFFFF), \
                            u32x4(          1,          0,         16,         15), \
                            u32x4( 0x7FFFFFFF, 0x85000000, 0xFFFF0000,      0x512), \
                            u32x4(         16,         15,          5, 0xC0000000)  };

#define TEST_DATA_u64x2_t { u64x2(                     0,                     5), \
                            u64x2( 0x8000000000000000ULL, 0xFFFFFFFFFFFFFFFFULL), \
                            u64x2( 0xFFFFFFFFFFFFFFFFULL,                     1), \
                            u64x2(                     1,                     0), \
                            u64x2( 0x7FFFFFFFFFFFFFFFULL, 0x8500000000000000ULL), \
                            u64x2(                    16,                    15), \
                            u64x2( 0x8FFFFFFFFFFFFFFFULL, 0x7FFFFFFFFFFFFFFFULL), \
                            u64x2(         0xF1F3F4F5ULL,                    16), \
                            u64x2( 0x4000000000000000ULL, 0x3FFFFFFFFFFFFFFFULL), \
                            u64x2(            0xFABC6ULL,        0xAFAF1F1F2ULL), \
                            u64x2( 0xF1F2F3F4F5F6F7F8ULL, 0x5000000000000000ULL), \
                            u64x2(                   255, 0xC000000000000000ULL)  };
                            
//#define TEST_DATA_f16x2_t  {0}; ///F
//#define TEST_DATA_f16x4_t  {0}; ///F
//#define TEST_DATA_f16x8_t  {0}; ///F

#define TEST_DATA_f32x2_t { f32x2(-2.50f,       -FLOAT_INF         ), \
                            f32x2(-1.50f,       -FLOAT_PI          ), \
                            f32x2(-0.75f,       -1.0f              ), \
                            f32x2(-0.50000005f, -0.0f              ), \
                            f32x2(-0.50f,       +0.0f              ), \
                            f32x2(-0.25f,       1.0f               ), \
                            f32x2(0.25f,        FLOAT_PI           ), \
                            f32x2(0.50f,        FLOAT_INF          ), \
                            f32x2(0.50000005f,  FLOAT_NAN          ), \
                            f32x2(0.75f,        -FLOAT_DENORM * 64 ), \
                            f32x2(1.50f,        FLOAT_DENORM  * 64 ), \
                            f32x2(1.5000001f,   -FLOAT_DENORM * 512), \
                            f32x2(2.5f,         FLOAT_DENORM       )  };
                            
#define TEST_DATA_f32x4_t { f32x4(-10.00f,     (float)(1103  / 13.0), -2.50f,       -FLOAT_INF         ), \
                            f32x4(-10.25f,     (float)(2053  / 17.0), -1.50f,       -FLOAT_PI          ), \
                            f32x4(-10.50f,     (float)(3571  / 19.0), -0.75f,       -1.0f              ), \
                            f32x4(-10.75f,     (float)(-1163 / 23.0), -0.50000005f, -0.0f              ), \
                            f32x4( 10.00f,     (float)(-2213 / 29.0), -0.50f,       +0.0f              ), \
                            f32x4( 10.25f,     (float)(-2549 / 31.0), -0.25f,       1.0f               ), \
                            f32x4( 10.50f,     FLOAT_PI,              0.25f,        FLOAT_PI           ), \
                            f32x4( 10.75f,     FLOAT_INF,             0.50f,        FLOAT_INF          ), \
                            f32x4(0.50000005f, FLOAT_NAN,             0.50000005f,  FLOAT_NAN          ), \
                            f32x4(1.50f,       FLOAT_DENORM * 64,     0.75f,        -FLOAT_DENORM * 64 ), \
                            f32x4(1.5000001f,  -FLOAT_DENORM  * 512,  2.5f,         FLOAT_DENORM       )  };

#define TEST_DATA_f64x2_t { f64x2(-2.50,               -DOUBLE_INF         ), \
                            f64x2(-1.50,               -DOUBLE_PI          ), \
                            f64x2(-0.75,               -1.0f               ), \
                            f64x2(-0.5000000000000001, -0.0f               ), \
                            f64x2(-0.50,               +0.0f               ), \
                            f64x2(-0.25,               1.0f                ), \
                            f64x2(0.25,                DOUBLE_PI           ), \
                            f64x2(0.50,                DOUBLE_INF          ), \
                            f64x2(0.5000000000000001,  DOUBLE_NAN          ), \
                            f64x2(0.75,                -DOUBLE_DENORM * 64 ), \
                            f64x2(1.50,                DOUBLE_DENORM  * 64 ), \
                            f64x2(1.5000000000000002,  -DOUBLE_DENORM * 512), \
                            f64x2(2.5,                 DOUBLE_DENORM       )  };

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
//                  NEW(val1, val2, ...) - create a new test set of the same type with 
//                                         values val1, val2, ...
//
//              Examples:
//
//                  SRCN(2);           // 2 src arguments; default test data type and values
//                  SRCT(S32.ADD(7));  // 1 src argument with test set based on S32 
//                                     // with additional value "7"
//                  SRCT(S32.NEW(7));  // 1 source argument of type s32 with 1 value "7" 
//
//=================================================================================================

// NB: The following list includes all standard HSAIL instructions and types of their operands.
// NB: Instructions and types not supported yet by LUA extension are commented out
//     (except for f16, image and sampler types which are not shown). 

BEGIN_TEST_DATA

    INST(ADD)         TYPE(S32)
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64)   SRCN(2);
                      TYPE(F32)   SRCT( F32T.ADDL(dstFtzF32), F32T.ADDL(dstFtzF32) );
                      TYPE(F64)   SRCT( F64T.ADDL(dstFtzF64), F64T.ADDL(dstFtzF64) );
                      SXTYPES     SRCN(2);
                      UXTYPES     SRCN(2);
                      TYPE(F32X2) SRCT( F32X2T.ADD(dstFtzF32x2), F32X2T.ADD(dstFtzF32x2) );
                      TYPE(F32X4) SRCT( F32X4T.ADD(dstFtzF32x4), F32X4T.ADD(dstFtzF32x4) );
                      TYPE(F64X2) SRCT( F64X2T.ADD(dstFtzF64x2), F64X2T.ADD(dstFtzF64x2) );

    INST(SUB)         TYPE(S32)
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64)   SRCN(2);
                      TYPE(F32)   SRCT( F32T.ADDL(dstFtzF32), F32T.ADDL(dstFtzF32) );
                      TYPE(F64)   SRCT( F64T.ADDL(dstFtzF64), F64T.ADDL(dstFtzF64) );
                      SXTYPES     SRCN(2);
                      UXTYPES     SRCN(2);
                      TYPE(F32X2) SRCT( F32X2T.ADD(dstFtzF32x2), F32X2T.ADD(dstFtzF32x2) );
                      TYPE(F32X4) SRCT( F32X4T.ADD(dstFtzF32x4), F32X4T.ADD(dstFtzF32x4) );
                      TYPE(F64X2) SRCT( F64X2T.ADD(dstFtzF64x2), F64X2T.ADD(dstFtzF64x2) );

    INST(MAX)         TYPE(S32)
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64)
                      TYPE(F32)
                      TYPE(F64)
                      XTYPES    SRCN(2);

    INST(MIN)         TYPE(S32)             
                      TYPE(S64)             
                      TYPE(U32)
                      TYPE(U64)
                      TYPE(F32)
                      TYPE(F64)
                      XTYPES    SRCN(2);

    INST(MUL)         TYPE(S32)
                      TYPE(S64)
                      TYPE(U32)
                      TYPE(U64)   SRCN(2);
                      TYPE(F32)   SRCT( F32T.ADDL(dstFtzF32), F32T.ADDL(dstFtzF32) );
                      TYPE(F64)   SRCT( F64T.ADDL(dstFtzF64), F64T.ADDL(dstFtzF64) );
                      SXTYPES     SRCN(2);
                      UXTYPES     SRCN(2);
                      TYPE(F32X2) SRCT( F32X2T.ADD(dstFtzF32x2), F32X2T.ADD(dstFtzF32x2) );
                      TYPE(F32X4) SRCT( F32X4T.ADD(dstFtzF32x4), F32X4T.ADD(dstFtzF32x4) );
                      TYPE(F64X2) SRCT( F64X2T.ADD(dstFtzF64x2), F64X2T.ADD(dstFtzF64x2) );

    INST(MULHI)       TYPE(S32)
                      TYPE(S64)
                      TYPE(U32) 
                      TYPE(U64)
                      SXTYPES
                      UXTYPES   SRCN(2);

    INST(DIV)         TYPE(S32)   SRCT( S32T.ADD(-63, 127), S32T.ADD(-15, 30) );
                      TYPE(S64)   SRCT( S64T.ADD(-63, 127), S64T.ADD(-15, 30) );
                      TYPE(U32)   SRCT( U32T.ADD(     127), U32T.ADD(     30) );
                      TYPE(U64)   SRCT( U64T.ADD(     127), U64T.ADD(     30) );
                      TYPE(F32)   SRCT( F32T.ADDL(dstFtzF32), F32T.ADDL(dstFtzF32) );
                      TYPE(F64)   SRCT( F64T.ADDL(dstFtzF64), F64T.ADDL(dstFtzF64) );
                      TYPE(F32X2) SRCT( F32X2T.ADD(dstFtzF32x2), F32X2T.ADD(dstFtzF32x2) );
                      TYPE(F32X4) SRCT( F32X4T.ADD(dstFtzF32x4), F32X4T.ADD(dstFtzF32x4) );
                      TYPE(F64X2) SRCT( F64X2T.ADD(dstFtzF64x2), F64X2T.ADD(dstFtzF64x2) );

    INST(REM)         TYPE(S32) SRCT( S32T.ADD(-63, 127), S32T.ADD(-15, 30) );
                      TYPE(S64) SRCT( S64T.ADD(-63, 127), S64T.ADD(-15, 30) );
                      TYPE(U32) SRCT( U32T.ADD(     127), U32T.ADD(     30) );
                      TYPE(U64) SRCT( U64T.ADD(     127), U64T.ADD(     30) );

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
                      TYPE(F64)
                      SXTYPES
                      FXTYPES   SRCN(1);

    INST(ABS)         TYPE(S32)
                      TYPE(S64)
                      TYPE(F32)
                      TYPE(F64)
                      SXTYPES
                      FXTYPES   SRCN(1);

    INST(COPYSIGN)    TYPE(F32)
                      TYPE(F64)
                      FXTYPES   SRCN(2);

    INST(FRACT)       TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(roundTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(roundTestsF64) );
                      FXTYPES   SRCN(1);

    INST(SQRT)        TYPE(F32) SRCT( F32T.ADDL(extraTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64) );
                      FXTYPES   SRCN(1);

    INST(CEIL)        TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(roundTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(roundTestsF64) );
                      FXTYPES   SRCN(1);

    INST(FLOOR)       TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(roundTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(roundTestsF64) );
                      FXTYPES   SRCN(1);

    INST(RINT)        TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(roundTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(roundTestsF64) );
                      FXTYPES   SRCN(1);

    INST(TRUNC)       TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(roundTestsF32) );
                      TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(roundTestsF64) );
                      FXTYPES   SRCN(1);

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

    INST(FMA)         TYPE(F32) SRCT( F32T.ADDL(dstFtzF32), F32T.ADDL(dstFtzF32), F32T );
                      TYPE(F64) SRCT( F64T.ADDL(dstFtzF64), F64T.ADDL(dstFtzF64), F64T );

    INST(SHL)         TYPE(S32)   SRCT( S32T,   U32T.ADD(2, 31, 32, 33) ); // NB: src2 is always u32
                      TYPE(S64)   SRCT( S64T,   U32T.ADD(2, 63, 64, 65) );
                      TYPE(U32)   SRCT( U32T,   U32T.ADD(2, 31, 32, 33) );
                      TYPE(U64)   SRCT( U64T,   U32T.ADD(2, 63, 64, 65) );
                      TYPE(S8X4)  SRCT( S8X4T,  U32T.ADD(2,  7,  8,  9) );
                      TYPE(S8X8)  SRCT( S8X8T,  U32T.ADD(2,  7,  8,  9) );
                      TYPE(S8X16) SRCT( S8X16T, U32T.ADD(2,  7,  8,  9) );
                      TYPE(S16X2) SRCT( S16X2T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(S16X4) SRCT( S16X4T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(S16X8) SRCT( S16X8T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(S32X2) SRCT( S32X2T, U32T.ADD(2, 31, 32, 33) );
                      TYPE(S32X4) SRCT( S32X4T, U32T.ADD(2, 31, 32, 33) );
                      TYPE(S64X2) SRCT( S64X2T, U32T.ADD(2, 63, 64, 65) );
                      TYPE(U8X4)  SRCT( U8X4T,  U32T.ADD(2,  7,  8,  9) );
                      TYPE(U8X8)  SRCT( U8X8T,  U32T.ADD(2,  7,  8,  9) );
                      TYPE(U8X16) SRCT( U8X16T, U32T.ADD(2,  7,  8,  9) );
                      TYPE(U16X2) SRCT( U16X2T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(U16X4) SRCT( U16X4T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(U16X8) SRCT( U16X8T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(U32X2) SRCT( U32X2T, U32T.ADD(2, 31, 32, 33) );
                      TYPE(U32X4) SRCT( U32X4T, U32T.ADD(2, 31, 32, 33) );
                      TYPE(U64X2) SRCT( U64X2T, U32T.ADD(2, 63, 64, 65) );

    INST(SHR)         TYPE(S32)   SRCT( S32T,   U32T.ADD(2, 31, 32, 33) ); // NB: src2 is always u32
                      TYPE(S64)   SRCT( S64T,   U32T.ADD(2, 63, 64, 65) );
                      TYPE(U32)   SRCT( U32T,   U32T.ADD(2, 31, 32, 33) );
                      TYPE(U64)   SRCT( U64T,   U32T.ADD(2, 63, 64, 65) );
                      TYPE(S8X4)  SRCT( S8X4T,  U32T.ADD(2,  7,  8,  9) );
                      TYPE(S8X8)  SRCT( S8X8T,  U32T.ADD(2,  7,  8,  9) );
                      TYPE(S8X16) SRCT( S8X16T, U32T.ADD(2,  7,  8,  9) );
                      TYPE(S16X2) SRCT( S16X2T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(S16X4) SRCT( S16X4T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(S16X8) SRCT( S16X8T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(S32X2) SRCT( S32X2T, U32T.ADD(2, 31, 32, 33) );
                      TYPE(S32X4) SRCT( S32X4T, U32T.ADD(2, 31, 32, 33) );
                      TYPE(S64X2) SRCT( S64X2T, U32T.ADD(2, 63, 64, 65) );
                      TYPE(U8X4)  SRCT( U8X4T,  U32T.ADD(2,  7,  8,  9) );
                      TYPE(U8X8)  SRCT( U8X8T,  U32T.ADD(2,  7,  8,  9) );
                      TYPE(U8X16) SRCT( U8X16T, U32T.ADD(2,  7,  8,  9) );
                      TYPE(U16X2) SRCT( U16X2T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(U16X4) SRCT( U16X4T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(U16X8) SRCT( U16X8T, U32T.ADD(2, 15, 16, 17) );
                      TYPE(U32X2) SRCT( U32X2T, U32T.ADD(2, 31, 32, 33) );
                      TYPE(U32X4) SRCT( U32X4T, U32T.ADD(2, 31, 32, 33) );
                      TYPE(U64X2) SRCT( U64X2T, U32T.ADD(2, 63, 64, 65) );

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

    //NB: Due to 4 arguments, there are lots of test value combinations, so add   values with care!
    INST(BITINSERT)   TYPE(S32) SRCT( S32T.NEW(0xF0F0F0F0, 0xFF00FF) .ADD(wavesize),  
                                      S32T.NEW(0xA251C468, 0xF0F0F0F).ADD(wavesize), 
                                      U32T.NEW(0, 1, 2, 31, 32)      .ADD(wavesize),                        // NB: src3 and src4 are always u32
                                      U32T.NEW(0, 1, 2, 31, 32)      .ADD(wavesize)
                                    );
                      TYPE(S64) SRCT( S64T.NEW(0xF0F0F0F0F0F0F0F0ULL, 0xFF00FF00FF00FFULL) .ADD(wavesize),  
                                      S64T.NEW(0xA251C468A251C468ULL, 0xF0F0F0F0F0F0F0FULL).ADD(wavesize), 
                                      U32T.NEW(0, 1, 2, 63, 64)                            .ADD(wavesize),  // NB: src3 and src4 are always u32
                                      U32T.NEW(0, 1, 2, 63, 64)                            .ADD(wavesize)
                                    );
                      TYPE(U32) SRCT( U32T.NEW(0xF0F0F0F0, 0xFF00FF) .ADD(wavesize),  
                                      U32T.NEW(0xA251C468, 0xF0F0F0F).ADD(wavesize), 
                                      U32T.NEW(0, 1, 2, 31, 32)      .ADD(wavesize),                        // NB: src3 and src4 are always u32
                                      U32T.NEW(0, 1, 2, 31, 32)      .ADD(wavesize)
                                    );
                      TYPE(U64) SRCT( U64T.NEW(0xF0F0F0F0F0F0F0F0ULL, 0xFF00FF00FF00FFULL) .ADD(wavesize),  
                                      U64T.NEW(0xA251C468A251C468ULL, 0xF0F0F0F0F0F0F0FULL).ADD(wavesize), 
                                      U32T.NEW(0, 1, 2, 63, 64)                            .ADD(wavesize),  // NB: src3 and src4 are always u32
                                      U32T.NEW(0, 1, 2, 63, 64)                            .ADD(wavesize)
                                    );

    INST(FIRSTBIT)    SRC_TYPE(S32) SRCT( S32T.ADD(0x7FFFFFFF,            0x1FFFFFFF,            -2) );
                      SRC_TYPE(S64) SRCT( S64T.ADD(0x7FFFFFFFFFFFFFFFULL, 0x1FFFFFFFFFFFFFFFULL, -2) );
                      SRC_TYPE(U32) SRCT( U32T.ADD(0x7FFFFFFF,            0x1FFFFFFF               ) );
                      SRC_TYPE(U64) SRCT( U64T.ADD(0x7FFFFFFFFFFFFFFFULL, 0x1FFFFFFFFFFFFFFFULL    ) );

    INST(LASTBIT)     SRC_TYPE(S32) SRCT( S32T.ADD(0x8, 0xA, -2) );
                      SRC_TYPE(S64) SRCT( S64T.ADD(0x8, 0xA, -2) );
                      SRC_TYPE(U32) SRCT( U32T.ADD(0x8, 0xA    ) );
                      SRC_TYPE(U64) SRCT( U64T.ADD(0x8, 0xA    ) );

    INST(COMBINE)     SRC_TYPE(B32)
                      SRC_TYPE(B64) SRCN(1);
                      
    INST(EXPAND)      SRC_TYPE(B64)
                      SRC_TYPE(B128) SRCN(1);

    INST(MOV)         TYPE(B1)
                      TYPE(B32)
                      TYPE(B64) 
                      TYPE(B128) 
                      TYPE(S32) 
                      TYPE(S64) 
                      TYPE(U32) 
                      TYPE(U64) 
                      TYPE(F32) 
                      TYPE(F64)  SRCN(1);

//INST(LDA)         // NB: not testable
//INST(LDC)         // NB: not testable

  INST(SHUFFLE)       TYPE(S16X2) SRCT( S16X2T.ITESTBITS2(s16x2), S16X2T.ITESTBITS2(s16x2), B32T.NEW(      0x0,      0x1,      0x2,      0x3).ADD(-1).ADD((b32_t)wavesize) );
                      TYPE(U16X2) SRCT( U16X2T.ITESTBITS2(u16x2), U16X2T.ITESTBITS2(u16x2), B32T.NEW(      0x0,      0x1,      0x2,      0x3).ADD(-1).ADD((b32_t)wavesize) );
                      TYPE(S32X2) SRCT( S32X2T.ITESTBITS2(s32x2), S32X2T.ITESTBITS2(s32x2), B64T.NEW(      0x0,      0x1,      0x2,      0x3).ADD(-1).ADD((b64_t)wavesize) );
                      TYPE(U32X2) SRCT( U32X2T.ITESTBITS2(u32x2), U32X2T.ITESTBITS2(u32x2), B64T.NEW(      0x0,      0x1,      0x2,      0x3).ADD(-1).ADD((b64_t)wavesize) );
                      TYPE(F32X2) SRCT( F32X2T.FTESTBITS2(f32x2), F32X2T.FTESTBITS2(f32x2), B64T.NEW(      0x0,      0x1,      0x2,      0x3).ADD(-1).ADD((b64_t)wavesize) );
                      TYPE(S8X4)  SRCT( S8X4T .ITESTBITS2(s8x4),  S8X4T .ITESTBITS2(s8x4),  B32T.NEW(     0x00,     0x46,     0x93,     0x5A).ADD(-1).ADD((b32_t)wavesize) );
                      TYPE(U8X4)  SRCT( U8X4T .ITESTBITS2(u8x4),  U8X4T .ITESTBITS2(u8x4),  B32T.NEW(     0x00,     0x46,     0x93,     0x5A).ADD(-1).ADD((b32_t)wavesize) );
                      TYPE(S16X4) SRCT( S16X4T.ITESTBITS2(s16x4), S16X4T.ITESTBITS2(s16x4), B64T.NEW(     0x00,     0x46,     0x93,     0x5A).ADD(-1).ADD((b64_t)wavesize) );
                      TYPE(U16X4) SRCT( U16X4T.ITESTBITS2(u16x4), U16X4T.ITESTBITS2(u16x4), B64T.NEW(     0x00,     0x46,     0x93,     0x5A).ADD(-1).ADD((b64_t)wavesize) );
                      TYPE(S8X8)  SRCT( S8X8T .ITESTBITS2(s8x8),  S8X8T .ITESTBITS2(s8x8),  B64T.NEW( 0x000000, 0x2C7593, 0xD46E08, 0x13FA1B).ADD(-1).ADD((b64_t)wavesize) );
                      TYPE(U8X8)  SRCT( U8X8T .ITESTBITS2(u8x8),  U8X8T .ITESTBITS2(u8x8),  B64T.NEW( 0xFFFFFF, 0x3D86A4, 0xF35075, 0x5738F4).ADD(-1).ADD((b64_t)wavesize) );

    INST(UNPACKLO)    X32TYPES
                      X64TYPES  SRCN(2);

    INST(UNPACKHI)    X32TYPES
                      X64TYPES  SRCN(2);

    INST(PACK)        SRC_TYPE(S32) 
                            BEGIN_DST
                                DST_TYPE(S8X4)  SRCT( S8X4T .ITESTBITS2(s8x4),  S32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S8X8)  SRCT( S8X8T .ITESTBITS2(s8x8),  S32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S8X16) SRCT( S8X16T.ITESTBITS2(s8x16), S32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 7, 15 ) .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S16X2) SRCT( S16X2T.ITESTBITS2(s16x2), S32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S16X4) SRCT( S16X4T.ITESTBITS2(s16x4), S32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S16X8) SRCT( S16X8T.ITESTBITS2(s16x8), S32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S32X2) SRCT( S32X2T.ITESTBITS2(s32x2), S32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S32X4) SRCT( S32X4T.ITESTBITS2(s32x4), S32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                            END_DST

                      SRC_TYPE(S64)
                            BEGIN_DST
                                DST_TYPE(S8X4)  SRCT( S8X4T .ITESTBITS2(s8x4),  S64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S8X8)  SRCT( S8X8T .ITESTBITS2(s8x8),  S64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S8X16) SRCT( S8X16T.ITESTBITS2(s8x16), S64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 7, 15 ) .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S16X2) SRCT( S16X2T.ITESTBITS2(s16x2), S64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S16X4) SRCT( S16X4T.ITESTBITS2(s16x4), S64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S16X8) SRCT( S16X8T.ITESTBITS2(s16x8), S64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S32X2) SRCT( S32X2T.ITESTBITS2(s32x2), S64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S32X4) SRCT( S32X4T.ITESTBITS2(s32x4), S64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                                DST_TYPE(S64X2) SRCT( S64X2T.ITESTBITS2(s64x2), S64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                            END_DST

                      SRC_TYPE(U32)
                            BEGIN_DST
                                DST_TYPE(U8X4)  SRCT( U8X4T .ITESTBITS2(u8x4),  U32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U8X8)  SRCT( U8X8T .ITESTBITS2(u8x8),  U32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U8X16) SRCT( U8X16T.ITESTBITS2(u8x16), U32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 7, 15 ) .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U16X2) SRCT( U16X2T.ITESTBITS2(u16x2), U32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U16X4) SRCT( U16X4T.ITESTBITS2(u16x4), U32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U16X8) SRCT( U16X8T.ITESTBITS2(u16x8), U32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U32X2) SRCT( U32X2T.ITESTBITS2(u32x2), U32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U32X4) SRCT( U32X4T.ITESTBITS2(u32x4), U32T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                            END_DST

                      SRC_TYPE(U64)
                            BEGIN_DST
                                DST_TYPE(U8X4)  SRCT( U8X4T .ITESTBITS2(u8x4),  U64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U8X8)  SRCT( U8X8T .ITESTBITS2(u8x8),  U64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U8X16) SRCT( U8X16T.ITESTBITS2(u8x16), U64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 7, 15 ) .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U16X2) SRCT( U16X2T.ITESTBITS2(u16x2), U64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U16X4) SRCT( U16X4T.ITESTBITS2(u16x4), U64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U16X8) SRCT( U16X8T.ITESTBITS2(u16x8), U64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U32X2) SRCT( U32X2T.ITESTBITS2(u32x2), U64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U32X4) SRCT( U32X4T.ITESTBITS2(u32x4), U64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                                DST_TYPE(U64X2) SRCT( U64X2T.ITESTBITS2(u64x2), U64T.NEW(-1, 1).ADD(wavesize), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                            END_DST

                      SRC_TYPE(F32)
                            BEGIN_DST
                                DST_TYPE(F32X2) SRCT( F32X2T.FTESTBITS2(f32x2), F32T.NEW(0, 1.127f), U32T.NEW( 0, 1 )       .ADD(-1).ADD(wavesize) );
                                DST_TYPE(F32X4) SRCT( F32X4T.FTESTBITS2(f32x4), F32T.NEW(0, 1.127f), U32T.NEW( 0, 1, 2, 3 ) .ADD(-1).ADD(wavesize) );
                            END_DST

                      SRC_TYPE(F64)
                            BEGIN_DST
                                DST_TYPE(F64X2) SRCT( F64X2T.FTESTBITS2(f64x2), F64T.NEW(0, 1.127), U32T.NEW( 0, 1 )        .ADD(-1).ADD(wavesize) );
                            END_DST


    INST(UNPACK)      SRC_TYPE(S8X4)  SRCT(S8X4T .ITESTBITS2(s8x4),  U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(S8X8)  SRCT(S8X8T .ITESTBITS2(s8x8),  U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(S8X16) SRCT(S8X16T.ITESTBITS2(s8x16), U32T.NEW( 0, 3, 4, 7, 15 ) .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(S16X2) SRCT(S16X2T.ITESTBITS2(s16x2), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(S16X4) SRCT(S16X4T.ITESTBITS2(s16x4), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(S16X8) SRCT(S16X8T.ITESTBITS2(s16x8), U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(S32X2) SRCT(S32X2T.ITESTBITS2(s32x2), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(S32X4) SRCT(S32X4T.ITESTBITS2(s32x4), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(S64X2) SRCT(S64X2T.ITESTBITS2(s64x2), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(U8X4)  SRCT(U8X4T .ITESTBITS2(u8x4),  U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(U8X8)  SRCT(U8X8T .ITESTBITS2(u8x8),  U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(U8X16) SRCT(U8X16T.ITESTBITS2(u8x16), U32T.NEW( 0, 3, 4, 7, 15 ) .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(U16X2) SRCT(U16X2T.ITESTBITS2(u16x2), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(U16X4) SRCT(U16X4T.ITESTBITS2(u16x4), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(U16X8) SRCT(U16X8T.ITESTBITS2(u16x8), U32T.NEW( 0, 3, 4, 5, 7 )  .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(U32X2) SRCT(U32X2T.ITESTBITS2(u32x2), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(U32X4) SRCT(U32X4T.ITESTBITS2(u32x4), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(U64X2) SRCT(U64X2T.ITESTBITS2(u64x2), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(F32X2) SRCT(F32X2T.FTESTBITS2(f32x2), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(F32X4) SRCT(F32X4T.FTESTBITS2(f32x4), U32T.NEW( 0, 1, 2, 3 )     .ADD(-1).ADD(wavesize) );
                      SRC_TYPE(F64X2) SRCT(F64X2T.FTESTBITS2(f64x2), U32T.NEW( 0, 1 )           .ADD(-1).ADD(wavesize) );

    INST(CMOV)        TYPE(B1)    SRCT(B1T, B1T,  B1T);
                      TYPE(B32)   SRCT(B1T, B32T, B32T);
                      TYPE(B64)   SRCT(B1T, B64T, B64T);
                      TYPE(S8X4)  SRCT( U8X4T .ICTLBITS(u8x4),  S8X4T .ITESTBITS1(s8x4,  1),  S8X4T.ITESTBITS1(s8x4,  -1) );  
                      TYPE(S8X8)  SRCT( U8X8T .ICTLBITS(u8x8),  S8X8T .ITESTBITS1(s8x8,  1),  S8X8T.ITESTBITS1(s8x8,  -1) ); 
                      TYPE(S8X16) SRCT( U8X16T.ICTLBITS(u8x16), S8X16T.ITESTBITS1(s8x16, 1), S8X16T.ITESTBITS1(s8x16, -1) );  
                      TYPE(S16X2) SRCT( U16X2T.ICTLBITS(u16x2), S16X2T.ITESTBITS1(s16x2, 1), S16X2T.ITESTBITS1(s16x2, -1) );  
                      TYPE(S16X4) SRCT( U16X4T.ICTLBITS(u16x4), S16X4T.ITESTBITS1(s16x4, 1), S16X4T.ITESTBITS1(s16x4, -1) );  
                      TYPE(S16X8) SRCT( U16X8T.ICTLBITS(u16x8), S16X8T.ITESTBITS1(s16x8, 1), S16X8T.ITESTBITS1(s16x8, -1) );  
                      TYPE(S32X2) SRCT( U32X2T.ICTLBITS(u32x2), S32X2T.ITESTBITS1(s32x2, 1), S32X2T.ITESTBITS1(s32x2, -1) );  
                      TYPE(S32X4) SRCT( U32X4T.ICTLBITS(u32x4), S32X4T.ITESTBITS1(s32x4, 1), S32X4T.ITESTBITS1(s32x4, -1) );  
                      TYPE(S64X2) SRCT( U64X2T.ICTLBITS(u64x2), S64X2T.ITESTBITS1(s64x2, 1), S64X2T.ITESTBITS1(s64x2, -1) );  
                      TYPE(U8X4)  SRCT( U8X4T .ICTLBITS(u8x4),  U8X4T .ITESTBITS1(u8x4,  1),  U8X4T.ITESTBITS1(u8x4,  -1) );  
                      TYPE(U8X8)  SRCT( U8X8T .ICTLBITS(u8x8),  U8X8T .ITESTBITS1(u8x8,  1),  U8X8T.ITESTBITS1(u8x8,  -1) );  
                      TYPE(U8X16) SRCT( U8X16T.ICTLBITS(u8x16), U8X16T.ITESTBITS1(u8x16, 1), U8X16T.ITESTBITS1(u8x16, -1) );  
                      TYPE(U16X2) SRCT( U16X2T.ICTLBITS(u16x2), U16X2T.ITESTBITS1(u16x2, 1), U16X2T.ITESTBITS1(u16x2, -1) );  
                      TYPE(U16X4) SRCT( U16X4T.ICTLBITS(u16x4), U16X4T.ITESTBITS1(u16x4, 1), U16X4T.ITESTBITS1(u16x4, -1) );  
                      TYPE(U16X8) SRCT( U16X8T.ICTLBITS(u16x8), U16X8T.ITESTBITS1(u16x8, 1), U16X8T.ITESTBITS1(u16x8, -1) );  
                      TYPE(U32X2) SRCT( U32X2T.ICTLBITS(u32x2), U32X2T.ITESTBITS1(u32x2, 1), U32X2T.ITESTBITS1(u32x2, -1) );  
                      TYPE(U32X4) SRCT( U32X4T.ICTLBITS(u32x4), U32X4T.ITESTBITS1(u32x4, 1), U32X4T.ITESTBITS1(u32x4, -1) );  
                      TYPE(U64X2) SRCT( U64X2T.ICTLBITS(u64x2), U64X2T.ITESTBITS1(u64x2, 1), U64X2T.ITESTBITS1(u64x2, -1) );  
                      TYPE(F32X2) SRCT( U32X2T.ICTLBITS(u32x2), F32X2T.FTESTBITS1(f32x2, 1), F32X2T.FTESTBITS1(f32x2, -1) );  
                      TYPE(F32X4) SRCT( U32X4T.ICTLBITS(u32x4), F32X4T.FTESTBITS1(f32x4, 1), F32X4T.FTESTBITS1(f32x4, -1) );  
                      TYPE(F64X2) SRCT( U64X2T.ICTLBITS(u64x2), F64X2T.FTESTBITS1(f64x2, 1), F64X2T.FTESTBITS1(f64x2, -1) );  

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

    INST(BITALIGN)    SRC_TYPE(B32) SRCT( B32T.NEW(0xFFFFFFFF, 0xF0F0F0F0, 0xA0A0A0A) .ADD((b32_t)wavesize),
                                          B32T.NEW(0xFFFFFFFF, 0xF0F0F0F0, 0xA0A0A0A) .ADD((b32_t)wavesize),
                                          B32T.NEW(0, 1, 7, 8, 15).ADD(16, 31, 33, -1).ADD((b32_t)wavesize)
                                        );

    INST(BYTEALIGN)   SRC_TYPE(B32) SRCT( B32T.NEW(0xFFFFFFFF, 0xF0F0F0F0, 0xA0A0A0A).ADD((b32_t)wavesize),
                                          B32T.NEW(0xFFFFFFFF, 0xF0F0F0F0, 0xA0A0A0A).ADD((b32_t)wavesize),
                                          B32T.NEW(0, 1, 3, 4, 7).ADD(8, 12, -1)     .ADD((b32_t)wavesize)
                                        );

    INST(LERP)        TYPE(U8X4) SRCN(3);


    INST(SAD)         TYPE(U32)    SRCT(   U32T,   U32T,  U32T );
                      TYPE(U8X4)   SRCT(  U8X4T,  U8X4T,  U32T );
                      TYPE(U16X2)  SRCT( U16X2T, U16X2T,  U32T );

    INST(SADHI)       TYPE(U8X4)   SRCT(  U8X4T,  U8X4T,  U16X2T );

    INST(PACKCVT)     TYPE(F32)    SRCT( F32T.NEW(-FLOAT_INF,  -FLOAT_PI,   1.0f,      254.0f, FLOAT_INF), 
                                         F32T.NEW(-FLOAT_INF,      -1.0f,   FLOAT_PI,  255.0f, FLOAT_NAN), 
                                         F32T.NEW(-FLOAT_INF,      -0.0f,   1.0f,      255.5f, FLOAT_DENORM * 16), 
                                         F32T.NEW(-FLOAT_INF,      +0.0f,   FLOAT_PI,  300.0f, FLOAT_NAN) );

    INST(UNPACKCVT)   TYPE(U8X4)   SRCT( U8X4T, U32T.NEW(0, 1, 2, 3) );

//INST(SEGMENTP)    // NB: not testable
//INST(FTOS)        // NB: not testable
//INST(STOF)        // NB: not testable

    INST(CMP)         SRC_TYPE(B1)
                      SRC_TYPE(B32)
                      SRC_TYPE(B64)
                      SRC_TYPE(S32)
                      SRC_TYPE(S64)
                      SRC_TYPE(U32)
                      SRC_TYPE(U64)    SRCN(2);
                      SRC_TYPE(F32)    SRCT( F32T.ADDL(extraSubnormF32), F32T.ADDL(extraSubnormF32) );
                      SRC_TYPE(F64)    SRCT( F64T.ADDL(extraSubnormF64), F64T.ADDL(extraSubnormF64) );
                      XTYPES           SRCN(2);

    INST(CVT)         SRC_TYPE(B1)
                      SRC_TYPE(S8)
                      SRC_TYPE(S16)
                      SRC_TYPE(S32)
                      SRC_TYPE(S64)
                      SRC_TYPE(U8)
                      SRC_TYPE(U16)
                      SRC_TYPE(U32)
                      SRC_TYPE(U64) SRCN(1);
                      SRC_TYPE(F32) SRCT( F32T.ADDL(extraTestsF32).ADDL(extraSubnormF32)                   );
                      SRC_TYPE(F64) SRCT( F64T.ADDL(extraTestsF64).ADDL(extraSubnormF64).ADD(ftzCvt64to32) );

    INST(LD)          TYPE(S8)   SRCT(  S8T.NEW (0, MAX_S8,  -1, MIN_S8 )   );
                      TYPE(S16)  SRCT(  S16T.NEW(0, MAX_S16, -1, MIN_S16)   );
                      TYPE(S32)  SRCT(  S32T.NEW(0, MAX_S32             )   );
                      TYPE(S64)  SRCT(  S64T.NEW(0, MAX_S64             )   );
                      TYPE(U8)   SRCT(  U8T.NEW (0, MAX_U8              )   );
                      TYPE(U16)  SRCT(  U16T.NEW(0, MAX_U16)   );
                      TYPE(U32)  SRCT(  U32T.NEW(0, MAX_U32)   );
                      TYPE(U64)  SRCT(  U64T.NEW(0, MAX_U64)   );
                      TYPE(F32)  SRCT(  F32T.NEW(0, FLOAT_PI)  );
                      TYPE(F64)  SRCT(  F64T.NEW(0, DOUBLE_PI) );
                      TYPE(B128) SRCT(  B128T.NEW(b128(0xAA000000BBBB0000ULL, 0xCCCCCCCCFFFFFFFFULL)) );

    INST(ST)          TYPE(S8)   SRCT(0, S8T.NEW (0, MAX_S8,  -1).ADD(wavesize), S8T.NEW(1, MIN_S8)      );
                      TYPE(S16)  SRCT(0, S16T.NEW(0, MAX_S16, -1).ADD(wavesize), S16T.NEW(1, MIN_S16)    );
                      TYPE(S32)  SRCT(0, S32T.NEW(0, MAX_S32)    .ADD(wavesize), S32T.NEW(1, MIN_S32)    );
                      TYPE(S64)  SRCT(0, S64T.NEW(0, MAX_S64)    .ADD(wavesize), S64T.NEW(1, MIN_S64)    );
                      TYPE(U8)   SRCT(0, U8T.NEW (0, MAX_U8)     .ADD(wavesize), U8T.NEW(1, MID_U8)      );
                      TYPE(U16)  SRCT(0, U16T.NEW(0, MAX_U16)    .ADD(wavesize), U16T.NEW(1, MID_U16)    );
                      TYPE(U32)  SRCT(0, U32T.NEW(0, MAX_U32)    .ADD(wavesize), U32T.NEW(1, MID_U32)    );
                      TYPE(U64)  SRCT(0, U64T.NEW(0, MAX_U64)    .ADD(wavesize), U64T.NEW(1, MID_U64)    );
                      TYPE(F32)  SRCT(0, F32T.NEW(0, FLOAT_PI),                  F32T.NEW(1, FLOAT_NAN)  );
                      TYPE(F64)  SRCT(0, F64T.NEW(0, DOUBLE_PI),                 F64T.NEW(1, DOUBLE_NAN) );
                      TYPE(B128) SRCT(0, B128T.NEW(b128(0xAA000000BBBB0000ULL, 0xCCCCCCCCFFFFFFFFULL)).ADD(b128(wavesize, 0)), B128T.NEW(b128(0x12345678DDDDDDDDULL, 0x01020304050607080ULL)) );

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

// Not testable
//
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

