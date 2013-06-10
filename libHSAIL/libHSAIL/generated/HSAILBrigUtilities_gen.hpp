const char* atomicOperation2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ATOMIC_ADD                : return "add";
    case BRIG_ATOMIC_AND                : return "and";
    case BRIG_ATOMIC_CAS                : return "cas";
    case BRIG_ATOMIC_DEC                : return "dec";
    case BRIG_ATOMIC_EXCH               : return "exch";
    case BRIG_ATOMIC_INC                : return "inc";
    case BRIG_ATOMIC_MAX                : return "max";
    case BRIG_ATOMIC_MIN                : return "min";
    case BRIG_ATOMIC_OR                 : return "or";
    case BRIG_ATOMIC_SUB                : return "sub";
    case BRIG_ATOMIC_XOR                : return "xor";
    default : return NULL;
    }
}

const char* compareOperation2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_COMPARE_EQ                : return "eq";
    case BRIG_COMPARE_EQU               : return "equ";
    case BRIG_COMPARE_GE                : return "ge";
    case BRIG_COMPARE_GEU               : return "geu";
    case BRIG_COMPARE_GT                : return "gt";
    case BRIG_COMPARE_GTU               : return "gtu";
    case BRIG_COMPARE_LE                : return "le";
    case BRIG_COMPARE_LEU               : return "leu";
    case BRIG_COMPARE_LT                : return "lt";
    case BRIG_COMPARE_LTU               : return "ltu";
    case BRIG_COMPARE_NAN               : return "nan";
    case BRIG_COMPARE_NE                : return "ne";
    case BRIG_COMPARE_NEU               : return "neu";
    case BRIG_COMPARE_NUM               : return "num";
    case BRIG_COMPARE_SEQ               : return "seq";
    case BRIG_COMPARE_SEQU              : return "sequ";
    case BRIG_COMPARE_SGE               : return "sge";
    case BRIG_COMPARE_SGEU              : return "sgeu";
    case BRIG_COMPARE_SGT               : return "sgt";
    case BRIG_COMPARE_SGTU              : return "sgtu";
    case BRIG_COMPARE_SLE               : return "sle";
    case BRIG_COMPARE_SLEU              : return "sleu";
    case BRIG_COMPARE_SLT               : return "slt";
    case BRIG_COMPARE_SLTU              : return "sltu";
    case BRIG_COMPARE_SNAN              : return "snan";
    case BRIG_COMPARE_SNE               : return "sne";
    case BRIG_COMPARE_SNEU              : return "sneu";
    case BRIG_COMPARE_SNUM              : return "snum";
    default : return NULL;
    }
}

const char* controlDirective2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_CONTROL_ENABLEBREAKEXCEPTIONS : return "enablebreakexceptions";
    case BRIG_CONTROL_ENABLEDETECTEXCEPTIONS : return "enabledetectexceptions";
    case BRIG_CONTROL_MAXDYNAMICGROUPSIZE : return "maxdynamicgroupsize";
    case BRIG_CONTROL_MAXFLATGRIDSIZE   : return "maxflatgridsize";
    case BRIG_CONTROL_MAXFLATWORKGROUPSIZE : return "maxflatworkgroupsize";
    case BRIG_CONTROL_NONE              : return "";
    case BRIG_CONTROL_REQUESTEDWORKGROUPSPERCU : return "requestedworkgroupspercu";
    case BRIG_CONTROL_REQUIREDDIM       : return "requireddim";
    case BRIG_CONTROL_REQUIREDGRIDSIZE  : return "requiredgridsize";
    case BRIG_CONTROL_REQUIREDWORKGROUPSIZE : return "requiredworkgroupsize";
    case BRIG_CONTROL_REQUIRENOPARTIALWORKGROUPS : return "requirenopartialworkgroups";
    default : return NULL;
    }
}

int size_of_directive(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_DIRECTIVE_ARG_SCOPE_END   : return sizeof(BrigDirectiveArgScopeEnd);
    case BRIG_DIRECTIVE_ARG_SCOPE_START : return sizeof(BrigDirectiveArgScopeStart);
    case BRIG_DIRECTIVE_BLOCK_END       : return sizeof(BrigBlockEnd);
    case BRIG_DIRECTIVE_BLOCK_NUMERIC   : return sizeof(BrigBlockNumeric);
    case BRIG_DIRECTIVE_BLOCK_START     : return sizeof(BrigBlockStart);
    case BRIG_DIRECTIVE_BLOCK_STRING    : return sizeof(BrigBlockString);
    case BRIG_DIRECTIVE_COMMENT         : return sizeof(BrigDirectiveComment);
    case BRIG_DIRECTIVE_CONTROL         : return sizeof(BrigDirectiveControl);
    case BRIG_DIRECTIVE_EXTENSION       : return sizeof(BrigDirectiveExtension);
    case BRIG_DIRECTIVE_FBARRIER        : return sizeof(BrigDirectiveFbarrier);
    case BRIG_DIRECTIVE_FILE            : return sizeof(BrigDirectiveFile);
    case BRIG_DIRECTIVE_FUNCTION        : return sizeof(BrigDirectiveFunction);
    case BRIG_DIRECTIVE_IMAGE           : return sizeof(BrigDirectiveImage);
    case BRIG_DIRECTIVE_IMAGE_INIT      : return sizeof(BrigDirectiveImageInit);
    case BRIG_DIRECTIVE_KERNEL          : return sizeof(BrigDirectiveKernel);
    case BRIG_DIRECTIVE_LABEL           : return sizeof(BrigDirectiveLabel);
    case BRIG_DIRECTIVE_LABEL_INIT      : return sizeof(BrigDirectiveLabelInit);
    case BRIG_DIRECTIVE_LABEL_TARGETS   : return sizeof(BrigDirectiveLabelTargets);
    case BRIG_DIRECTIVE_LOC             : return sizeof(BrigDirectiveLoc);
    case BRIG_DIRECTIVE_PRAGMA          : return sizeof(BrigDirectivePragma);
    case BRIG_DIRECTIVE_SAMPLER         : return sizeof(BrigDirectiveSampler);
    case BRIG_DIRECTIVE_SAMPLER_INIT    : return sizeof(BrigDirectiveSamplerInit);
    case BRIG_DIRECTIVE_SIGNATURE       : return sizeof(BrigDirectiveSignature);
    case BRIG_DIRECTIVE_VARIABLE        : return sizeof(BrigDirectiveVariable);
    case BRIG_DIRECTIVE_VARIABLE_INIT   : return sizeof(BrigDirectiveVariableInit);
    case BRIG_DIRECTIVE_VERSION         : return sizeof(BrigDirectiveVersion);
    default : return -1;
    }
}

bool isToplevelOnly(Directive d) {
  using namespace Brig;
  switch( d.brig()->kind ) {
    case BRIG_DIRECTIVE_ARG_SCOPE_END   : return false;
    case BRIG_DIRECTIVE_ARG_SCOPE_START : return false;
    case BRIG_DIRECTIVE_BLOCK_END       : return false;
    case BRIG_DIRECTIVE_BLOCK_NUMERIC   : return false;
    case BRIG_DIRECTIVE_BLOCK_START     : return false;
    case BRIG_DIRECTIVE_BLOCK_STRING    : return false;
    case BRIG_DIRECTIVE_COMMENT         : return false;
    case BRIG_DIRECTIVE_CONTROL         : return false;
    case BRIG_DIRECTIVE_EXTENSION       : return true;
    case BRIG_DIRECTIVE_FBARRIER        : return false;
    case BRIG_DIRECTIVE_FILE            : return true;
    case BRIG_DIRECTIVE_FUNCTION        : return true;
    case BRIG_DIRECTIVE_IMAGE           : return false;
    case BRIG_DIRECTIVE_IMAGE_INIT      : return true;
    case BRIG_DIRECTIVE_KERNEL          : return true;
    case BRIG_DIRECTIVE_LABEL           : return false;
    case BRIG_DIRECTIVE_LABEL_INIT      : return false;
    case BRIG_DIRECTIVE_LABEL_TARGETS   : return false;
    case BRIG_DIRECTIVE_LOC             : return false;
    case BRIG_DIRECTIVE_PRAGMA          : return false;
    case BRIG_DIRECTIVE_SAMPLER         : return false;
    case BRIG_DIRECTIVE_SAMPLER_INIT    : return true;
    case BRIG_DIRECTIVE_SIGNATURE       : return true;
    case BRIG_DIRECTIVE_VARIABLE        : return false;
    case BRIG_DIRECTIVE_VARIABLE_INIT   : return false;
    case BRIG_DIRECTIVE_VERSION         : return true;
    default : assert(false); return false;
    }
}

bool isBodyOnly(Directive d) {
  using namespace Brig;
  switch( d.brig()->kind ) {
    case BRIG_DIRECTIVE_ARG_SCOPE_END   : return true;
    case BRIG_DIRECTIVE_ARG_SCOPE_START : return true;
    case BRIG_DIRECTIVE_BLOCK_END       : return false;
    case BRIG_DIRECTIVE_BLOCK_NUMERIC   : return false;
    case BRIG_DIRECTIVE_BLOCK_START     : return false;
    case BRIG_DIRECTIVE_BLOCK_STRING    : return false;
    case BRIG_DIRECTIVE_COMMENT         : return false;
    case BRIG_DIRECTIVE_CONTROL         : return true;
    case BRIG_DIRECTIVE_EXTENSION       : return false;
    case BRIG_DIRECTIVE_FBARRIER        : return false;
    case BRIG_DIRECTIVE_FILE            : return false;
    case BRIG_DIRECTIVE_FUNCTION        : return false;
    case BRIG_DIRECTIVE_IMAGE           : return false;
    case BRIG_DIRECTIVE_IMAGE_INIT      : return false;
    case BRIG_DIRECTIVE_KERNEL          : return false;
    case BRIG_DIRECTIVE_LABEL           : return true;
    case BRIG_DIRECTIVE_LABEL_INIT      : return true;
    case BRIG_DIRECTIVE_LABEL_TARGETS   : return true;
    case BRIG_DIRECTIVE_LOC             : return true;
    case BRIG_DIRECTIVE_PRAGMA          : return false;
    case BRIG_DIRECTIVE_SAMPLER         : return false;
    case BRIG_DIRECTIVE_SAMPLER_INIT    : return false;
    case BRIG_DIRECTIVE_SIGNATURE       : return false;
    case BRIG_DIRECTIVE_VARIABLE        : return false;
    case BRIG_DIRECTIVE_VARIABLE_INIT   : return false;
    case BRIG_DIRECTIVE_VERSION         : return false;
    default : assert(false); return false;
    }
}

