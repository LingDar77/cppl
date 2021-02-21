//todo we can define a universal template to avoid define kindds of functions for every kind
template <typename T> //? typename T,... is a template parameter list which should not be empty
int compare(const T &t1, const T &t2)
{
    if (t1 < t2)
        return -1;
    if (t2 < t1)
        return 1;
    return 0;
}
//! besides we can use nontype parameter to express a value,but this parameter must be a const value
template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}
//! tmeplate can also be inline or constexpr but inline or constexpr should be put behind the temlate
//! besides, to program nontype code, we have to follow two laws:
//? parameters should be reference to const
//* use const reference makes sure our function can be used in types which can not be copy, and makes it faster
//? operators in function body can only use <
//* only use operator< can lower the request to this type, but actually we can use less<T> to define our function
template <class T>                 //? in template, class equals typename
int cmp(const T &t1, const T &t2) //! in this version, pointer can be alright
{
    if (less<T>(t1, t2))
        return -1;
    if (less<T>(t2, t1))
        return 1;
    //? less<T> will call <, so this version is not very well
    //? the two pointers point two different arrays, its behavers are undefined
    return 0;
}
//! btw, head files usually contain declarations and definations of template functions or template classes
