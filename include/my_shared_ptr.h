#ifndef EA36629F_9B34_4B1E_8BD9_D3CB12BA6D40
#define EA36629F_9B34_4B1E_8BD9_D3CB12BA6D40
#include <functional>

namespace msp
{
    template <typename T>
    class my_shared_ptr;
    template <typename T>
    auto swap(my_shared_ptr<T> &lhs, my_shared_ptr<T> &rhs)
    {
        using std::swap;
        swap(lhs.ref_count, rhs.ref_count);
        swap(lhs.ptr, rhs.ptr);
        swap(lhs.deleter, rhs.deleter);
    }
    template <typename T>
    void Delete(T *t)
    {
    }

    template <typename T>
    class my_shared_ptr
    {
    private:
        T *ptr;
        std::size_t *ref_count;
        std::function<void(T *)> deleter;
        void decrement_and_destory()
        {
            if (ptr && 0 == --*ref_count)
                delete ref_count, deleter(ptr);
            else if (!ptr)
                delete ref_count;
            ref_count = nullptr;
            ptr = nullptr;
        }

    public:
        my_shared_ptr() : ptr(nullptr), ref_count(new std::size_t(1)), deleter{msp::Delete}
        {
        }
        explicit my_shared_ptr(T *raw_ptr) : ptr(raw_ptr), ref_count(new std::size_t(1)), deleter{msp::Delete}
        {
        }
        my_shared_ptr(const my_shared_ptr &other) : ptr(other.ptr), ref_count(other.ref_count), deleter(other.deleter)
        {
            ++*ref_count;
        }
        my_shared_ptr(const my_shared_ptr &&other) noexcept : ptr(other.ptr), ref_count(other.ref_count), deleter(std::move(other.deleter))
        {
            other.ref_count = nullptr;
            other.ptr = nullptr;
        }
    };

} // namespace msp
#endif /* EA36629F_9B34_4B1E_8BD9_D3CB12BA6D40 */