const char* imageFormat2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_FORMAT_FLOAT              : return "float";
    case BRIG_FORMAT_HALF_FLOAT         : return "half_float";
    case BRIG_FORMAT_SIGNED_INT16       : return "signed_int16";
    case BRIG_FORMAT_SIGNED_INT32       : return "signed_int32";
    case BRIG_FORMAT_SIGNED_INT8        : return "signed_int8";
    case BRIG_FORMAT_SNORM_INT16        : return "snorm_int16";
    case BRIG_FORMAT_SNORM_INT8         : return "snorm_int8";
    case BRIG_FORMAT_UNKNOWN            : return "";
    case BRIG_FORMAT_UNORM_INT16        : return "unorm_int16";
    case BRIG_FORMAT_UNORM_INT24        : return "unorm_int24";
    case BRIG_FORMAT_UNORM_INT8         : return "unorm_int8";
    case BRIG_FORMAT_UNORM_SHORT_101010 : return "unorm_short_101010";
    case BRIG_FORMAT_UNORM_SHORT_555    : return "unorm_short_555";
    case BRIG_FORMAT_UNORM_SHORT_565    : return "unorm_short_565";
    case BRIG_FORMAT_UNSIGNED_INT16     : return "unsigned_int16";
    case BRIG_FORMAT_UNSIGNED_INT32     : return "unsigned_int32";
    case BRIG_FORMAT_UNSIGNED_INT8      : return "unsigned_int8";
    default : return NULL;
    }
}

const char* imageGeometry2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_GEOMETRY_1D               : return "1d";
    case BRIG_GEOMETRY_1DA              : return "1da";
    case BRIG_GEOMETRY_1DB              : return "1db";
    case BRIG_GEOMETRY_2D               : return "2d";
    case BRIG_GEOMETRY_2DA              : return "2da";
    case BRIG_GEOMETRY_3D               : return "3d";
    default : return NULL;
    }
}

const char* imageOrder2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ORDER_A                   : return "a";
    case BRIG_ORDER_ARGB                : return "argb";
    case BRIG_ORDER_BGRA                : return "bgra";
    case BRIG_ORDER_INTENSITY           : return "intensity";
    case BRIG_ORDER_LUMINANCE           : return "luminance";
    case BRIG_ORDER_R                   : return "r";
    case BRIG_ORDER_RA                  : return "ra";
    case BRIG_ORDER_RG                  : return "rg";
    case BRIG_ORDER_RGB                 : return "rgb";
    case BRIG_ORDER_RGBA                : return "rgba";
    case BRIG_ORDER_RGBX                : return "rgbx";
    case BRIG_ORDER_RGX                 : return "rgx";
    case BRIG_ORDER_RX                  : return "rx";
    case BRIG_ORDER_SBGRA               : return "sbgra";
    case BRIG_ORDER_SRGB                : return "srgb";
    case BRIG_ORDER_SRGBA               : return "srgba";
    case BRIG_ORDER_SRGBX               : return "srgbx";
    case BRIG_ORDER_UNKNOWN             : return "";
    default : return NULL;
    }
}

int size_of_inst(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_INST_ADDR                 : return sizeof(BrigInstAddr);
    case BRIG_INST_ATOMIC               : return sizeof(BrigInstAtomic);
    case BRIG_INST_ATOMIC_IMAGE         : return sizeof(BrigInstAtomicImage);
    case BRIG_INST_BAR                  : return sizeof(BrigInstBar);
    case BRIG_INST_BASIC                : return sizeof(BrigInstBasic);
    case BRIG_INST_BR                   : return sizeof(BrigInstBr);
    case BRIG_INST_CMP                  : return sizeof(BrigInstCmp);
    case BRIG_INST_CVT                  : return sizeof(BrigInstCvt);
    case BRIG_INST_FBAR                 : return sizeof(BrigInstFbar);
    case BRIG_INST_IMAGE                : return sizeof(BrigInstImage);
    case BRIG_INST_MEM                  : return sizeof(BrigInstMem);
    case BRIG_INST_MOD                  : return sizeof(BrigInstMod);
    case BRIG_INST_SEG                  : return sizeof(BrigInstSeg);
    case BRIG_INST_SOURCE_TYPE          : return sizeof(BrigInstSourceType);
    default : return -1;
    }
}

const char* linkage2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_LINKAGE_EXTERN            : return "extern";
    case BRIG_LINKAGE_NONE              : return "";
    case BRIG_LINKAGE_STATIC            : return "static";
    default : return NULL;
    }
}

const char* machineModel2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MACHINE_LARGE             : return "$large";
    case BRIG_MACHINE_SMALL             : return "$small";
    default : return NULL;
    }
}

const char* memoryFence2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_FENCE_BOTH                : return "fboth";
    case BRIG_FENCE_GLOBAL              : return "fglobal";
    case BRIG_FENCE_GROUP               : return "fgroup";
    case BRIG_FENCE_NONE                : return "fnone";
    case BRIG_FENCE_PARTIAL             : return "fpartial";
    case BRIG_FENCE_PARTIAL_BOTH        : return "fpartialboth";
    default : return NULL;
    }
}

const char* memorySemantic2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_SEMANTIC_ACQUIRE          : return "acq";
    case BRIG_SEMANTIC_ACQUIRE_RELEASE  : return "ar";
    case BRIG_SEMANTIC_PARTIAL_ACQUIRE  : return "part_acq";
    case BRIG_SEMANTIC_PARTIAL_ACQUIRE_RELEASE : return "part_ar";
    case BRIG_SEMANTIC_PARTIAL_RELEASE  : return "part_rel";
    case BRIG_SEMANTIC_REGULAR          : return "regular";
    case BRIG_SEMANTIC_RELEASE          : return "rel";
    default : return NULL;
    }
}

