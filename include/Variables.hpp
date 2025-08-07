#pragma once
#include <type_traits>
#include"Person.h"

//回答：为什么先抽类，而不是先抽指针
namespace detail
{

    template<typename T>
    struct variable_type{
        using type=T;
    };

    template< typename Class,typename T>
    struct variable_type<T Class::*>{
        using type=T;
    };

};//namespace detail

template<typename T>
using variable_type_without_class=typename detail::variable_type<T>::type ;

namespace internal
{

    template<typename T>
    struct basic_variable_traits{
        using type=variable_type_without_class<T>;
        static constexpr bool is_member=std::is_member_pointer_v<T>;
    };

};

///////



template<typename T>
struct variable_traits;

template<typename T>
struct variable_traits<T*>:internal::basic_variable_traits<T>
{
    using pointer_type=T *;
};
template<typename Class,typename T>
struct variable_traits<T Class::*>:internal::basic_variable_traits<T(Class::*)>
{
    using pointer_type=T*;
};



template<typename T>
auto variable_pointer_type_t(T)->T;

template<typename T,typename Class>
auto variable_pointer_type_t(T(Class::*))->T(Class::*);

template<auto V>
using variable_pointer_type= decltype(variable_pointer_type_t(V));

template<typename T>
struct FBaseVariable: variable_traits<T>
{
    FBaseVariable(T&& variable)
    :target(variable)
    {

    }

    T target;

    constexpr bool IsMember()
    {
        return variable_traits<T>::is_member;
    }
};








int test01()
{
    using pt=variable_traits<decltype(&Person::age)>;

    if(variable_traits<decltype(&Person::age)>::is_member){
        return 1;
    }
    else{
        return 2;
    }
    using type_in=pt::type;
//    static_assert(std::is_same_v<type_in ,int(Person::*)>,"different");
    std::cout<<(&Person::age)<<std::endl;
    std::cout<<(&Person::name)<<std::endl;

    return 0;
}







