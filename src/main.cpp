#include <iostream>
#include <string>
#include "Blob.h"
using namespace std;
int main(int argc, char const *argv[])
{
Blob<string> bi{"asd","add"};
bi.push_back("aaa");
cout<<(bi.front());


    return 0;
}