const char* opcode2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_ABS                : return "abs";
    case BRIG_OPCODE_ADD                : return "add";
    case BRIG_OPCODE_ALLOCA             : return "alloca";
    case BRIG_OPCODE_AND                : return "and";
    case BRIG_OPCODE_ARRIVEFBAR         : return "arrivefbar";
    case BRIG_OPCODE_ATOMIC             : return "atomic";
    case BRIG_OPCODE_ATOMICIMAGE        : return "atomicimage";
    case BRIG_OPCODE_ATOMICIMAGENORET   : return "atomicimagenoret";
    case BRIG_OPCODE_ATOMICNORET        : return "atomicnoret";
    case BRIG_OPCODE_BARRIER            : return "barrier";
    case BRIG_OPCODE_BITALIGN           : return "bitalign";
    case BRIG_OPCODE_BITEXTRACT         : return "bitextract";
    case BRIG_OPCODE_BITINSERT          : return "bitinsert";
    case BRIG_OPCODE_BITMASK            : return "bitmask";
    case BRIG_OPCODE_BITREV             : return "bitrev";
    case BRIG_OPCODE_BITSELECT          : return "bitselect";
    case BRIG_OPCODE_BORROW             : return "borrow";
    case BRIG_OPCODE_BRN                : return "brn";
    case BRIG_OPCODE_BYTEALIGN          : return "bytealign";
    case BRIG_OPCODE_CALL               : return "call";
    case BRIG_OPCODE_CARRY              : return "carry";
    case BRIG_OPCODE_CBR                : return "cbr";
    case BRIG_OPCODE_CEIL               : return "ceil";
    case BRIG_OPCODE_CLASS              : return "class";
    case BRIG_OPCODE_CLEARDETECTEXCEPT  : return "cleardetectexcept";
    case BRIG_OPCODE_CLOCK              : return "clock";
    case BRIG_OPCODE_CMOV               : return "cmov";
    case BRIG_OPCODE_CMP                : return "cmp";
    case BRIG_OPCODE_COMBINE            : return "combine";
    case BRIG_OPCODE_COPYSIGN           : return "copysign";
    case BRIG_OPCODE_COUNTLANE          : return "countlane";
    case BRIG_OPCODE_COUNTUPLANE        : return "countuplane";
    case BRIG_OPCODE_CUID               : return "cuid";
    case BRIG_OPCODE_CURRENTWORKGROUPSIZE : return "currentworkgroupsize";
    case BRIG_OPCODE_CVT                : return "cvt";
    case BRIG_OPCODE_DEBUGTRAP          : return "debugtrap";
    case BRIG_OPCODE_DIM                : return "dim";
    case BRIG_OPCODE_DISPATCHID         : return "dispatchid";
    case BRIG_OPCODE_DISPATCHPTR        : return "dispatchptr";
    case BRIG_OPCODE_DIV                : return "div";
    case BRIG_OPCODE_EXPAND             : return "expand";
    case BRIG_OPCODE_FIRSTBIT           : return "firstbit";
    case BRIG_OPCODE_FLOOR              : return "floor";
    case BRIG_OPCODE_FMA                : return "fma";
    case BRIG_OPCODE_FRACT              : return "fract";
    case BRIG_OPCODE_FTOS               : return "ftos";
    case BRIG_OPCODE_GETDETECTEXCEPT    : return "getdetectexcept";
    case BRIG_OPCODE_GRIDGROUPS         : return "gridgroups";
    case BRIG_OPCODE_GRIDSIZE           : return "gridsize";
    case BRIG_OPCODE_INITFBAR           : return "initfbar";
    case BRIG_OPCODE_JOINFBAR           : return "joinfbar";
    case BRIG_OPCODE_LANEID             : return "laneid";
    case BRIG_OPCODE_LASTBIT            : return "lastbit";
    case BRIG_OPCODE_LD                 : return "ld";
    case BRIG_OPCODE_LDA                : return "lda";
    case BRIG_OPCODE_LDC                : return "ldc";
    case BRIG_OPCODE_LDF                : return "ldf";
    case BRIG_OPCODE_LDIMAGE            : return "ldimage";
    case BRIG_OPCODE_LEAVEFBAR          : return "leavefbar";
    case BRIG_OPCODE_LERP               : return "lerp";
    case BRIG_OPCODE_MAD                : return "mad";
    case BRIG_OPCODE_MAD24              : return "mad24";
    case BRIG_OPCODE_MAD24HI            : return "mad24hi";
    case BRIG_OPCODE_MASKLANE           : return "masklane";
    case BRIG_OPCODE_MAX                : return "max";
    case BRIG_OPCODE_MAXCUID            : return "maxcuid";
    case BRIG_OPCODE_MAXWAVEID          : return "maxwaveid";
    case BRIG_OPCODE_MIN                : return "min";
    case BRIG_OPCODE_MOV                : return "mov";
    case BRIG_OPCODE_MUL                : return "mul";
    case BRIG_OPCODE_MUL24              : return "mul24";
    case BRIG_OPCODE_MUL24HI            : return "mul24hi";
    case BRIG_OPCODE_MULHI              : return "mulhi";
    case BRIG_OPCODE_NCOS               : return "ncos";
    case BRIG_OPCODE_NEG                : return "neg";
    case BRIG_OPCODE_NEXP2              : return "nexp2";
    case BRIG_OPCODE_NFMA               : return "nfma";
    case BRIG_OPCODE_NLOG2              : return "nlog2";
    case BRIG_OPCODE_NOP                : return "nop";
    case BRIG_OPCODE_NOT                : return "not";
    case BRIG_OPCODE_NRCP               : return "nrcp";
    case BRIG_OPCODE_NRSQRT             : return "nrsqrt";
    case BRIG_OPCODE_NSIN               : return "nsin";
    case BRIG_OPCODE_NSQRT              : return "nsqrt";
    case BRIG_OPCODE_NULLPTR            : return "nullptr";
    case BRIG_OPCODE_OR                 : return "or";
    case BRIG_OPCODE_PACK               : return "pack";
    case BRIG_OPCODE_PACKCVT            : return "packcvt";
    case BRIG_OPCODE_POPCOUNT           : return "popcount";
    case BRIG_OPCODE_QID                : return "qid";
    case BRIG_OPCODE_QPTR               : return "qptr";
    case BRIG_OPCODE_QUERYIMAGEARRAY    : return "queryimagearray";
    case BRIG_OPCODE_QUERYIMAGEDEPTH    : return "queryimagedepth";
    case BRIG_OPCODE_QUERYIMAGEFORMAT   : return "queryimageformat";
    case BRIG_OPCODE_QUERYIMAGEHEIGHT   : return "queryimageheight";
    case BRIG_OPCODE_QUERYIMAGEORDER    : return "queryimageorder";
    case BRIG_OPCODE_QUERYIMAGEWIDTH    : return "queryimagewidth";
    case BRIG_OPCODE_QUERYSAMPLERCOORD  : return "querysamplercoord";
    case BRIG_OPCODE_QUERYSAMPLERFILTER : return "querysamplerfilter";
    case BRIG_OPCODE_RDIMAGE            : return "rdimage";
    case BRIG_OPCODE_RECEIVELANE        : return "receivelane";
    case BRIG_OPCODE_RELEASEFBAR        : return "releasefbar";
    case BRIG_OPCODE_REM                : return "rem";
    case BRIG_OPCODE_RET                : return "ret";
    case BRIG_OPCODE_RINT               : return "rint";
    case BRIG_OPCODE_SAD                : return "sad";
    case BRIG_OPCODE_SADHI              : return "sadhi";
    case BRIG_OPCODE_SEGMENTP           : return "segmentp";
    case BRIG_OPCODE_SENDLANE           : return "sendlane";
    case BRIG_OPCODE_SETDETECTEXCEPT    : return "setdetectexcept";
    case BRIG_OPCODE_SHL                : return "shl";
    case BRIG_OPCODE_SHR                : return "shr";
    case BRIG_OPCODE_SHUFFLE            : return "shuffle";
    case BRIG_OPCODE_SQRT               : return "sqrt";
    case BRIG_OPCODE_ST                 : return "st";
    case BRIG_OPCODE_STIMAGE            : return "stimage";
    case BRIG_OPCODE_STOF               : return "stof";
    case BRIG_OPCODE_SUB                : return "sub";
    case BRIG_OPCODE_SYNC               : return "sync";
    case BRIG_OPCODE_SYSCALL            : return "syscall";
    case BRIG_OPCODE_TRUNC              : return "trunc";
    case BRIG_OPCODE_UNPACK             : return "unpack";
    case BRIG_OPCODE_UNPACKCVT          : return "unpackcvt";
    case BRIG_OPCODE_UNPACKHI           : return "unpackhi";
    case BRIG_OPCODE_UNPACKLO           : return "unpacklo";
    case BRIG_OPCODE_WAITFBAR           : return "waitfbar";
    case BRIG_OPCODE_WAVEID             : return "waveid";
    case BRIG_OPCODE_WORKGROUPID        : return "workgroupid";
    case BRIG_OPCODE_WORKGROUPSIZE      : return "workgroupsize";
    case BRIG_OPCODE_WORKITEMABSID      : return "workitemabsid";
    case BRIG_OPCODE_WORKITEMFLATABSID  : return "workitemflatabsid";
    case BRIG_OPCODE_WORKITEMFLATID     : return "workitemflatid";
    case BRIG_OPCODE_WORKITEMID         : return "workitemid";
    case BRIG_OPCODE_XOR                : return "xor";
    default : return NULL;
    }
}

bool doesSupportMemorySemantic(Brig::BrigOpcode16_t arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_LD                 : return true;
    case BRIG_OPCODE_ST                 : return true;
    default : return false;
    }
}

Brig::BrigMemoryFence8_t getDefFence(Brig::BrigOpcode16_t arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_ARRIVEFBAR         : return Brig::BRIG_FENCE_BOTH;
    case BRIG_OPCODE_BARRIER            : return Brig::BRIG_FENCE_BOTH;
    case BRIG_OPCODE_SYNC               : return Brig::BRIG_FENCE_BOTH;
    case BRIG_OPCODE_WAITFBAR           : return Brig::BRIG_FENCE_BOTH;
    default : return Brig::BRIG_FENCE_NONE;
    }
}

int size_of_operand(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPERAND_ADDRESS           : return sizeof(BrigOperandAddress);
    case BRIG_OPERAND_ARGUMENT_LIST     : return sizeof(BrigOperandArgumentList);
    case BRIG_OPERAND_ARGUMENT_REF      : return sizeof(BrigOperandArgumentRef);
    case BRIG_OPERAND_FBARRIER_REF      : return sizeof(BrigOperandFbarrierRef);
    case BRIG_OPERAND_FUNCTION_LIST     : return sizeof(BrigOperandFunctionList);
    case BRIG_OPERAND_FUNCTION_REF      : return sizeof(BrigOperandFunctionRef);
    case BRIG_OPERAND_IMMED             : return sizeof(BrigOperandImmed);
    case BRIG_OPERAND_LABEL_REF         : return sizeof(BrigOperandLabelRef);
    case BRIG_OPERAND_REG               : return sizeof(BrigOperandReg);
    case BRIG_OPERAND_REG_VECTOR        : return sizeof(BrigOperandRegVector);
    case BRIG_OPERAND_SIGNATURE_REF     : return sizeof(BrigOperandSignatureRef);
    case BRIG_OPERAND_WAVESIZE          : return sizeof(BrigOperandWavesize);
    default : return -1;
    }
}

const char* pack2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_PACK_NONE                 : return "";
    case BRIG_PACK_P                    : return "p";
    case BRIG_PACK_PP                   : return "pp";
    case BRIG_PACK_PPSAT                : return "pp_sat";
    case BRIG_PACK_PS                   : return "ps";
    case BRIG_PACK_PSAT                 : return "p_sat";
    case BRIG_PACK_PSSAT                : return "ps_sat";
    case BRIG_PACK_S                    : return "s";
    case BRIG_PACK_SP                   : return "sp";
    case BRIG_PACK_SPSAT                : return "sp_sat";
    case BRIG_PACK_SS                   : return "ss";
    case BRIG_PACK_SSAT                 : return "s_sat";
    case BRIG_PACK_SSSAT                : return "ss_sat";
    default : return NULL;
    }
}

const char* profile2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_PROFILE_BASE              : return "$base";
    case BRIG_PROFILE_FULL              : return "$full";
    default : return NULL;
    }
}

const char* round2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ROUND_FLOAT_MINUS_INFINITY : return "down";
    case BRIG_ROUND_FLOAT_NEAR_EVEN     : return "near";
    case BRIG_ROUND_FLOAT_PLUS_INFINITY : return "up";
    case BRIG_ROUND_FLOAT_ZERO          : return "zero";
    case BRIG_ROUND_INTEGER_MINUS_INFINITY : return "downi";
    case BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT : return "downi_sat";
    case BRIG_ROUND_INTEGER_NEAR_EVEN   : return "neari";
    case BRIG_ROUND_INTEGER_NEAR_EVEN_SAT : return "neari_sat";
    case BRIG_ROUND_INTEGER_PLUS_INFINITY : return "upi";
    case BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT : return "upi_sat";
    case BRIG_ROUND_INTEGER_ZERO        : return "zeroi";
    case BRIG_ROUND_INTEGER_ZERO_SAT    : return "zeroi_sat";
    default : return NULL;
    }
}

const char* samplerBoundaryMode2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_BOUNDARY_BORDER           : return "border";
    case BRIG_BOUNDARY_CLAMP            : return "clamp";
    case BRIG_BOUNDARY_MIRROR           : return "mirror";
    case BRIG_BOUNDARY_MIRRORONCE       : return "mirroronce";
    case BRIG_BOUNDARY_WRAP             : return "wrap";
    default : return NULL;
    }
}

const char* samplerFilter2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_FILTER_LINEAR             : return "linear";
    case BRIG_FILTER_NEAREST            : return "nearest";
    default : return NULL;
    }
}

const char* segment2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_SEGMENT_ARG               : return "arg";
    case BRIG_SEGMENT_EXTSPACE0         : return "extspace0";
    case BRIG_SEGMENT_FLAT              : return "";
    case BRIG_SEGMENT_GLOBAL            : return "global";
    case BRIG_SEGMENT_GROUP             : return "group";
    case BRIG_SEGMENT_KERNARG           : return "kernarg";
    case BRIG_SEGMENT_NONE              : return "";
    case BRIG_SEGMENT_PRIVATE           : return "private";
    case BRIG_SEGMENT_READONLY          : return "readonly";
    case BRIG_SEGMENT_SPILL             : return "spill";
    default : return NULL;
    }
}

