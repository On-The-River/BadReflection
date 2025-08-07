////
//// Created by dell on 2025/7/30.
////
//
#include "Factory.h"
#include "Primitive.h"

//



//template<typename T>
//UFactory<T>& UFactory<T>::Instance()
//{
//    {
//        EKind Kind=_GetTKind();
//
//        switch (Kind)
//        {
//            case Class:
//                return UFactory<T>();//!!!
//                break;
//            case Enum:
//                return UEnumFactory<T>::Instance();
//            case Primitive:
//                return UPrimitiveFactory<T>::Instance();
//            default:
//                return UFactory<T>();
//        }
//    }
//}
//
//template<typename T>
//template<typename InT>
//bool UFactory<T>::_Is_Primitive_V()
//{
//    return (UPrimitive::_DetectKind<InT>()==UPrimitive::Unknown);
//}