#include <iostream>
#include <string>
#include "typeTransform.h"
#include "pool.h"
#include "charactor.h"
using namespace std;
#include <unordered_set>
#include <map>
#include <algorithm>
int main(int argc, char const *argv[])
{
    pool p;
    map<std::string, unsigned> m;
    vector<charactors::charactor *> vc;
    charactors::ue aUe;
    charactors::sorry as;
    charactors::test at;
    vc.push_back(&aUe);
    vc.push_back(&as);
    vc.push_back(&at);
    // std::sort(vc.begin(),vc.end(),charactors::comp);

    for (unsigned i = 0; i < 1000; ++i)
    {
        ++m[charactors::pickCharactor(vc)->getName()];
    }
    std::cout << "ue\\sorry\\test : " << m["ue"] << "\\" << m["sorry"] <<"\\" <<m["test"]<<std::endl;
    // std::cout << m["sr"] << std::endl;
    // std::cout << m["ur"] << std::endl;

    // string s;
    // cin>>s;
    return 0;
}
