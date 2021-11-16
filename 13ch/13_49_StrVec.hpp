#ifndef EX_13_39_H
#define EX_13_39_H
#include<string>
#include<utility>
#include<memory>
#include<initializer_list>

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(std::initializer_list<std::string>);
    // copy constructor
    StrVec(const StrVec&);
    // copy-assignmnet operator
    StrVec &operator=(const StrVec &);
    // move copy-constructor
    StrVec(const StrVec&& rhs) noexcept:elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap) {
        elements = first_free = cap = nullptr;
    }
    // 移动复制运算符
    StrVec &operator=(StrVec &&s) noexcept {
        // avoid moving itemself
        if (this != &s) {
            free();
            elements = s.elements;
            first_free = s.first_free;
            cap = s.cap;
            s.elements = s.first_free = s.cap = nullptr;
        }
        return *this;
    }
    // 析构函数
    ~StrVec();
    void push_back(const std::string &);
    void resize(std::size_t, const std::string &);
    void resize(std::size_t);
    void reserve(std::size_t);

    std::string& at(size_t pos) { return *(elements+pos); }
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
private:
    std::allocator<std::string> alloc;
    // 检测并保证至少有一个空间容纳新元素，如果空间不足，则会调用 reallocate()
    void chk_n_alloc() {
        // 如果空间不够
        if (size() == capacity()) {
            reallocate();
        }
    }
    void free();
    void reallocate();
    // 拷贝指定范围内的数据，并分配新的空间
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string*, const std::string*);
    void range_initialize(const std::string*, const std::string*);
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};
#endif