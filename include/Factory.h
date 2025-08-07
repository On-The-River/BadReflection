//
// Created by dell on 2025/7/30.
//

#ifndef REFLECTION_FACTORY_H
#define REFLECTION_FACTORY_H
#include <type_traits>
#include "Primitive.h"
#include "Enum.h"



template<typename T>
class EmptyFactory
{
public:
    static EmptyFactory& Instance()
    {
        static EmptyFactory Factory;
        return Factory;
    }

    UType* Get(){return nullptr;}
};

template<typename T>
class UFactory
{
protected:

public:
    //when to use 'auto'? Confirm in compiler.
    static auto& Instance();

    static UType* GetType()
    {
        return &(UFactory<T>::Instance().Get());
    }

};



template<typename T>
auto &UFactory<T>::Instance()
{
    using PureT= typename std::remove_pointer<T>::type;

    if constexpr (std::is_fundamental_v<PureT>)
    {
        return UPrimitiveFactory<T>::Instance();
    }
    else if constexpr (std::is_enum_v<PureT>)
    {
        return UEnumFactory<T>::Instance();
    }
    else if constexpr (std::is_class_v<PureT>)
    {
        return EmptyFactory<T>::Instance();
    }
    else
    {
        return EmptyFactory<T>::Instance();
    }
}






#endif //REFLECTION_FACTORY_H
