#include <type_traits>
//we can use remove_reference to get element's type
//also we have remove_pointer

template <typename T>
auto fcn(T beg) -> decltype(*beg)
{
    return *beg;
}
template <typename T>
auto fcn1(T beg) -> typename std::remove_reference<decltype(*beg)>::type
//! there use type name to tell the compiler remove_reference is a class
{
    return *beg;
}
template <typename T>
auto fcn2(T beg) -> typename std::remove_pointer<T>::type
{
    return *beg;
}
template <typename T, typename M>
auto sum(T a, M b) -> decltype(a + b)
{
    return a + b;
}