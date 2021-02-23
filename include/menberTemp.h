#ifndef E75BAE8A_378F_4FA0_8C95_8AAA6752EF0F
#define E75BAE8A_378F_4FA0_8C95_8AAA6752EF0F
#include <iostream>
class debugDel
{
public:
    debugDel(std::ostream &os = std::cerr) : o(os){};
    template <typename T>
    void operator()(T *p) const
    {
        o << "deleting pointer!" << std::endl;
        delete p;
    }

private:
    std::ostream &o;
};

#endif /* E75BAE8A_378F_4FA0_8C95_8AAA6752EF0F */
