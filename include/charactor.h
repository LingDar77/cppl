#ifndef B3C8D872_A312_4DA8_929B_FC8ECD6440C5
#define B3C8D872_A312_4DA8_929B_FC8ECD6440C5
#include <set>
#include <pool.h>
namespace charactors
{
    //this interface is provide for being inherited from costumed charactors,
    //besides, costumed charactor still need to be inherited from a rarity  
    class charactor
    {
    private:
        char *name="unknown";
        size_t weight=0;
    public:
        virtual const char *getName()const = 0;
        virtual ~charactor() noexcept = 0;
        virtual size_t getWeight()const noexcept=0;
    };
        class sorry : public charactor, public ur
    {
    private:
        char *name;
        size_t weight;
    public:
        sorry() : name("sorry"),weight(990) {}
        ~sorry() noexcept {};
        const char *getName()const { return name; }
        size_t getWeight()const noexcept {return weight;}
    };
    class ue : public charactor, public ur
    {
    private:
        char *name;
        size_t weight;
    public:
        ue() : name("ue"),weight(5) {}
        ~ue() noexcept {};
        const char *getName()const { return name; }
        size_t getWeight()const noexcept {return weight;}
    };
        class test : public charactor, public ur
    {
    private:
        char *name;
        size_t weight;
    public:
        test() : name("test"),weight(5) {}
        ~test() noexcept {};
        const char *getName()const { return name; }
        size_t getWeight()const noexcept {return weight;}
    };
    charactor::~charactor() noexcept {}
    // pick a charactor from (sorted) charactor vector as its weight
    template <typename T>
    const charactor *pickCharactor(const std::vector<T *>& vT)
    {
        auto ret = vT[pickOne(vT)];
        return ret;
    }
        bool comp(const charactor* c1,const charactor* c2){return c1->getWeight()<c2->getWeight();}
}
#endif /* B3C8D872_A312_4DA8_929B_FC8ECD6440C5 */
