#ifndef DCF6203F_E946_4ECE_9997_67865E71C8B0
#define DCF6203F_E946_4ECE_9997_67865E71C8B0
#include <string>
#include <ctime>
#include <random>
#include <memory>
#include "charactor.h"
struct rarity
{
    virtual std::string print()const=0;
    virtual ~rarity()noexcept=0;
};
rarity::~rarity()noexcept{}
struct n : public rarity
{
    std::string print()const{ return "n"; }
    ~n()noexcept{};
};
struct r : public rarity
{
    std::string print()const{ return "r"; }
    ~r()noexcept{};
};
struct sr : public rarity
{
    std::string print()const{ return "sr"; }
    ~sr()noexcept{};
};
struct ur : public rarity
{
    std::string print()const{ return "ur"; }
    ~ur()noexcept{};
};
class pool
{
private:
    std::normal_distribution<> ni{0, 1}; //65 95 99.7
    std::default_random_engine e;

public:
    pool() { e.seed(time(0)); };
    const std::shared_ptr<rarity> pickOne()
    {
        auto ret = ni(e); //-3,0 0.5 0,1:0.3413 1,2:0.1359 2,3:0.0215
        if (ret < 0)
            return std::make_shared<n>();
        if (ret < 1)
            return std::make_shared<r>();
        if (ret < 2)
            return std::make_shared<sr>();
        if (ret < 3)
            return std::make_shared<ur>();
        return std::make_shared<n>();
    };
};
#endif /* DCF6203F_E946_4ECE_9997_67865E71C8B0 */
