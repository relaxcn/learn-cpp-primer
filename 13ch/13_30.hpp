#include<string>
#include<iostream>

class HasPtr;
void swap(HasPtr&, HasPtr&);
class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    // copy constructor
    HasPtr(const HasPtr &orig):
        ps(new std::string(*orig.ps)),
        i(orig.i),
        use(orig.use)
        { ++*use; }
    // copy-assignment operator
    HasPtr& operator=(const HasPtr& rhs_hp) {
        ++*rhs_hp.use;
        // 如果没有其他用户，则释放空间
        if(--*use == 0) {
            delete ps;
            delete use;
        }
        ps = rhs_hp.ps;
        i = rhs_hp.i;
        use = rhs_hp.use;
        // 返回本对象
        return *this;
    }
    // destructor
    ~HasPtr() {
        // because ps is using new
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }
private:
    std::string *ps;
    int i;
    // this is a pointer
    std::size_t *use;
};
inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.i, rhs.i);
    swap(lhs.ps, rhs.ps);
    swap(lhs.use, rhs.use);
    std::cout << "inline void swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
}