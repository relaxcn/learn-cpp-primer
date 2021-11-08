#ifndef EX_12_2_HPP
#define EX_12_2_HPP
#include<memory>
#include<string>
#include<vector>
#include<stdexcept>
#include"12_19.hpp"
using namespace std;

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

#endif