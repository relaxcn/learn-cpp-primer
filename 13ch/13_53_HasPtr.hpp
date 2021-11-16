#ifndef EX13_31_HPP
#define EX13_31_HPP
#include<string>
#include<iostream>

class HasPtr {
    friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    // copy constructor
    HasPtr(const HasPtr &orig):
        ps(new std::string(*orig.ps)),
        i(orig.i)
        { std::cout << "copy constructor" << std::endl; }
    // copy-assignment operator
    HasPtr& operator=(HasPtr rhs_hp) {
        this->swap(rhs_hp);
        return *this;
    }
    // destructor
    ~HasPtr() {
        // because ps is using new
        delete ps;
    }
    // move constructor
    // new adding
    HasPtr(HasPtr &&h) noexcept : ps(h.ps), i(h.i) {
        h.ps = nullptr;
        std::cout << "call move constructor" << std::endl;
    }
    void show() const {
        std::cout << *ps << std::endl;
    }
    void swap(HasPtr &rhs) {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "call swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
    }
private:
    std::string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
    lhs.swap(rhs);
}

bool operator<(const HasPtr& lhs, const HasPtr& rhs) {
    return *lhs.ps < *rhs.ps;
}

#endif