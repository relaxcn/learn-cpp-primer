#include<string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    // copy constructor
    HasPtr(const HasPtr &orig):
        ps(new std::string(*orig.ps)),
        i(orig.i)
        { }
    // copy-assignment operator
    HasPtr& operator=(const HasPtr& rhs_hp) {
        std::string *temp_ps = new std::string(*rhs_hp.ps);
        delete ps;
        ps = temp_ps;
        i = rhs_hp.i;
        return *this;
    }
    // destructor
    ~HasPtr() {
        // because ps is using new
        delete ps;
    }
private:
    std::string *ps;
    int i;
};