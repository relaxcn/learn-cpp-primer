#ifndef EX_13_44_STRING_HPP
#define EX_13_44_STRING_HPP
#include<iostream>
#include<memory>

class String {
public:
    String();
    String(const char *);

    String(const String&);
    String& operator=(const String&);
    ~String();
    // move copy constructor
    String(const String&& s) noexcept : element(s.element), end(s.end) {
        element = end = nullptr;
        std::cout << "move copy constructor" << std::endl;
    }
    // 移动拷贝赋值运算符
    String& operator=(String &&rhs) {
        if (this != &rhs) {
            free();
            element = rhs.element;
            end = rhs.end;
            rhs.element = rhs.end = nullptr;
        }
        std::cout << "move operator=" << std::endl;
        return *this;
    }

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
#endif