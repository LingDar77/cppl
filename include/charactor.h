#ifndef B3C8D872_A312_4DA8_929B_FC8ECD6440C5
#define B3C8D872_A312_4DA8_929B_FC8ECD6440C5

namespace charactors
{



class charactor{
    private:
    char* name;
    public:
    virtual const char* getName()=0;
    virtual ~charactor()noexcept=0;
};
charactor::~charactor()noexcept{}



}
#endif /* B3C8D872_A312_4DA8_929B_FC8ECD6440C5 */
