//
// Created by dell on 2025/7/30.
//

#ifndef REFLECTION_PROPERTY_H
#define REFLECTION_PROPERTY_H

//#include "Type.hpp"

#include "Factory.h"
class UType;

//尚未完成
class UProperty
{
public:
    template<typename T>
    static UProperty Create();

public:
    const UType* GetType() const {return Type;}
    bool IsPointer() const {return Type->IsPointer();}

    auto GetValue()
    {

    }

protected:
    const UType* Type;
    void* VarP;


};



template<typename T>
UProperty UProperty::Create()
{
    UProperty Property;
    Property.Type=&(UFactory<T>::GetType());
    return Property;
}

#endif //REFLECTION_PROPERTY_H
