#include <iostream>
#include <string>
#include "typeTransform.h"
#include "notes.h"

using namespace std;
void tf(const int& i)
{
    cout<<i<<endl;
}

int main(int argc, char const *argv[])
{
    int i=10;
    f4(tf,66);
    return 0;
}
