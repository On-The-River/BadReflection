#include <iostream>
#include<string>
#include"../include/Variables.hpp"
#include"../include/Function.hpp"
#include"../include/Person.h"
#include "../include/Enum.h"
#include "../include/Primitive.h"
#include "../include/Factory.h"

template<typename Class>
struct FClassInfo;


#define BEGIN_CLASS(CLASS) template<> struct FClassInfo<CLASS>{

#define FUNCTIONS(...)  \
static constexpr auto Functions=std::make_tuple(__VA_ARGS__);

#define FUNCTION(FUNC) FBaseFunction{FUNC,#FUNC}


#define END_CLASS() };

BEGIN_CLASS(Person)
    FUNCTIONS(
            FUNCTION(&Person::test),
            FUNCTION(&Person::GetAge)
            )
END_CLASS()

enum class EKind
{
    Actor,
    Pawn,
    Character,
};

struct FName{
    std::string s;
};


int main()
{
//    test();
//    UEnum& Enum02=UEnumFactory<EAxis>::Instance().GetEnumRef();
//    std::cout<<Enum02.ToString()<<std::endl;

//
//    UPrimitive NewPrimitive =UPrimitiveFactory<char*>::Instance().GetPrimitiveRef();
//    std::cout<<NewPrimitive.GetName()<<std::endl;
//    std::cout<<NewPrimitive.IsPointer()<<std::endl;


    UPrimitive& Prim=UFactory<int*>::Instance().GetPrimitiveRef();
    std::cout<<Prim.IsPointer()<<std::endl;

    std::cout<<Prim.GetName()<<std::endl;

    UType* Type= UFactory<int*>::GetType();
    std::cout<<Type->GetName()<<std::endl;

//    static_assert(std::);



//    UEnumFactory<EKind>::Instance().Register("EKind").Add("Actor",EKind::Actor)
//    .Add("Pawn",EKind::Pawn)
//    .Add("Character",EKind::Character);
//
//    UEnum& Enum01=UEnumFactory<EKind>::Instance().GetEnumRef();
//
//    auto Items=Enum01.GetItemsConst();
//
//    std::cout<<'-'<<Enum01.GetName()<<'-'<<std::endl;
//
//    for(auto a:Items){
//        std::cout<<a.Name<<" - "<<a.Value<<std::endl;
//    }


//    FClassInfo<Person> ClassPerson;
//    auto& Functions=ClassPerson.Functions;
//    FBaseFunction function=std::get<0>(Functions);
//    std::cout<<function.GetName()<<std::endl;

}