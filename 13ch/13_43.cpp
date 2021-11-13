#include"13_39_StrVec.hpp"
#include<algorithm>
// std::allocator<std::string> alloc;
std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    // 返回分配的第一个空指针
    // 疑惑，string指针相减得到的size_t类型的大小是多少
    auto data = alloc.allocate(e-b);
    // uninitialized_copy返回一个指针，指向最后一个构造的元素之后的位置
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    std::for_each(elements, first_free, [this](std::string *p){ alloc.destroy(p); });
    // 销毁使用alloc.construct分配的内存空间
    alloc.deallocate(elements, cap-elements);
}

void StrVec::range_initialize(const std::string*b, const std::string *e)
{
    auto newdata = alloc_n_copy(b, e);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &rhs)
{
    range_initialize(rhs.begin(), rhs.end());
}

StrVec::StrVec(std::initializer_list<std::string> li)
{
    range_initialize(li.begin(), li.end());
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    // 如果size为0，则分配newcapacity为1
    auto newcapacity = size() ? 2*size() : 1;
    reserve(newcapacity);
}

void StrVec::reserve(size_t newcapacity)
{
    if (newcapacity >= size()) {
        auto newdata = alloc.allocate(newcapacity);
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }
}

void StrVec::resize(size_t newsize)
{
    resize(newsize, std::string());
}

void StrVec::resize(size_t newsize, const std::string &s)
{
    if (newsize > capacity()) reserve(2*newsize);
    if (newsize > size()) {
        size_t nowsize = size();
        for (; nowsize <= newsize; ++newsize)
            push_back(s);
    } 
    else if (newsize < size()) {
        auto nowp = first_free;
        auto newp = elements + newsize;
        for (auto nowp = first_free, newp = elements+newsize; nowp != newp;)
            alloc.destroy(--nowp);
    }
    first_free = elements + newsize;
}
void StrVec::push_back(const std::string& s)
{
    // 确保有空间容纳新元素
    chk_n_alloc();
    alloc.construct(first_free++, s);
}