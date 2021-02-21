#ifndef DB9F32C1_E361_45D1_B4A2_5FE9E83AE7B4
#define DB9F32C1_E361_45D1_B4A2_5FE9E83AE7B4
#include <vector>
#include <memory>
#include <string>
template <typename T>
class Blob;
template <typename T>
class BlobPtr;
template <typename T>
bool operator==(const Blob<T> &b1, const Blob<T> &b2);
template <typename T>
//!!!! nontype coding should put declaratons and definations together!!!!!
class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T> &b1, const Blob<T> &b2);

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    //? when we need to tell compiler a name means a type instead of a value we must use typename 
    Blob();
    Blob(std::initializer_list<T>);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(t); }
    void pop_back();
    T &back();
    T &front();
    const T &cback();
    const T &cfront();
    T &operator[](size_type i);

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
class BlobPtr
{
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    T &operator*() const;
    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr &operator++(int);
    BlobPtr &operator--(int);

private:
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
    std::shared_ptr<T> check(size_t i, std::string &msg) const;
};
// template <typename T>
// bool operator==<T>(const Blob<T> &b1, const Blob<T> &b2)
// {
//     return true;
// }
#include "Blob.h"

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>())
{
}
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(std::vector<T>(il))) {}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}
template <typename T>
T &Blob<T>::operator[](size_type i)
{
    check(i, "Subscript out of range!");
    return (*data)[i];
}
template <typename T>
void Blob<T>::pop_back()
{
    check(0, "Pop back on empty blob!");
    data->pop_back();
}
template <typename T>
T &Blob<T>::back()
{
    check(0, "Back on empty blob!");
    return data->back();
}
template <typename T>
const T &Blob<T>::cback()
{
    check(0, "Back on empty blob!");
    data->back();
}
template <typename T>
T &Blob<T>::front()
{
    check(0, "Front on empty blob!");
    return data->front();
}
template <typename T>
const T &Blob<T>::cfront()
{
    check(0, "Front on empty blob!");
    return data->front();
}
template <typename T>
T &BlobPtr<T>::operator*() const
{
    auto p = check(curr, "Dereference past end!");
    return *(wptr)[curr];
}
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++(int)
{
    auto p = *this;
    ++(*this);
    return p;
}
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--(int)
{
    auto p = *this;
    --(*this);
    return p;
}
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    auto p = check(curr + 1, "Dereference past end!");
    return *(wptr)[++curr];
}
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    auto p = check(curr - 1, "Dereference before begin!");
    return *(wptr)[--curr];
}
#endif /* DB9F32C1_E361_45D1_B4A2_5FE9E83AE7B4 */
