#ifndef EX_14_7_STRING_HPP
#define EX_14_7_STRING_HPP
#include<memory>
#include<iostream>

class String {
    // 输出运算符
    friend std::ostream& operator<<( std::ostream& os, String& s);
public:
    String();
    String(const char *);

    String(const String&);
    String& operator=(const String&);
    ~String();

    const char *c_str() const { return element; }
    size_t size() const { return end - element -1; }
    size_t length() const { return size(); }

private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();

private:
    char *element;
    char *end;
    std::allocator<char> alloc;
};

std::ostream& operator<<( std::ostream& os, const String& s) {
    char *c = const_cast<char*>(s.c_str());
    while (*c)
        os << *c++;
    return os;
}

#endif