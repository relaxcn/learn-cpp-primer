#include"13_44_String.hpp"
#include<algorithm>
#include<cstring>
#include<iostream>

std::pair<char*, char*> String::alloc_n_copy(const char *beg, const char *end)
{
    auto data = alloc.allocate(end-beg);
    return {data, std::uninitialized_copy(beg, end, data)};
}

void String::range_initializer(const char *b, const char *e)
{
    auto data = alloc_n_copy(b, e);
    element = data.first;
    end = data.second;
}

void String::free()
{
    std::for_each(element, end, [this](char &c){ alloc.destroy(&c); });
    alloc.deallocate(element, end-element);
    std::cout << "free()" << std::endl;
}

String::String() { String(""); }

String::String(const char *p)
{
    std::size_t length =  strlen(p);
    range_initializer(p, p+length+1);
    std::cout << "initialiaztion function: String(const char *p)" << std::endl;
}

String::String(const String &rhs)
{
    range_initializer(rhs.element, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

String &String::operator=(const String &rhs)
{
    auto data = alloc_n_copy(rhs.element, rhs.end);
    free();
    element = data.first;
    end = data.second;
    std::cout << "operator=" << std::endl;
    return *this;
}

String::~String()
{
    free();
}