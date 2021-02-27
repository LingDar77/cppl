#ifndef F3372930_73E9_4B96_985D_7001FE7943C2
#define F3372930_73E9_4B96_985D_7001FE7943C2

//? tuple type
#include <tuple>
#include <iostream>
//? tuple is a little similar to pair
//? it can have any types with any amount inside it
void test1()
{
    std::tuple<int, std::string, double> t(1, "asd", 3.14);

    int i = std::get<0>(t);
    std::string s = std::get<1>(t);
    double d = std::get<2>(t);
    std::cout << s << std::endl;

    //* if we do not know the accurate types or size,
    //* we can use decltype with tuple_element and tuple_size
    size_t size = std::tuple_size<decltype(t)>::value;
    std::tuple_element<0, decltype(t)>::type e = std::get<0>(t);
    std::cout << e << std::endl;
}
float ff(float n)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;
    x2 = n * 0.5F;
    y = n;
    i = *(long *)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y));
    return y;
}

//! regular expressions

//! random-number engines and random-number distributions
#include <random>
#include <ctime>
#include <cmath>
#include <string>



#endif /* F3372930_73E9_4B96_985D_7001FE7943C2 */
