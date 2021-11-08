#ifndef EX_12_2_HPP
#define EX_12_2_HPP
#include<memory>
#include<string>
#include<vector>
#include<stdexcept>
#include<initializer_list>
using std::string;
using std::vector;
using std::make_shared;
using std::weak_ptr;
using std::shared_ptr;
using std::out_of_range;
using std::runtime_error;

class StrBlobPtr;
class StrBlob {
public:
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;
    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }
    
    StrBlob() : data(make_shared<vector<string>>()) { };
    StrBlob(std::initializer_list<std::string> il) : data(make_shared<vector<string>>(il)) { };
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and del elem
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();

    const string &back() const;
    const string& front() const;

private:
    shared_ptr<std::vector<string>> data;
    void check(size_type i, const string &msg) const;
};

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

void StrBlob::pop_back() {
    check(0, "pop back on empty StrBlob");
    data->pop_back();
}

const string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}


class StrBlobPtr {
public:
    // 构造函数
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0) :
        wptr(a.data), curr(sz) { }
    string& deref() const;
    StrBlobPtr& incr(); // 前缀递增
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
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

#endif