template<typename RetType, typename Visitor>
RetType dispatchByType_gen(unsigned type, Visitor& v) {
  using namespace Brig;
  switch( type ) {
    case BRIG_TYPE_B1                   : return v.template visit< BrigType<BRIG_TYPE_B1> >();
    case BRIG_TYPE_B128                 : return v.template visit< BrigType<BRIG_TYPE_B128> >();
    case BRIG_TYPE_B16                  : return v.template visit< BrigType<BRIG_TYPE_B16> >();
    case BRIG_TYPE_B32                  : return v.template visit< BrigType<BRIG_TYPE_B32> >();
    case BRIG_TYPE_B64                  : return v.template visit< BrigType<BRIG_TYPE_B64> >();
    case BRIG_TYPE_B8                   : return v.template visit< BrigType<BRIG_TYPE_B8> >();
    case BRIG_TYPE_F16                  : return v.template visit< BrigType<BRIG_TYPE_F16> >();
    case BRIG_TYPE_F16X2                : return v.template visit< BrigType<BRIG_TYPE_F16X2> >();
    case BRIG_TYPE_F16X4                : return v.template visit< BrigType<BRIG_TYPE_F16X4> >();
    case BRIG_TYPE_F16X8                : return v.template visit< BrigType<BRIG_TYPE_F16X8> >();
    case BRIG_TYPE_F32                  : return v.template visit< BrigType<BRIG_TYPE_F32> >();
    case BRIG_TYPE_F32X2                : return v.template visit< BrigType<BRIG_TYPE_F32X2> >();
    case BRIG_TYPE_F32X4                : return v.template visit< BrigType<BRIG_TYPE_F32X4> >();
    case BRIG_TYPE_F64                  : return v.template visit< BrigType<BRIG_TYPE_F64> >();
    case BRIG_TYPE_F64X2                : return v.template visit< BrigType<BRIG_TYPE_F64X2> >();
    case BRIG_TYPE_S16                  : return v.template visit< BrigType<BRIG_TYPE_S16> >();
    case BRIG_TYPE_S16X2                : return v.template visit< BrigType<BRIG_TYPE_S16X2> >();
    case BRIG_TYPE_S16X4                : return v.template visit< BrigType<BRIG_TYPE_S16X4> >();
    case BRIG_TYPE_S16X8                : return v.template visit< BrigType<BRIG_TYPE_S16X8> >();
    case BRIG_TYPE_S32                  : return v.template visit< BrigType<BRIG_TYPE_S32> >();
    case BRIG_TYPE_S32X2                : return v.template visit< BrigType<BRIG_TYPE_S32X2> >();
    case BRIG_TYPE_S32X4                : return v.template visit< BrigType<BRIG_TYPE_S32X4> >();
    case BRIG_TYPE_S64                  : return v.template visit< BrigType<BRIG_TYPE_S64> >();
    case BRIG_TYPE_S64X2                : return v.template visit< BrigType<BRIG_TYPE_S64X2> >();
    case BRIG_TYPE_S8                   : return v.template visit< BrigType<BRIG_TYPE_S8> >();
    case BRIG_TYPE_S8X16                : return v.template visit< BrigType<BRIG_TYPE_S8X16> >();
    case BRIG_TYPE_S8X4                 : return v.template visit< BrigType<BRIG_TYPE_S8X4> >();
    case BRIG_TYPE_S8X8                 : return v.template visit< BrigType<BRIG_TYPE_S8X8> >();
    case BRIG_TYPE_U16                  : return v.template visit< BrigType<BRIG_TYPE_U16> >();
    case BRIG_TYPE_U16X2                : return v.template visit< BrigType<BRIG_TYPE_U16X2> >();
    case BRIG_TYPE_U16X4                : return v.template visit< BrigType<BRIG_TYPE_U16X4> >();
    case BRIG_TYPE_U16X8                : return v.template visit< BrigType<BRIG_TYPE_U16X8> >();
    case BRIG_TYPE_U32                  : return v.template visit< BrigType<BRIG_TYPE_U32> >();
    case BRIG_TYPE_U32X2                : return v.template visit< BrigType<BRIG_TYPE_U32X2> >();
    case BRIG_TYPE_U32X4                : return v.template visit< BrigType<BRIG_TYPE_U32X4> >();
    case BRIG_TYPE_U64                  : return v.template visit< BrigType<BRIG_TYPE_U64> >();
    case BRIG_TYPE_U64X2                : return v.template visit< BrigType<BRIG_TYPE_U64X2> >();
    case BRIG_TYPE_U8                   : return v.template visit< BrigType<BRIG_TYPE_U8> >();
    case BRIG_TYPE_U8X16                : return v.template visit< BrigType<BRIG_TYPE_U8X16> >();
    case BRIG_TYPE_U8X4                 : return v.template visit< BrigType<BRIG_TYPE_U8X4> >();
    case BRIG_TYPE_U8X8                 : return v.template visit< BrigType<BRIG_TYPE_U8X8> >();
    default : return v.visitNone(type);
    }
}

