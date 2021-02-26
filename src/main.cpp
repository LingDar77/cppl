#include <iostream>
#include <string>
#include "typeTransform.h"
#include "notes.h"

using namespace std;
void tf(const int& i)
{
    cout<<i<<endl;
}
#include <unordered_set>
int main(int argc, char const *argv[])
{
    unordered_set<tc> ts;
    tc t1(1,"asd"),t2(-1,"dds");
    ts.insert(t1);
    ts.insert(t2);
    for(auto& i:ts)
        cout<<i<<endl;

    return 0;
}