int brigtype_get_length(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_TYPE_B1                   : return 1;
    case BRIG_TYPE_B128                 : return 128;
    case BRIG_TYPE_B16                  : return 16;
    case BRIG_TYPE_B32                  : return 32;
    case BRIG_TYPE_B64                  : return 64;
    case BRIG_TYPE_B8                   : return 8;
    case BRIG_TYPE_F16                  : return 16;
    case BRIG_TYPE_F16X2                : return 32;
    case BRIG_TYPE_F16X4                : return 64;
    case BRIG_TYPE_F16X8                : return 128;
    case BRIG_TYPE_F32                  : return 32;
    case BRIG_TYPE_F32X2                : return 64;
    case BRIG_TYPE_F32X4                : return 128;
    case BRIG_TYPE_F64                  : return 64;
    case BRIG_TYPE_F64X2                : return 128;
    case BRIG_TYPE_S16                  : return 16;
    case BRIG_TYPE_S16X2                : return 32;
    case BRIG_TYPE_S16X4                : return 64;
    case BRIG_TYPE_S16X8                : return 128;
    case BRIG_TYPE_S32                  : return 32;
    case BRIG_TYPE_S32X2                : return 64;
    case BRIG_TYPE_S32X4                : return 128;
    case BRIG_TYPE_S64                  : return 64;
    case BRIG_TYPE_S64X2                : return 128;
    case BRIG_TYPE_S8                   : return 8;
    case BRIG_TYPE_S8X16                : return 128;
    case BRIG_TYPE_S8X4                 : return 32;
    case BRIG_TYPE_S8X8                 : return 64;
    case BRIG_TYPE_U16                  : return 16;
    case BRIG_TYPE_U16X2                : return 32;
    case BRIG_TYPE_U16X4                : return 64;
    case BRIG_TYPE_U16X8                : return 128;
    case BRIG_TYPE_U32                  : return 32;
    case BRIG_TYPE_U32X2                : return 64;
    case BRIG_TYPE_U32X4                : return 128;
    case BRIG_TYPE_U64                  : return 64;
    case BRIG_TYPE_U64X2                : return 128;
    case BRIG_TYPE_U8                   : return 8;
    case BRIG_TYPE_U8X16                : return 128;
    case BRIG_TYPE_U8X4                 : return 32;
    case BRIG_TYPE_U8X8                 : return 64;
    default : return 0;
    }
}

const char* typeX2str(unsigned arg) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_TYPE_B1                   : return "b1";
    case BRIG_TYPE_B128                 : return "b128";
    case BRIG_TYPE_B16                  : return "b16";
    case BRIG_TYPE_B32                  : return "b32";
    case BRIG_TYPE_B64                  : return "b64";
    case BRIG_TYPE_B8                   : return "b8";
    case BRIG_TYPE_F16                  : return "f16";
    case BRIG_TYPE_F16X2                : return "f16x2";
    case BRIG_TYPE_F16X4                : return "f16x4";
    case BRIG_TYPE_F16X8                : return "f16x8";
    case BRIG_TYPE_F32                  : return "f32";
    case BRIG_TYPE_F32X2                : return "f32x2";
    case BRIG_TYPE_F32X4                : return "f32x4";
    case BRIG_TYPE_F64                  : return "f64";
    case BRIG_TYPE_F64X2                : return "f64x2";
    case BRIG_TYPE_FBAR                 : return "fbar";
    case BRIG_TYPE_NONE                 : return "";
    case BRIG_TYPE_ROIMG                : return "roimg";
    case BRIG_TYPE_RWIMG                : return "rwimg";
    case BRIG_TYPE_S16                  : return "s16";
    case BRIG_TYPE_S16X2                : return "s16x2";
    case BRIG_TYPE_S16X4                : return "s16x4";
    case BRIG_TYPE_S16X8                : return "s16x8";
    case BRIG_TYPE_S32                  : return "s32";
    case BRIG_TYPE_S32X2                : return "s32x2";
    case BRIG_TYPE_S32X4                : return "s32x4";
    case BRIG_TYPE_S64                  : return "s64";
    case BRIG_TYPE_S64X2                : return "s64x2";
    case BRIG_TYPE_S8                   : return "s8";
    case BRIG_TYPE_S8X16                : return "s8x16";
    case BRIG_TYPE_S8X4                 : return "s8x4";
    case BRIG_TYPE_S8X8                 : return "s8x8";
    case BRIG_TYPE_SAMP                 : return "samp";
    case BRIG_TYPE_U16                  : return "u16";
    case BRIG_TYPE_U16X2                : return "u16x2";
    case BRIG_TYPE_U16X4                : return "u16x4";
    case BRIG_TYPE_U16X8                : return "u16x8";
    case BRIG_TYPE_U32                  : return "u32";
    case BRIG_TYPE_U32X2                : return "u32x2";
    case BRIG_TYPE_U32X4                : return "u32x4";
    case BRIG_TYPE_U64                  : return "u64";
    case BRIG_TYPE_U64X2                : return "u64x2";
    case BRIG_TYPE_U8                   : return "u8";
    case BRIG_TYPE_U8X16                : return "u8x16";
    case BRIG_TYPE_U8X4                 : return "u8x4";
    case BRIG_TYPE_U8X8                 : return "u8x8";
    default : return NULL;
    }
}

