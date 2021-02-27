#include <iostream>
#include <string>
#include "typeTransform.h"
#include "pool.h"
using namespace std;
#include <unordered_set>
#include <map>
int main(int argc, char const *argv[])
{
    pool p;
    map<std::string, unsigned> m;
    for (unsigned i = 0; i < 100; ++i)
    {
        ++m[p.pickOne()->print()];
    }
    std::cout << m["n"] << std::endl;
    std::cout << m["r"] << std::endl;
    std::cout << m["sr"] << std::endl;
    std::cout << m["ur"] << std::endl;
    return 0;
}
