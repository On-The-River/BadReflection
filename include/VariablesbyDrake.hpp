#pragma once
#include <type_traits>


namespace member_getter
{
    template<typename T>
    struct is_member_s
    {
        static constexpr bool is_member=std::is_member_pointer_v<T>;
    };

};

namespace detail
{
    template<typename T>
    struct drop_class_s
    {
        using type=T;
    };

    template<typename Class,typename T>
    struct drop_class_s<T Class::*>
    {
        using type=T;
    };
};



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


namespace internal{
    template<typename T>
    struct variable_traits;

    template<typename T>
    struct variable_traits<T*>:internal::basic_variable_traits<T>
    {
        using pointer_type=T *;
    };


    template<typename Class,typename T>
    struct variable_traits<T Class::*>:internal::basic_variable_traits<T>
    {
        using pointer_type=T*;
    };
}








