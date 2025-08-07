#ifndef REFLECTION_PRIMITIVE
#define REFLECTION_PRIMITIVE

#include<iostream>
#include<type_traits>
#include "Type.hpp"

template<typename T>
class UFactory;

class UPrimitive : public UType
{
public:
    enum EKind
    {
        None,
        Bool,
        Byte,
        Short,
        Int,
        Long,
        LongLong,
        Float,
        Double,
        Unknown
    };

public:

    template<typename T>
    static UPrimitive Create()
    {
        return UPrimitive(_DetectKind<T>());
    }


    UPrimitive(EKind Kind)
    :
    UType(UType::Primitive),Kind(Kind),TypeName(_GetNameByKind(Kind))
    {}

    virtual std::string GetName()const{return TypeName;}
    EKind GetKind(){return Kind;}


protected:

    std::string _GetNameByKind(EKind InKind)
    {
        switch (InKind)
        {
            case None:
                return "None";
            case Bool:
                return "Bool";
            case Byte:
                return "Byte";
            case Short:
                return "Short";
            case Int:
                return "Int";
            case Long:
                return "Long";
            case LongLong:
                return "LongLong";
            case Float:
                return "Float";
            case Double:
                return "Double";
            default:
                return "Unknown";
        }

    }

    template<typename T>
    friend class UFactory;


    template<typename T>
    static EKind _DetectKind()
    {
        using PureT=typename std::remove_pointer<T>::type;


        if(std::is_same_v<PureT ,bool>){
            return (Bool);
        }
        else if(std::is_same_v<PureT,char>){
            return (Byte);
        }
        else if(std::is_same_v<PureT,short>){
            return (Short);
        }
        else if(std::is_same_v<PureT,int>){
            return (Int);
        }
        else if(std::is_same_v<PureT,long>){
            return (Long);
        }
        else if(std::is_same_v<PureT,long long>){
            return (LongLong);
        }
        else if(std::is_same_v<PureT,float>){
            return (Float);
        }
        else if(std::is_same_v<PureT,double>){
            return (Double);
        }
        else{
            return (Unknown);
        }
    }

    std::string TypeName;
    EKind Kind;


};

template<typename T>
class UPrimitiveFactory// : public UFactory<T>
{
protected:
    UPrimitive Primitive;
public:
    static UPrimitiveFactory& Instance()
    {
        static UPrimitiveFactory Singleon{UPrimitive::Create<T>()};
        Singleon.Primitive.PostConstruct<T>();
        return Singleon;
    }

    UPrimitive GetPrimitive(){return Primitive;}
    UPrimitive& GetPrimitiveRef(){return Primitive;}

    auto& Get(){return Primitive;}

protected:



    UPrimitiveFactory(UPrimitive&& InPrimitive)
    : Primitive(InPrimitive)
    {

    }

};



#endif