//notes.h
//! when we assign a lvalue to rvalue(i) reference argument(T&&,T&)
//* T will be inferred its reference
//* for example
template <typename T>
auto exp1(T &&t) -> decltype(t)
{
    //is this fied, when a lvalue was assgined, T was inferred its reference;

    return ++t;
}
//this rule cases two results
//! if a parameter of a function is a rvalue referrence(T&&)
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