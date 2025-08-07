//
// Created by dell on 2025/7/30.
//

#ifndef REFLECTION_TYPE_HPP
#define REFLECTION_TYPE_HPP

#include <string>
#include <type_traits>


class UEnum;
class UPrimitive;

class UType
{
protected:
    enum ETypeKind
    {
        None,
        Primitive,
        Enum,
    };
    ETypeKind TypeKind;


    bool bIsPointer;



public:

    UType(ETypeKind InKind)
    :TypeKind(InKind)
    {

    }


    UPrimitive* AsPrimitive(){return (UPrimitive*)this;}
    UEnum* AsEnum(){return (UEnum*)this;}

    virtual std::string GetName()const=0;
    ETypeKind GetTypeKind(){return TypeKind;}
    bool IsPointer() const {return bIsPointer;}

    template<typename T>
    void PostConstruct()
    {
        bIsPointer=std::is_pointer_v<T>;
    }

};

#endif //REFLECTION_TYPE_HPP
