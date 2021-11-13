#ifndef EX_13_44_STRING_HPP
#define EX_13_44_STRING_HPP
#include<memory>

class String {
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
#endif