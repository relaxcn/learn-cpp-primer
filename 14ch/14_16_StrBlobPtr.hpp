#ifndef EX_12_19_HPP
#define EX_12_19_HPP
#include<memory>
#include<vector>
#include<string>
#include<stdexcept>
#include"14_16_StrBlob.hpp"
using namespace std;

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
public:
    // 构造函数
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0) :
        wptr(a.data), curr(sz) { }
    
    string& deref() const;
    StrBlobPtr& incr(); // 前缀递增
private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const 
{
    // 如果vector已被销毁，则lock返回一个空指针。
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    // shared_ptr 指向vector
    return ret;
}

string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increnment past end of StrBlobPtr");
    ++curr;
    return *this;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}
#endif