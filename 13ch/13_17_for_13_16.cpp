#include<iostream>

class numbered {
public:
    numbered() {
        mysn = ++unique;
    }
    // copy constructo
    numbered(const numbered& ris) {
        mysn = ++unique;
    }
    int mysn;
    static int unique;
};

int numbered::unique = 10;

// not exec copy constructor
void f (numbered &s)
{
    std::cout << s.mysn << std::endl;
}

int main() {
    // exec copy constructor
    // becase there is default copy constructor, so the mysn is the same.
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
}