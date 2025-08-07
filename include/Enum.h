//
// Created by dell on 2025/7/30.
//

#ifndef REFLECTION_ENUM_H
#define REFLECTION_ENUM_H



#include <utility>
#include <vector>
#include <string>
#include "Type.hpp"





class UEnum : public UType{

protected:

    using ItemNameType=std::string;
    using ItemValueType=short;

public:
    struct Item {
        Item(ItemNameType name, ItemValueType value) : Name(std::move(name)), Value(value)
        {}

        ItemNameType Name;
        ItemValueType Value;
    };

    std::string ToString()
    {
        std::string Content;

        Content+="-";
        Content+=TypeName;
        Content+="-\n";

        for(auto& a:Items)
        {
            Content+=a.Name;
            Content+=" ";
            Content+=a.Value;
            Content+="\n";
        }


        return Content;
    }

public:

    UEnum()
    : UType(UType::Enum)
    {

    }


    template<typename T>
    inline UEnum& Add(const ItemNameType& InName,T InValue)
    {
        return Add_Impl(InName,InValue);
    }


    //getters
    virtual std::string GetName() const{return TypeName;}

    std::vector<Item> GetItems()const{return Items;}

    const std::vector<Item>& GetItemsConst() const{ return Items; }


protected:

    template<typename T>
    friend class UEnumFactory;
    //the type's name.
    std::string TypeName;

    std::vector<Item> Items;

    template<typename T>
    UEnum& Add_Impl(const ItemNameType& InName,T InValue)
    {
        Items.emplace_back(InName,static_cast<ItemValueType>(InValue));
        return *this;
    }
};





template<typename T>
class UEnumFactory// : public UFactory<T>
{
public:
    static UEnumFactory& Instance()
    {
        static UEnumFactory Singleon;
        Singleon.Enum.PostConstruct<T>();
        return Singleon;
    }


    //Call by Instance().{ThisMethod}()
    UEnum& GetEnumRef()
    {
        return Enum;
    }
    UEnum GetEnum()
    {
        return Enum;
    }

    auto& Get()
    {
        return Enum;
    }


    UEnum& Register(const std::string TypeName)
    {
        Enum.TypeName=TypeName;
        return Enum;
    }


protected:
    UEnumFactory()
    {

    }

    UEnum Enum;

};

#define UEnumRegister(X) UEnumFactory<X>::Instance().Register(#X)
#define AddItem(Value) Add(#Value,Value)


enum class EAxis{
    X,
    Y,
    Z,

};

//int test(){
//    UEnumRegister(EAxis).AddItem(EAxis::X).AddItem(EAxis::Y).AddItem(EAxis::Z);
//    return 0;
//}

#endif //REFLECTION_ENUM_H