/* 
    行为像指针的类
    拥有类似于智能指针的引用计数，这里类似于用户计数
    用户数是使用动态内存分配的，一旦用户数减为零，则释放空间
*/
#include<string>

class HasPtr {
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