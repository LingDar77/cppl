//notes.h
//! when we assign a lvalue to rvalue(i) reference argument(T&&,T&)
//* T will be inferred its reference
//* for example
template <typename T>
auto exp1(T &&t) -> decltype(t)
{
    //is this field, when a lvalue was assigned, T was inferred its reference;

    return ++t;
}
//this rule cases two results
//! if a parameter of a function is a rvalue reference(T&&)
//it could be bound to a lvalue
//! besides, if the argument is a lvalue, the parameter will be inferred lvalue reference
//? this shows that we can assign any argument to T&&
//in short,
//int to f(T t), T=int, int& to f(T t), T=int
//int to f(T &t), T= int&, int& to f(T &&t), T=int&&&(int&)
template <typename T>
auto f1(T t) -> decltype(t)
{
    return ++t;
}
template <typename T>
auto f2(T &t) -> decltype(t)
{
    return ++t;
}
template <typename T>
auto f3(T &&t) -> decltype(t)
{
    return ++t;
}

//std::forward<type> can keep T and argument left and right the same
template <typename F, typename T>
void f4(F f, T &&t)
{
    f(std::forward<T>(t));
}

//? variadic template is template class or template function accpets variadic parameters
//? these parameters called parameter packet
//? parameter packet contained template parameter packet which express some template parameters
//? and function parameter packter which express some function parameters
//! class... or typename... pointed that the following paraments express some types
//! typename/class T... pointed that the following paraments express some nontype paraments
//for example
template <typename T, typename... Args>
void f5(const T &t, const Args &...rest);
//* this is a variadic template function
//* Args express some extra type parameter
//* we can call f5(int,const int& const double&...)
//! we can use sizeof...(Args) to know how many paraments were assigned
template <typename... Args>
void f6(Args... args)
{
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(args) << std::endl;
}
//! variadic fuctions often use recursion


//? except get the size of the packet,
//? we also need to expand it
//* if we wanna expand a packet, we only need to add a ... folling the packet to get the list of its elements 


template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
    return os << t;
}
template <typename T, typename... args>
std::ostream &print(std::ostream &os, const T &t, const args &...rest)//! there we use const args&... to expand args
{
    os << t << ",";
    return print(os, rest...);//! there use rest... to expand
}