const char* anyEnum2str( Brig::BrigAluModifierMask arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ALU_FTZ                   : return "BRIG_ALU_FTZ";
    case BRIG_ALU_ROUND                 : return "BRIG_ALU_ROUND";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigAtomicOperation arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ATOMIC_ADD                : return "BRIG_ATOMIC_ADD";
    case BRIG_ATOMIC_AND                : return "BRIG_ATOMIC_AND";
    case BRIG_ATOMIC_CAS                : return "BRIG_ATOMIC_CAS";
    case BRIG_ATOMIC_DEC                : return "BRIG_ATOMIC_DEC";
    case BRIG_ATOMIC_EXCH               : return "BRIG_ATOMIC_EXCH";
    case BRIG_ATOMIC_INC                : return "BRIG_ATOMIC_INC";
    case BRIG_ATOMIC_MAX                : return "BRIG_ATOMIC_MAX";
    case BRIG_ATOMIC_MIN                : return "BRIG_ATOMIC_MIN";
    case BRIG_ATOMIC_OR                 : return "BRIG_ATOMIC_OR";
    case BRIG_ATOMIC_SUB                : return "BRIG_ATOMIC_SUB";
    case BRIG_ATOMIC_XOR                : return "BRIG_ATOMIC_XOR";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigCompareOperation arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_COMPARE_EQ                : return "BRIG_COMPARE_EQ";
    case BRIG_COMPARE_EQU               : return "BRIG_COMPARE_EQU";
    case BRIG_COMPARE_GE                : return "BRIG_COMPARE_GE";
    case BRIG_COMPARE_GEU               : return "BRIG_COMPARE_GEU";
    case BRIG_COMPARE_GT                : return "BRIG_COMPARE_GT";
    case BRIG_COMPARE_GTU               : return "BRIG_COMPARE_GTU";
    case BRIG_COMPARE_LE                : return "BRIG_COMPARE_LE";
    case BRIG_COMPARE_LEU               : return "BRIG_COMPARE_LEU";
    case BRIG_COMPARE_LT                : return "BRIG_COMPARE_LT";
    case BRIG_COMPARE_LTU               : return "BRIG_COMPARE_LTU";
    case BRIG_COMPARE_NAN               : return "BRIG_COMPARE_NAN";
    case BRIG_COMPARE_NE                : return "BRIG_COMPARE_NE";
    case BRIG_COMPARE_NEU               : return "BRIG_COMPARE_NEU";
    case BRIG_COMPARE_NUM               : return "BRIG_COMPARE_NUM";
    case BRIG_COMPARE_SEQ               : return "BRIG_COMPARE_SEQ";
    case BRIG_COMPARE_SEQU              : return "BRIG_COMPARE_SEQU";
    case BRIG_COMPARE_SGE               : return "BRIG_COMPARE_SGE";
    case BRIG_COMPARE_SGEU              : return "BRIG_COMPARE_SGEU";
    case BRIG_COMPARE_SGT               : return "BRIG_COMPARE_SGT";
    case BRIG_COMPARE_SGTU              : return "BRIG_COMPARE_SGTU";
    case BRIG_COMPARE_SLE               : return "BRIG_COMPARE_SLE";
    case BRIG_COMPARE_SLEU              : return "BRIG_COMPARE_SLEU";
    case BRIG_COMPARE_SLT               : return "BRIG_COMPARE_SLT";
    case BRIG_COMPARE_SLTU              : return "BRIG_COMPARE_SLTU";
    case BRIG_COMPARE_SNAN              : return "BRIG_COMPARE_SNAN";
    case BRIG_COMPARE_SNE               : return "BRIG_COMPARE_SNE";
    case BRIG_COMPARE_SNEU              : return "BRIG_COMPARE_SNEU";
    case BRIG_COMPARE_SNUM              : return "BRIG_COMPARE_SNUM";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigControlDirective arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_CONTROL_ENABLEBREAKEXCEPTIONS : return "BRIG_CONTROL_ENABLEBREAKEXCEPTIONS";
    case BRIG_CONTROL_ENABLEDETECTEXCEPTIONS : return "BRIG_CONTROL_ENABLEDETECTEXCEPTIONS";
    case BRIG_CONTROL_MAXDYNAMICGROUPSIZE : return "BRIG_CONTROL_MAXDYNAMICGROUPSIZE";
    case BRIG_CONTROL_MAXFLATGRIDSIZE   : return "BRIG_CONTROL_MAXFLATGRIDSIZE";
    case BRIG_CONTROL_MAXFLATWORKGROUPSIZE : return "BRIG_CONTROL_MAXFLATWORKGROUPSIZE";
    case BRIG_CONTROL_NONE              : return "BRIG_CONTROL_NONE";
    case BRIG_CONTROL_REQUESTEDWORKGROUPSPERCU : return "BRIG_CONTROL_REQUESTEDWORKGROUPSPERCU";
    case BRIG_CONTROL_REQUIREDDIM       : return "BRIG_CONTROL_REQUIREDDIM";
    case BRIG_CONTROL_REQUIREDGRIDSIZE  : return "BRIG_CONTROL_REQUIREDGRIDSIZE";
    case BRIG_CONTROL_REQUIREDWORKGROUPSIZE : return "BRIG_CONTROL_REQUIREDWORKGROUPSIZE";
    case BRIG_CONTROL_REQUIRENOPARTIALWORKGROUPS : return "BRIG_CONTROL_REQUIRENOPARTIALWORKGROUPS";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigDirectiveKinds arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_DIRECTIVE_ARG_SCOPE_END   : return "BRIG_DIRECTIVE_ARG_SCOPE_END";
    case BRIG_DIRECTIVE_ARG_SCOPE_START : return "BRIG_DIRECTIVE_ARG_SCOPE_START";
    case BRIG_DIRECTIVE_BLOCK_END       : return "BRIG_DIRECTIVE_BLOCK_END";
    case BRIG_DIRECTIVE_BLOCK_NUMERIC   : return "BRIG_DIRECTIVE_BLOCK_NUMERIC";
    case BRIG_DIRECTIVE_BLOCK_START     : return "BRIG_DIRECTIVE_BLOCK_START";
    case BRIG_DIRECTIVE_BLOCK_STRING    : return "BRIG_DIRECTIVE_BLOCK_STRING";
    case BRIG_DIRECTIVE_COMMENT         : return "BRIG_DIRECTIVE_COMMENT";
    case BRIG_DIRECTIVE_CONTROL         : return "BRIG_DIRECTIVE_CONTROL";
    case BRIG_DIRECTIVE_EXTENSION       : return "BRIG_DIRECTIVE_EXTENSION";
    case BRIG_DIRECTIVE_FBARRIER        : return "BRIG_DIRECTIVE_FBARRIER";
    case BRIG_DIRECTIVE_FILE            : return "BRIG_DIRECTIVE_FILE";
    case BRIG_DIRECTIVE_FUNCTION        : return "BRIG_DIRECTIVE_FUNCTION";
    case BRIG_DIRECTIVE_IMAGE           : return "BRIG_DIRECTIVE_IMAGE";
    case BRIG_DIRECTIVE_IMAGE_INIT      : return "BRIG_DIRECTIVE_IMAGE_INIT";
    case BRIG_DIRECTIVE_KERNEL          : return "BRIG_DIRECTIVE_KERNEL";
    case BRIG_DIRECTIVE_LABEL           : return "BRIG_DIRECTIVE_LABEL";
    case BRIG_DIRECTIVE_LABEL_INIT      : return "BRIG_DIRECTIVE_LABEL_INIT";
    case BRIG_DIRECTIVE_LABEL_TARGETS   : return "BRIG_DIRECTIVE_LABEL_TARGETS";
    case BRIG_DIRECTIVE_LOC             : return "BRIG_DIRECTIVE_LOC";
    case BRIG_DIRECTIVE_PRAGMA          : return "BRIG_DIRECTIVE_PRAGMA";
    case BRIG_DIRECTIVE_SAMPLER         : return "BRIG_DIRECTIVE_SAMPLER";
    case BRIG_DIRECTIVE_SAMPLER_INIT    : return "BRIG_DIRECTIVE_SAMPLER_INIT";
    case BRIG_DIRECTIVE_SIGNATURE       : return "BRIG_DIRECTIVE_SIGNATURE";
    case BRIG_DIRECTIVE_VARIABLE        : return "BRIG_DIRECTIVE_VARIABLE";
    case BRIG_DIRECTIVE_VARIABLE_INIT   : return "BRIG_DIRECTIVE_VARIABLE_INIT";
    case BRIG_DIRECTIVE_VERSION         : return "BRIG_DIRECTIVE_VERSION";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigImageFormat arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_FORMAT_FLOAT              : return "BRIG_FORMAT_FLOAT";
    case BRIG_FORMAT_HALF_FLOAT         : return "BRIG_FORMAT_HALF_FLOAT";
    case BRIG_FORMAT_SIGNED_INT16       : return "BRIG_FORMAT_SIGNED_INT16";
    case BRIG_FORMAT_SIGNED_INT32       : return "BRIG_FORMAT_SIGNED_INT32";
    case BRIG_FORMAT_SIGNED_INT8        : return "BRIG_FORMAT_SIGNED_INT8";
    case BRIG_FORMAT_SNORM_INT16        : return "BRIG_FORMAT_SNORM_INT16";
    case BRIG_FORMAT_SNORM_INT8         : return "BRIG_FORMAT_SNORM_INT8";
    case BRIG_FORMAT_UNKNOWN            : return "BRIG_FORMAT_UNKNOWN";
    case BRIG_FORMAT_UNORM_INT16        : return "BRIG_FORMAT_UNORM_INT16";
    case BRIG_FORMAT_UNORM_INT24        : return "BRIG_FORMAT_UNORM_INT24";
    case BRIG_FORMAT_UNORM_INT8         : return "BRIG_FORMAT_UNORM_INT8";
    case BRIG_FORMAT_UNORM_SHORT_101010 : return "BRIG_FORMAT_UNORM_SHORT_101010";
    case BRIG_FORMAT_UNORM_SHORT_555    : return "BRIG_FORMAT_UNORM_SHORT_555";
    case BRIG_FORMAT_UNORM_SHORT_565    : return "BRIG_FORMAT_UNORM_SHORT_565";
    case BRIG_FORMAT_UNSIGNED_INT16     : return "BRIG_FORMAT_UNSIGNED_INT16";
    case BRIG_FORMAT_UNSIGNED_INT32     : return "BRIG_FORMAT_UNSIGNED_INT32";
    case BRIG_FORMAT_UNSIGNED_INT8      : return "BRIG_FORMAT_UNSIGNED_INT8";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigImageGeometry arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_GEOMETRY_1D               : return "BRIG_GEOMETRY_1D";
    case BRIG_GEOMETRY_1DA              : return "BRIG_GEOMETRY_1DA";
    case BRIG_GEOMETRY_1DB              : return "BRIG_GEOMETRY_1DB";
    case BRIG_GEOMETRY_2D               : return "BRIG_GEOMETRY_2D";
    case BRIG_GEOMETRY_2DA              : return "BRIG_GEOMETRY_2DA";
    case BRIG_GEOMETRY_3D               : return "BRIG_GEOMETRY_3D";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigImageOrder arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ORDER_A                   : return "BRIG_ORDER_A";
    case BRIG_ORDER_ARGB                : return "BRIG_ORDER_ARGB";
    case BRIG_ORDER_BGRA                : return "BRIG_ORDER_BGRA";
    case BRIG_ORDER_INTENSITY           : return "BRIG_ORDER_INTENSITY";
    case BRIG_ORDER_LUMINANCE           : return "BRIG_ORDER_LUMINANCE";
    case BRIG_ORDER_R                   : return "BRIG_ORDER_R";
    case BRIG_ORDER_RA                  : return "BRIG_ORDER_RA";
    case BRIG_ORDER_RG                  : return "BRIG_ORDER_RG";
    case BRIG_ORDER_RGB                 : return "BRIG_ORDER_RGB";
    case BRIG_ORDER_RGBA                : return "BRIG_ORDER_RGBA";
    case BRIG_ORDER_RGBX                : return "BRIG_ORDER_RGBX";
    case BRIG_ORDER_RGX                 : return "BRIG_ORDER_RGX";
    case BRIG_ORDER_RX                  : return "BRIG_ORDER_RX";
    case BRIG_ORDER_SBGRA               : return "BRIG_ORDER_SBGRA";
    case BRIG_ORDER_SRGB                : return "BRIG_ORDER_SRGB";
    case BRIG_ORDER_SRGBA               : return "BRIG_ORDER_SRGBA";
    case BRIG_ORDER_SRGBX               : return "BRIG_ORDER_SRGBX";
    case BRIG_ORDER_UNKNOWN             : return "BRIG_ORDER_UNKNOWN";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigInstKinds arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_INST_ADDR                 : return "BRIG_INST_ADDR";
    case BRIG_INST_ATOMIC               : return "BRIG_INST_ATOMIC";
    case BRIG_INST_ATOMIC_IMAGE         : return "BRIG_INST_ATOMIC_IMAGE";
    case BRIG_INST_BAR                  : return "BRIG_INST_BAR";
    case BRIG_INST_BASIC                : return "BRIG_INST_BASIC";
    case BRIG_INST_BR                   : return "BRIG_INST_BR";
    case BRIG_INST_CMP                  : return "BRIG_INST_CMP";
    case BRIG_INST_CVT                  : return "BRIG_INST_CVT";
    case BRIG_INST_FBAR                 : return "BRIG_INST_FBAR";
    case BRIG_INST_IMAGE                : return "BRIG_INST_IMAGE";
    case BRIG_INST_MEM                  : return "BRIG_INST_MEM";
    case BRIG_INST_MOD                  : return "BRIG_INST_MOD";
    case BRIG_INST_SEG                  : return "BRIG_INST_SEG";
    case BRIG_INST_SOURCE_TYPE          : return "BRIG_INST_SOURCE_TYPE";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigLinkage arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_LINKAGE_EXTERN            : return "BRIG_LINKAGE_EXTERN";
    case BRIG_LINKAGE_NONE              : return "BRIG_LINKAGE_NONE";
    case BRIG_LINKAGE_STATIC            : return "BRIG_LINKAGE_STATIC";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigMachineModel arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MACHINE_LARGE             : return "BRIG_MACHINE_LARGE";
    case BRIG_MACHINE_SMALL             : return "BRIG_MACHINE_SMALL";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigMemoryFence arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_FENCE_BOTH                : return "BRIG_FENCE_BOTH";
    case BRIG_FENCE_GLOBAL              : return "BRIG_FENCE_GLOBAL";
    case BRIG_FENCE_GROUP               : return "BRIG_FENCE_GROUP";
    case BRIG_FENCE_NONE                : return "BRIG_FENCE_NONE";
    case BRIG_FENCE_PARTIAL             : return "BRIG_FENCE_PARTIAL";
    case BRIG_FENCE_PARTIAL_BOTH        : return "BRIG_FENCE_PARTIAL_BOTH";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigMemoryModifierMask arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_MEMORY_ALIGNED            : return "BRIG_MEMORY_ALIGNED";
    case BRIG_MEMORY_SEMANTIC           : return "BRIG_MEMORY_SEMANTIC";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigMemorySemantic arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_SEMANTIC_ACQUIRE          : return "BRIG_SEMANTIC_ACQUIRE";
    case BRIG_SEMANTIC_ACQUIRE_RELEASE  : return "BRIG_SEMANTIC_ACQUIRE_RELEASE";
    case BRIG_SEMANTIC_NONE             : return "BRIG_SEMANTIC_NONE";
    case BRIG_SEMANTIC_PARTIAL_ACQUIRE  : return "BRIG_SEMANTIC_PARTIAL_ACQUIRE";
    case BRIG_SEMANTIC_PARTIAL_ACQUIRE_RELEASE : return "BRIG_SEMANTIC_PARTIAL_ACQUIRE_RELEASE";
    case BRIG_SEMANTIC_PARTIAL_RELEASE  : return "BRIG_SEMANTIC_PARTIAL_RELEASE";
    case BRIG_SEMANTIC_REGULAR          : return "BRIG_SEMANTIC_REGULAR";
    case BRIG_SEMANTIC_RELEASE          : return "BRIG_SEMANTIC_RELEASE";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigOpcode arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_ABS                : return "BRIG_OPCODE_ABS";
    case BRIG_OPCODE_ADD                : return "BRIG_OPCODE_ADD";
    case BRIG_OPCODE_ALLOCA             : return "BRIG_OPCODE_ALLOCA";
    case BRIG_OPCODE_AND                : return "BRIG_OPCODE_AND";
    case BRIG_OPCODE_ARRIVEFBAR         : return "BRIG_OPCODE_ARRIVEFBAR";
    case BRIG_OPCODE_ATOMIC             : return "BRIG_OPCODE_ATOMIC";
    case BRIG_OPCODE_ATOMICIMAGE        : return "BRIG_OPCODE_ATOMICIMAGE";
    case BRIG_OPCODE_ATOMICIMAGENORET   : return "BRIG_OPCODE_ATOMICIMAGENORET";
    case BRIG_OPCODE_ATOMICNORET        : return "BRIG_OPCODE_ATOMICNORET";
    case BRIG_OPCODE_BARRIER            : return "BRIG_OPCODE_BARRIER";
    case BRIG_OPCODE_BITALIGN           : return "BRIG_OPCODE_BITALIGN";
    case BRIG_OPCODE_BITEXTRACT         : return "BRIG_OPCODE_BITEXTRACT";
    case BRIG_OPCODE_BITINSERT          : return "BRIG_OPCODE_BITINSERT";
    case BRIG_OPCODE_BITMASK            : return "BRIG_OPCODE_BITMASK";
    case BRIG_OPCODE_BITREV             : return "BRIG_OPCODE_BITREV";
    case BRIG_OPCODE_BITSELECT          : return "BRIG_OPCODE_BITSELECT";
    case BRIG_OPCODE_BORROW             : return "BRIG_OPCODE_BORROW";
    case BRIG_OPCODE_BRN                : return "BRIG_OPCODE_BRN";
    case BRIG_OPCODE_BYTEALIGN          : return "BRIG_OPCODE_BYTEALIGN";
    case BRIG_OPCODE_CALL               : return "BRIG_OPCODE_CALL";
    case BRIG_OPCODE_CARRY              : return "BRIG_OPCODE_CARRY";
    case BRIG_OPCODE_CBR                : return "BRIG_OPCODE_CBR";
    case BRIG_OPCODE_CEIL               : return "BRIG_OPCODE_CEIL";
    case BRIG_OPCODE_CLASS              : return "BRIG_OPCODE_CLASS";
    case BRIG_OPCODE_CLEARDETECTEXCEPT  : return "BRIG_OPCODE_CLEARDETECTEXCEPT";
    case BRIG_OPCODE_CLOCK              : return "BRIG_OPCODE_CLOCK";
    case BRIG_OPCODE_CMOV               : return "BRIG_OPCODE_CMOV";
    case BRIG_OPCODE_CMP                : return "BRIG_OPCODE_CMP";
    case BRIG_OPCODE_COMBINE            : return "BRIG_OPCODE_COMBINE";
    case BRIG_OPCODE_COPYSIGN           : return "BRIG_OPCODE_COPYSIGN";
    case BRIG_OPCODE_COUNTLANE          : return "BRIG_OPCODE_COUNTLANE";
    case BRIG_OPCODE_COUNTUPLANE        : return "BRIG_OPCODE_COUNTUPLANE";
    case BRIG_OPCODE_CUID               : return "BRIG_OPCODE_CUID";
    case BRIG_OPCODE_CURRENTWORKGROUPSIZE : return "BRIG_OPCODE_CURRENTWORKGROUPSIZE";
    case BRIG_OPCODE_CVT                : return "BRIG_OPCODE_CVT";
    case BRIG_OPCODE_DEBUGTRAP          : return "BRIG_OPCODE_DEBUGTRAP";
    case BRIG_OPCODE_DIM                : return "BRIG_OPCODE_DIM";
    case BRIG_OPCODE_DISPATCHID         : return "BRIG_OPCODE_DISPATCHID";
    case BRIG_OPCODE_DISPATCHPTR        : return "BRIG_OPCODE_DISPATCHPTR";
    case BRIG_OPCODE_DIV                : return "BRIG_OPCODE_DIV";
    case BRIG_OPCODE_EXPAND             : return "BRIG_OPCODE_EXPAND";
    case BRIG_OPCODE_FIRSTBIT           : return "BRIG_OPCODE_FIRSTBIT";
    case BRIG_OPCODE_FLOOR              : return "BRIG_OPCODE_FLOOR";
    case BRIG_OPCODE_FMA                : return "BRIG_OPCODE_FMA";
    case BRIG_OPCODE_FRACT              : return "BRIG_OPCODE_FRACT";
    case BRIG_OPCODE_FTOS               : return "BRIG_OPCODE_FTOS";
    case BRIG_OPCODE_GETDETECTEXCEPT    : return "BRIG_OPCODE_GETDETECTEXCEPT";
    case BRIG_OPCODE_GRIDGROUPS         : return "BRIG_OPCODE_GRIDGROUPS";
    case BRIG_OPCODE_GRIDSIZE           : return "BRIG_OPCODE_GRIDSIZE";
    case BRIG_OPCODE_INITFBAR           : return "BRIG_OPCODE_INITFBAR";
    case BRIG_OPCODE_JOINFBAR           : return "BRIG_OPCODE_JOINFBAR";
    case BRIG_OPCODE_LANEID             : return "BRIG_OPCODE_LANEID";
    case BRIG_OPCODE_LASTBIT            : return "BRIG_OPCODE_LASTBIT";
    case BRIG_OPCODE_LD                 : return "BRIG_OPCODE_LD";
    case BRIG_OPCODE_LDA                : return "BRIG_OPCODE_LDA";
    case BRIG_OPCODE_LDC                : return "BRIG_OPCODE_LDC";
    case BRIG_OPCODE_LDF                : return "BRIG_OPCODE_LDF";
    case BRIG_OPCODE_LDIMAGE            : return "BRIG_OPCODE_LDIMAGE";
    case BRIG_OPCODE_LEAVEFBAR          : return "BRIG_OPCODE_LEAVEFBAR";
    case BRIG_OPCODE_LERP               : return "BRIG_OPCODE_LERP";
    case BRIG_OPCODE_MAD                : return "BRIG_OPCODE_MAD";
    case BRIG_OPCODE_MAD24              : return "BRIG_OPCODE_MAD24";
    case BRIG_OPCODE_MAD24HI            : return "BRIG_OPCODE_MAD24HI";
    case BRIG_OPCODE_MASKLANE           : return "BRIG_OPCODE_MASKLANE";
    case BRIG_OPCODE_MAX                : return "BRIG_OPCODE_MAX";
    case BRIG_OPCODE_MAXCUID            : return "BRIG_OPCODE_MAXCUID";
    case BRIG_OPCODE_MAXWAVEID          : return "BRIG_OPCODE_MAXWAVEID";
    case BRIG_OPCODE_MIN                : return "BRIG_OPCODE_MIN";
    case BRIG_OPCODE_MOV                : return "BRIG_OPCODE_MOV";
    case BRIG_OPCODE_MUL                : return "BRIG_OPCODE_MUL";
    case BRIG_OPCODE_MUL24              : return "BRIG_OPCODE_MUL24";
    case BRIG_OPCODE_MUL24HI            : return "BRIG_OPCODE_MUL24HI";
    case BRIG_OPCODE_MULHI              : return "BRIG_OPCODE_MULHI";
    case BRIG_OPCODE_NCOS               : return "BRIG_OPCODE_NCOS";
    case BRIG_OPCODE_NEG                : return "BRIG_OPCODE_NEG";
    case BRIG_OPCODE_NEXP2              : return "BRIG_OPCODE_NEXP2";
    case BRIG_OPCODE_NFMA               : return "BRIG_OPCODE_NFMA";
    case BRIG_OPCODE_NLOG2              : return "BRIG_OPCODE_NLOG2";
    case BRIG_OPCODE_NOP                : return "BRIG_OPCODE_NOP";
    case BRIG_OPCODE_NOT                : return "BRIG_OPCODE_NOT";
    case BRIG_OPCODE_NRCP               : return "BRIG_OPCODE_NRCP";
    case BRIG_OPCODE_NRSQRT             : return "BRIG_OPCODE_NRSQRT";
    case BRIG_OPCODE_NSIN               : return "BRIG_OPCODE_NSIN";
    case BRIG_OPCODE_NSQRT              : return "BRIG_OPCODE_NSQRT";
    case BRIG_OPCODE_NULLPTR            : return "BRIG_OPCODE_NULLPTR";
    case BRIG_OPCODE_OR                 : return "BRIG_OPCODE_OR";
    case BRIG_OPCODE_PACK               : return "BRIG_OPCODE_PACK";
    case BRIG_OPCODE_PACKCVT            : return "BRIG_OPCODE_PACKCVT";
    case BRIG_OPCODE_POPCOUNT           : return "BRIG_OPCODE_POPCOUNT";
    case BRIG_OPCODE_QID                : return "BRIG_OPCODE_QID";
    case BRIG_OPCODE_QPTR               : return "BRIG_OPCODE_QPTR";
    case BRIG_OPCODE_QUERYIMAGEARRAY    : return "BRIG_OPCODE_QUERYIMAGEARRAY";
    case BRIG_OPCODE_QUERYIMAGEDEPTH    : return "BRIG_OPCODE_QUERYIMAGEDEPTH";
    case BRIG_OPCODE_QUERYIMAGEFORMAT   : return "BRIG_OPCODE_QUERYIMAGEFORMAT";
    case BRIG_OPCODE_QUERYIMAGEHEIGHT   : return "BRIG_OPCODE_QUERYIMAGEHEIGHT";
    case BRIG_OPCODE_QUERYIMAGEORDER    : return "BRIG_OPCODE_QUERYIMAGEORDER";
    case BRIG_OPCODE_QUERYIMAGEWIDTH    : return "BRIG_OPCODE_QUERYIMAGEWIDTH";
    case BRIG_OPCODE_QUERYSAMPLERCOORD  : return "BRIG_OPCODE_QUERYSAMPLERCOORD";
    case BRIG_OPCODE_QUERYSAMPLERFILTER : return "BRIG_OPCODE_QUERYSAMPLERFILTER";
    case BRIG_OPCODE_RDIMAGE            : return "BRIG_OPCODE_RDIMAGE";
    case BRIG_OPCODE_RECEIVELANE        : return "BRIG_OPCODE_RECEIVELANE";
    case BRIG_OPCODE_RELEASEFBAR        : return "BRIG_OPCODE_RELEASEFBAR";
    case BRIG_OPCODE_REM                : return "BRIG_OPCODE_REM";
    case BRIG_OPCODE_RET                : return "BRIG_OPCODE_RET";
    case BRIG_OPCODE_RINT               : return "BRIG_OPCODE_RINT";
    case BRIG_OPCODE_SAD                : return "BRIG_OPCODE_SAD";
    case BRIG_OPCODE_SADHI              : return "BRIG_OPCODE_SADHI";
    case BRIG_OPCODE_SEGMENTP           : return "BRIG_OPCODE_SEGMENTP";
    case BRIG_OPCODE_SENDLANE           : return "BRIG_OPCODE_SENDLANE";
    case BRIG_OPCODE_SETDETECTEXCEPT    : return "BRIG_OPCODE_SETDETECTEXCEPT";
    case BRIG_OPCODE_SHL                : return "BRIG_OPCODE_SHL";
    case BRIG_OPCODE_SHR                : return "BRIG_OPCODE_SHR";
    case BRIG_OPCODE_SHUFFLE            : return "BRIG_OPCODE_SHUFFLE";
    case BRIG_OPCODE_SQRT               : return "BRIG_OPCODE_SQRT";
    case BRIG_OPCODE_ST                 : return "BRIG_OPCODE_ST";
    case BRIG_OPCODE_STIMAGE            : return "BRIG_OPCODE_STIMAGE";
    case BRIG_OPCODE_STOF               : return "BRIG_OPCODE_STOF";
    case BRIG_OPCODE_SUB                : return "BRIG_OPCODE_SUB";
    case BRIG_OPCODE_SYNC               : return "BRIG_OPCODE_SYNC";
    case BRIG_OPCODE_SYSCALL            : return "BRIG_OPCODE_SYSCALL";
    case BRIG_OPCODE_TRUNC              : return "BRIG_OPCODE_TRUNC";
    case BRIG_OPCODE_UNPACK             : return "BRIG_OPCODE_UNPACK";
    case BRIG_OPCODE_UNPACKCVT          : return "BRIG_OPCODE_UNPACKCVT";
    case BRIG_OPCODE_UNPACKHI           : return "BRIG_OPCODE_UNPACKHI";
    case BRIG_OPCODE_UNPACKLO           : return "BRIG_OPCODE_UNPACKLO";
    case BRIG_OPCODE_WAITFBAR           : return "BRIG_OPCODE_WAITFBAR";
    case BRIG_OPCODE_WAVEID             : return "BRIG_OPCODE_WAVEID";
    case BRIG_OPCODE_WORKGROUPID        : return "BRIG_OPCODE_WORKGROUPID";
    case BRIG_OPCODE_WORKGROUPSIZE      : return "BRIG_OPCODE_WORKGROUPSIZE";
    case BRIG_OPCODE_WORKITEMABSID      : return "BRIG_OPCODE_WORKITEMABSID";
    case BRIG_OPCODE_WORKITEMFLATABSID  : return "BRIG_OPCODE_WORKITEMFLATABSID";
    case BRIG_OPCODE_WORKITEMFLATID     : return "BRIG_OPCODE_WORKITEMFLATID";
    case BRIG_OPCODE_WORKITEMID         : return "BRIG_OPCODE_WORKITEMID";
    case BRIG_OPCODE_XOR                : return "BRIG_OPCODE_XOR";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigOperandKinds arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPERAND_ADDRESS           : return "BRIG_OPERAND_ADDRESS";
    case BRIG_OPERAND_ARGUMENT_LIST     : return "BRIG_OPERAND_ARGUMENT_LIST";
    case BRIG_OPERAND_ARGUMENT_REF      : return "BRIG_OPERAND_ARGUMENT_REF";
    case BRIG_OPERAND_FBARRIER_REF      : return "BRIG_OPERAND_FBARRIER_REF";
    case BRIG_OPERAND_FUNCTION_LIST     : return "BRIG_OPERAND_FUNCTION_LIST";
    case BRIG_OPERAND_FUNCTION_REF      : return "BRIG_OPERAND_FUNCTION_REF";
    case BRIG_OPERAND_IMMED             : return "BRIG_OPERAND_IMMED";
    case BRIG_OPERAND_LABEL_REF         : return "BRIG_OPERAND_LABEL_REF";
    case BRIG_OPERAND_REG               : return "BRIG_OPERAND_REG";
    case BRIG_OPERAND_REG_VECTOR        : return "BRIG_OPERAND_REG_VECTOR";
    case BRIG_OPERAND_SIGNATURE_REF     : return "BRIG_OPERAND_SIGNATURE_REF";
    case BRIG_OPERAND_WAVESIZE          : return "BRIG_OPERAND_WAVESIZE";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigPack arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_PACK_NONE                 : return "BRIG_PACK_NONE";
    case BRIG_PACK_P                    : return "BRIG_PACK_P";
    case BRIG_PACK_PP                   : return "BRIG_PACK_PP";
    case BRIG_PACK_PPSAT                : return "BRIG_PACK_PPSAT";
    case BRIG_PACK_PS                   : return "BRIG_PACK_PS";
    case BRIG_PACK_PSAT                 : return "BRIG_PACK_PSAT";
    case BRIG_PACK_PSSAT                : return "BRIG_PACK_PSSAT";
    case BRIG_PACK_S                    : return "BRIG_PACK_S";
    case BRIG_PACK_SP                   : return "BRIG_PACK_SP";
    case BRIG_PACK_SPSAT                : return "BRIG_PACK_SPSAT";
    case BRIG_PACK_SS                   : return "BRIG_PACK_SS";
    case BRIG_PACK_SSAT                 : return "BRIG_PACK_SSAT";
    case BRIG_PACK_SSSAT                : return "BRIG_PACK_SSSAT";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigProfile arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_PROFILE_BASE              : return "BRIG_PROFILE_BASE";
    case BRIG_PROFILE_FULL              : return "BRIG_PROFILE_FULL";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigRound arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_ROUND_FLOAT_MINUS_INFINITY : return "BRIG_ROUND_FLOAT_MINUS_INFINITY";
    case BRIG_ROUND_FLOAT_NEAR_EVEN     : return "BRIG_ROUND_FLOAT_NEAR_EVEN";
    case BRIG_ROUND_FLOAT_PLUS_INFINITY : return "BRIG_ROUND_FLOAT_PLUS_INFINITY";
    case BRIG_ROUND_FLOAT_ZERO          : return "BRIG_ROUND_FLOAT_ZERO";
    case BRIG_ROUND_INTEGER_MINUS_INFINITY : return "BRIG_ROUND_INTEGER_MINUS_INFINITY";
    case BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT : return "BRIG_ROUND_INTEGER_MINUS_INFINITY_SAT";
    case BRIG_ROUND_INTEGER_NEAR_EVEN   : return "BRIG_ROUND_INTEGER_NEAR_EVEN";
    case BRIG_ROUND_INTEGER_NEAR_EVEN_SAT : return "BRIG_ROUND_INTEGER_NEAR_EVEN_SAT";
    case BRIG_ROUND_INTEGER_PLUS_INFINITY : return "BRIG_ROUND_INTEGER_PLUS_INFINITY";
    case BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT : return "BRIG_ROUND_INTEGER_PLUS_INFINITY_SAT";
    case BRIG_ROUND_INTEGER_ZERO        : return "BRIG_ROUND_INTEGER_ZERO";
    case BRIG_ROUND_INTEGER_ZERO_SAT    : return "BRIG_ROUND_INTEGER_ZERO_SAT";
    case BRIG_ROUND_NONE                : return "BRIG_ROUND_NONE";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigSamplerBoundaryMode arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_BOUNDARY_BORDER           : return "BRIG_BOUNDARY_BORDER";
    case BRIG_BOUNDARY_CLAMP            : return "BRIG_BOUNDARY_CLAMP";
    case BRIG_BOUNDARY_MIRROR           : return "BRIG_BOUNDARY_MIRROR";
    case BRIG_BOUNDARY_MIRRORONCE       : return "BRIG_BOUNDARY_MIRRORONCE";
    case BRIG_BOUNDARY_WRAP             : return "BRIG_BOUNDARY_WRAP";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigSamplerFilter arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_FILTER_LINEAR             : return "BRIG_FILTER_LINEAR";
    case BRIG_FILTER_NEAREST            : return "BRIG_FILTER_NEAREST";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigSegment arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_SEGMENT_ARG               : return "BRIG_SEGMENT_ARG";
    case BRIG_SEGMENT_EXTSPACE0         : return "BRIG_SEGMENT_EXTSPACE0";
    case BRIG_SEGMENT_FLAT              : return "BRIG_SEGMENT_FLAT";
    case BRIG_SEGMENT_GLOBAL            : return "BRIG_SEGMENT_GLOBAL";
    case BRIG_SEGMENT_GROUP             : return "BRIG_SEGMENT_GROUP";
    case BRIG_SEGMENT_KERNARG           : return "BRIG_SEGMENT_KERNARG";
    case BRIG_SEGMENT_NONE              : return "BRIG_SEGMENT_NONE";
    case BRIG_SEGMENT_PRIVATE           : return "BRIG_SEGMENT_PRIVATE";
    case BRIG_SEGMENT_READONLY          : return "BRIG_SEGMENT_READONLY";
    case BRIG_SEGMENT_SPILL             : return "BRIG_SEGMENT_SPILL";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigTypeX arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_TYPE_B1                   : return "BRIG_TYPE_B1";
    case BRIG_TYPE_B128                 : return "BRIG_TYPE_B128";
    case BRIG_TYPE_B16                  : return "BRIG_TYPE_B16";
    case BRIG_TYPE_B32                  : return "BRIG_TYPE_B32";
    case BRIG_TYPE_B64                  : return "BRIG_TYPE_B64";
    case BRIG_TYPE_B8                   : return "BRIG_TYPE_B8";
    case BRIG_TYPE_F16                  : return "BRIG_TYPE_F16";
    case BRIG_TYPE_F16X2                : return "BRIG_TYPE_F16X2";
    case BRIG_TYPE_F16X4                : return "BRIG_TYPE_F16X4";
    case BRIG_TYPE_F16X8                : return "BRIG_TYPE_F16X8";
    case BRIG_TYPE_F32                  : return "BRIG_TYPE_F32";
    case BRIG_TYPE_F32X2                : return "BRIG_TYPE_F32X2";
    case BRIG_TYPE_F32X4                : return "BRIG_TYPE_F32X4";
    case BRIG_TYPE_F64                  : return "BRIG_TYPE_F64";
    case BRIG_TYPE_F64X2                : return "BRIG_TYPE_F64X2";
    case BRIG_TYPE_FBAR                 : return "BRIG_TYPE_FBAR";
    case BRIG_TYPE_NONE                 : return "BRIG_TYPE_NONE";
    case BRIG_TYPE_ROIMG                : return "BRIG_TYPE_ROIMG";
    case BRIG_TYPE_RWIMG                : return "BRIG_TYPE_RWIMG";
    case BRIG_TYPE_S16                  : return "BRIG_TYPE_S16";
    case BRIG_TYPE_S16X2                : return "BRIG_TYPE_S16X2";
    case BRIG_TYPE_S16X4                : return "BRIG_TYPE_S16X4";
    case BRIG_TYPE_S16X8                : return "BRIG_TYPE_S16X8";
    case BRIG_TYPE_S32                  : return "BRIG_TYPE_S32";
    case BRIG_TYPE_S32X2                : return "BRIG_TYPE_S32X2";
    case BRIG_TYPE_S32X4                : return "BRIG_TYPE_S32X4";
    case BRIG_TYPE_S64                  : return "BRIG_TYPE_S64";
    case BRIG_TYPE_S64X2                : return "BRIG_TYPE_S64X2";
    case BRIG_TYPE_S8                   : return "BRIG_TYPE_S8";
    case BRIG_TYPE_S8X16                : return "BRIG_TYPE_S8X16";
    case BRIG_TYPE_S8X4                 : return "BRIG_TYPE_S8X4";
    case BRIG_TYPE_S8X8                 : return "BRIG_TYPE_S8X8";
    case BRIG_TYPE_SAMP                 : return "BRIG_TYPE_SAMP";
    case BRIG_TYPE_U16                  : return "BRIG_TYPE_U16";
    case BRIG_TYPE_U16X2                : return "BRIG_TYPE_U16X2";
    case BRIG_TYPE_U16X4                : return "BRIG_TYPE_U16X4";
    case BRIG_TYPE_U16X8                : return "BRIG_TYPE_U16X8";
    case BRIG_TYPE_U32                  : return "BRIG_TYPE_U32";
    case BRIG_TYPE_U32X2                : return "BRIG_TYPE_U32X2";
    case BRIG_TYPE_U32X4                : return "BRIG_TYPE_U32X4";
    case BRIG_TYPE_U64                  : return "BRIG_TYPE_U64";
    case BRIG_TYPE_U64X2                : return "BRIG_TYPE_U64X2";
    case BRIG_TYPE_U8                   : return "BRIG_TYPE_U8";
    case BRIG_TYPE_U8X16                : return "BRIG_TYPE_U8X16";
    case BRIG_TYPE_U8X4                 : return "BRIG_TYPE_U8X4";
    case BRIG_TYPE_U8X8                 : return "BRIG_TYPE_U8X8";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::BrigWidth arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_WIDTH_1                   : return "BRIG_WIDTH_1";
    case BRIG_WIDTH_1024                : return "BRIG_WIDTH_1024";
    case BRIG_WIDTH_1048576             : return "BRIG_WIDTH_1048576";
    case BRIG_WIDTH_1073741824          : return "BRIG_WIDTH_1073741824";
    case BRIG_WIDTH_128                 : return "BRIG_WIDTH_128";
    case BRIG_WIDTH_131072              : return "BRIG_WIDTH_131072";
    case BRIG_WIDTH_134217728           : return "BRIG_WIDTH_134217728";
    case BRIG_WIDTH_16                  : return "BRIG_WIDTH_16";
    case BRIG_WIDTH_16384               : return "BRIG_WIDTH_16384";
    case BRIG_WIDTH_16777216            : return "BRIG_WIDTH_16777216";
    case BRIG_WIDTH_2                   : return "BRIG_WIDTH_2";
    case BRIG_WIDTH_2048                : return "BRIG_WIDTH_2048";
    case BRIG_WIDTH_2097152             : return "BRIG_WIDTH_2097152";
    case BRIG_WIDTH_2147483648          : return "BRIG_WIDTH_2147483648";
    case BRIG_WIDTH_256                 : return "BRIG_WIDTH_256";
    case BRIG_WIDTH_262144              : return "BRIG_WIDTH_262144";
    case BRIG_WIDTH_268435456           : return "BRIG_WIDTH_268435456";
    case BRIG_WIDTH_32                  : return "BRIG_WIDTH_32";
    case BRIG_WIDTH_32768               : return "BRIG_WIDTH_32768";
    case BRIG_WIDTH_33554432            : return "BRIG_WIDTH_33554432";
    case BRIG_WIDTH_4                   : return "BRIG_WIDTH_4";
    case BRIG_WIDTH_4096                : return "BRIG_WIDTH_4096";
    case BRIG_WIDTH_4194304             : return "BRIG_WIDTH_4194304";
    case BRIG_WIDTH_512                 : return "BRIG_WIDTH_512";
    case BRIG_WIDTH_524288              : return "BRIG_WIDTH_524288";
    case BRIG_WIDTH_536870912           : return "BRIG_WIDTH_536870912";
    case BRIG_WIDTH_64                  : return "BRIG_WIDTH_64";
    case BRIG_WIDTH_65536               : return "BRIG_WIDTH_65536";
    case BRIG_WIDTH_67108864            : return "BRIG_WIDTH_67108864";
    case BRIG_WIDTH_8                   : return "BRIG_WIDTH_8";
    case BRIG_WIDTH_8192                : return "BRIG_WIDTH_8192";
    case BRIG_WIDTH_8388608             : return "BRIG_WIDTH_8388608";
    case BRIG_WIDTH_ALL                 : return "BRIG_WIDTH_ALL";
    case BRIG_WIDTH_NONE                : return "BRIG_WIDTH_NONE";
    case BRIG_WIDTH_WAVESIZE            : return "BRIG_WIDTH_WAVESIZE";
    default : return "??";
    }
}

