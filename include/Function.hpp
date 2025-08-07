#include<iostream>
#include<type_traits>

template<typename T>
struct basic_function_traits
{
};

template<typename Ret,typename... Args>
struct basic_function_traits<Ret(Args...)>
{
    using return_type=Ret;
    using args=std::tuple<Args...>;

};
//函数信息封装类

template<typename T>
struct function_traits;

template<typename Ret,typename Class,typename ...Args>
struct function_traits<Ret(Class::*)(Args...)>:basic_function_traits<Ret(Args...)>
{

    using full_type=Ret(Class::*)(Args...);
    using args_with_class=std::tuple<Class*,Args...>;
    static constexpr bool is_member=true;
    static constexpr bool is_const=false;
};

template<typename Ret,typename Class,typename ...Args>
struct function_traits<Ret(Class::*)(Args...)const>:basic_function_traits<Ret(Args...)>
{

    using full_type=Ret(Class::*)(Args...);
    using args_with_class=std::tuple<Class*,Args...>;
    static constexpr bool is_member=true;
    static constexpr bool is_const=true;
};

template<typename Ret,typename ...Args>
struct function_traits<Ret(Args...)>:basic_function_traits<Ret(Args...)>
{

    using full_type=Ret(Args...);
    using args_with_class=std::tuple<Args...>;
    static constexpr bool is_member=false;
    static constexpr bool is_const=false;
};

template<typename Ret,typename ...Args>
struct function_traits<Ret(Args...)const>:basic_function_traits<Ret(Args...)>
{
    using full_type=Ret(Args...);
    using args_with_class=std::tuple<Args...>;
    static constexpr bool is_member=false;
    static constexpr bool is_const= true;
};

//之前写的这个不叫反射，叫类型萃取with wrapper

template<typename Ret, typename Class,typename ... Args>
auto function_pointer_type(Ret(Class::*)(Args...))->Ret(Class::*)(Args...);

template<typename Ret, typename Class,typename ... Args>
auto function_pointer_type(Ret(*)(Args...))->Ret(*)(Args...);

template<auto FUNCPTR>
using function_pointer_type_t= decltype(function_pointer_type(FUNCPTR));

template<auto FUNCPTR>
using FFunctionTraits=function_traits<function_pointer_type_t<FUNCPTR>>;

template<typename T>
struct FBaseFunction: function_traits<T>
{
    constexpr FBaseFunction(T&& function,std::string_view name)
    : Target(function),Name(name)
    {

    }

    T Target;

    std::string_view Name;

    constexpr std::string_view GetName()
    {
        return Name;
    }

    constexpr bool IsMember()
    {
        return function_traits<T>::is_member;
    }

    constexpr bool IsConst()
    {
        return function_traits<T>::is_const;
    }
};

int test02()
{
    return 0;
}
