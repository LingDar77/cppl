//notes.h
//! when we assign a lvalue to rvalue(i) reference argument(T&&,T&)
//* T will be inferred its reference
//* for example

#ifndef FED24FFA_5D82_4EA6_B205_AC974182A6CA
#define FED24FFA_5D82_4EA6_B205_AC974182A6CA
#include <memory>
#include <cstring>
#include <iostream>
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
std::ostream &print(std::ostream &os, const T &t, const args &...rest) //! there we use const args&... to expand args
{
    os << t << ",";
    return print(os, rest...); //! there use rest... to expand
}

//? cpp still support more complex expand operation
template <typename T>
auto f7(T &t) -> decltype(t)
{
    return ++t;
}
template <typename... Args>
std::ostream &printp(std::ostream &os, Args &&...args)
{
    print(os, std::forward<Args>((args))...);
    // we expand f7(args) to get a list like f7(a1),f7(a2)...
    // still, if we wanna keep parameters the same as them were sent
    // we can use std::forward
    return os;
}
//? this solution may save little memory than recursion in some cases

template <typename T, typename... Args>
auto make_shared(Args &&...args) -> std::shared_ptr<T>
{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
} //pack args as a packet then send it to the constructors

//! template specialization
template <typename T>
int comp1(const T &t1, const T &t2)
{ //universal version
    return t1 < t2;
}
template <>
int comp1(const char *const &c1, const char *const &c2)
{ // special version, T was initialized as const char * or maybe char* const ?
    // essentially, this special version is an instance instead of an overridden one
    return strcmp(c1, c2);
}

template <typename T>
void testt(T const *t1)
{
    t1 = nullptr;
}

//! template class specialization

class tc
{
private:
public:
    bool operator==(const tc &t) const
    {
        return a == t.a;
    }
    tc() : a(0), s(""){};
    tc(int i, const std::string &str) : a(i), s(str){};
    int a;
    std::string s;
};
std::ostream &operator<<(std::ostream &os, const tc &t)
{
    os << t.a << " " << t.s;
    return os;
}
namespace std
{ //open namespace std to specialization hash
    template <>
    struct hash<tc>
    {
        typedef size_t result_type;
        typedef tc argument_type;
        size_t operator()(const tc &t) const;
    };
    size_t hash<tc>::operator()(const tc &t)const{
        return hash<int>()(t.a)^hash<string>()(t.s);
    }

}

//! template class partial specialization
//* we can only partial specialize template class or its class menber function









































#endif /* FED24FFA_5D82_4EA6_B205_AC974182A6CA */