const char* anyEnum2str( Brig::OldGcnOpcodes arg ) {
  using namespace Brig;
  switch( arg ) {
    case BRIG_OPCODE_GCNAPPEND          : return "BRIG_OPCODE_GCNAPPEND";
    case BRIG_OPCODE_GCNATOMIC          : return "BRIG_OPCODE_GCNATOMIC";
    case BRIG_OPCODE_GCNATOMICNORET     : return "BRIG_OPCODE_GCNATOMICNORET";
    case BRIG_OPCODE_GCNB32XCHG         : return "BRIG_OPCODE_GCNB32XCHG";
    case BRIG_OPCODE_GCNB4XCHG          : return "BRIG_OPCODE_GCNB4XCHG";
    case BRIG_OPCODE_GCNBFM             : return "BRIG_OPCODE_GCNBFM";
    case BRIG_OPCODE_GCNCONSUME         : return "BRIG_OPCODE_GCNCONSUME";
    case BRIG_OPCODE_GCNFLDEXP          : return "BRIG_OPCODE_GCNFLDEXP";
    case BRIG_OPCODE_GCNFREXP_EXP       : return "BRIG_OPCODE_GCNFREXP_EXP";
    case BRIG_OPCODE_GCNFREXP_MANT      : return "BRIG_OPCODE_GCNFREXP_MANT";
    case BRIG_OPCODE_GCNLD              : return "BRIG_OPCODE_GCNLD";
    case BRIG_OPCODE_GCNMADS            : return "BRIG_OPCODE_GCNMADS";
    case BRIG_OPCODE_GCNMADU            : return "BRIG_OPCODE_GCNMADU";
    case BRIG_OPCODE_GCNMAX3            : return "BRIG_OPCODE_GCNMAX3";
    case BRIG_OPCODE_GCNMED3            : return "BRIG_OPCODE_GCNMED3";
    case BRIG_OPCODE_GCNMIN3            : return "BRIG_OPCODE_GCNMIN3";
    case BRIG_OPCODE_GCNMQSAD           : return "BRIG_OPCODE_GCNMQSAD";
    case BRIG_OPCODE_GCNMQSAD4          : return "BRIG_OPCODE_GCNMQSAD4";
    case BRIG_OPCODE_GCNMSAD            : return "BRIG_OPCODE_GCNMSAD";
    case BRIG_OPCODE_GCNPRIORITY        : return "BRIG_OPCODE_GCNPRIORITY";
    case BRIG_OPCODE_GCNQSAD            : return "BRIG_OPCODE_GCNQSAD";
    case BRIG_OPCODE_GCNREGIONALLOC     : return "BRIG_OPCODE_GCNREGIONALLOC";
    case BRIG_OPCODE_GCNSADD            : return "BRIG_OPCODE_GCNSADD";
    case BRIG_OPCODE_GCNSADW            : return "BRIG_OPCODE_GCNSADW";
    case BRIG_OPCODE_GCNSLEEP           : return "BRIG_OPCODE_GCNSLEEP";
    case BRIG_OPCODE_GCNST              : return "BRIG_OPCODE_GCNST";
    case BRIG_OPCODE_GCNTRIG_PREOP      : return "BRIG_OPCODE_GCNTRIG_PREOP";
    default : return "??";
    }
}

