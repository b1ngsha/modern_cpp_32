#include <utility>
#include <iostream>

class shape
{
public:
    virtual ~shape() {}
};

class circle : public shape
{
public:
    ~circle() { puts("~circle()"); }
};

class shared_count
{
public:
    shared_count() noexcept : count_(1) {}
    void add_count() noexcept { ++count_; }
    long reduce_count() noexcept { return --count_; }
    long get_count() const noexcept { return count_; };

private:
    long count_;
};

template <typename T>
class smart_ptr
{
public:
    explicit smart_ptr(T *ptr = nullptr) : ptr_(ptr)
    {
        if (ptr_)
        {
            shared_count_ = new shared_count();
        }
    }

    ~smart_ptr()
    {
        if (ptr_ && !shared_count_->reduce_count())
        {
            delete ptr_;
            delete shared_count_;
        }
    }

    smart_ptr(smart_ptr &&other)
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
        }
    }

    template <typename U>
    smart_ptr(smart_ptr<U> &&other) noexcept
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
        }
    }

    smart_ptr &operator=(smart_ptr other) noexcept
    {
        other.swap(*this);
        return *this;
    }

    smart_ptr(const smart_ptr &other)
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    template <typename U>
    smart_ptr(const smart_ptr<U> &other) noexcept
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    template <typename U>
    smart_ptr(const smart_ptr<U> &other, T *ptr) noexcept
    {
        ptr_ = ptr;
        if (ptr_)
        {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    T *get() const noexcept { return ptr_; }

    T &operator*() const noexcept { return *ptr_; }

    T *operator->() const noexcept { return ptr_; }

    operator bool() const noexcept { return ptr_; }

    void swap(smart_ptr &other) noexcept
    {
        using std::swap;
        swap(ptr_, other.ptr_);
        swap(shared_count_, other.shared_count_);
    }

    long use_count() const noexcept
    {
        if (ptr_)
        {
            return shared_count_->get_count();
        }
        return 0;
    }

private:
    T *ptr_;
    shared_count *shared_count_;

    template <typename U>
    friend class smart_ptr;
};

template <typename T, typename U>
smart_ptr<T> static_pointer_cast(const smart_ptr<U> &other) noexcept
{
    T *ptr = static_cast<T *>(other.get());
    return smart_ptr<T>(other, ptr)
}

template <typename T, typename U>
smart_ptr<T> dynamic_pointer_cast(const smart_ptr<U> &other) noexcept
{
    T *ptr = dynamic_cast<T *>(other.get());
    return smart_ptr<T>(other, ptr);
}

template <typename T, typename U>
smart_ptr<T> const_pointer_cast(const smart_ptr<U> &other) noexcept
{
    T *ptr = const_cast<T *>(other.get());
    return smart_ptr<T>(other, ptr);
}

template <typename T, typename U>
smart_ptr<T> reinterpret_pointer_cast(const smart_ptr<U> &other) noexcept
{
    T *ptr = reinterpret_cast<T *>(other.get());
    return smart_ptr<T>(other, ptr);
}

int main()
{
    smart_ptr<circle> ptr1(new circle());
    printf("use count of ptr1 is %ld\n", ptr1.use_count());

    smart_ptr<shape> ptr2;
    printf("use count of ptr2 was %ld\n", ptr2.use_count());

    ptr2 = ptr1;
    printf("use count of ptr2 is now %ld\n", ptr1.use_count());

    if (ptr1)
    {
        puts("ptr1 is not empty");
    }

    smart_ptr<circle> ptr3 = dynamic_pointer_cast<circle>(ptr2);
    printf("use count of ptr3 is %ld\n", ptr3.use_count());
}