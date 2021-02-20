#ifndef ED34739A_9599_4795_A6A7_D0758FC06893
#define ED34739A_9599_4795_A6A7_D0758FC06893
#include <string>
#include <memory>
#include <ostream>
class queryBase;
class query;
class wordQuery;
class notQuery;
class andQuery;
class orQuery;
class textQuery;
class queryBase
{
    //! this class will surppt:
    //todo word qurry: get a certain line which contains a word
    //todo logical not query: use ~ to find a certain line which do not have a certain word
    //todo logical or query: use | to find a certain line which contain any one word between given two words
    //todo logical and query: use & to find a certain line which contain given words the same time
    //todo besides we wish we can use these queries together like fiery & bird | wind
    friend class query;

protected:
    // using line_no=textQuery::line_no;
    virtual ~queryBase() = default;
    queryBase() = default;

private:
    queryBase(const std::string &);
    virtual queryResult eval(const textQuery &) const = 0;
    virtual std::string rep() const = 0;
};
class wordQuery : public queryBase
{
    friend class query;
    wordQuery(const std::string s) : word(s){};
    std::string word;
    queryResult eval(const textQuery &t) const { return t.query(word); };
    std::string rep() const { return word; };
};
class notQuery : public queryBase
{
    friend query operator~(const query &);
    notQuery(const query &Q) : q(Q) {}
    std::string rep() const { return "~(" + q.rep() + ")"; }
    queryResult eval(const textQuery &) const;
    query q;
};
class binaryQuery : public queryBase
{
protected:
    binaryQuery(const query q1, const query q2, std::string s) : q(q1), qq(q2), opSym(s){};
    std::string rep() const { return "(" + q.rep() + opSym + qq.rep() + ")"; };
    query q, qq;
    std::string opSym;
};
class andQuery : public binaryQuery
{
    friend query operator&(const query &, const query &);
    andQuery(const query &q1, const query &q2) : binaryQuery(q1, q2, "&"){};
    queryResult eval(const textQuery &t) const;
    std::string rep() const;
};
class orQuery : public binaryQuery
{
    friend query operator|(const query &, const query &);
    orQuery(const query &q1, const query &q2) : binaryQuery(q1, q2, "|"){};
    queryResult eval(const textQuery &t) const;
    std::string rep() const;
};
class query //! this class is used to hide those progresses.
{
    friend query operator~(const query &);
    friend query operator|(const query &, const query &);
    friend query operator&(const query &, const query &);
    friend std::ostream &operator<<(std::ostream &, const query &);

public:
    query(const std::string &s) : p(new wordQuery(s)){};
    queryResult eval(const textQuery &t) const { return p->eval(t); };
    std::string rep() const { return p->rep(); };

private:
    query(std::shared_ptr<queryBase> query) : p(query){};
    std::shared_ptr<queryBase> p;
};
class textQuery
{
public:
    queryResult query(const std::string &) const;
};
class queryResult
{
};
inline std::ostream &operator<<(std::ostream os, const query &q) { return os << q.rep(); }
inline query operator~(const query &q) { return std::make_shared<queryBase>(new notQuery(q)); }
inline query operator&(const query &q1, const query &q2) { return std::make_shared<queryBase>(new andQuery(q1, q2)); }
inline query operator|(const query &q1, const query &q2) { return std::make_shared<queryBase>(new orQuery(q1, q2)); }

#endif /* ED34739A_9599_4795_A6A7_D0758FC06893 */
