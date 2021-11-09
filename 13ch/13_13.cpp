#include<iostream>
#include<vector>

struct X {
    X() { std::cout << "X()" << std::endl; }
    // copy constructor
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    // copy-assignment operator
    X& operator=(const X& ris) { std::cout << "X& operator=(const X& ris)" << std::endl; }
    // destructo
    ~X() { std::cout << "~X()" << std::endl; }
};
void reference(X& x) {

}

void noreference(X x) {

}

int main()
{
    X x;
    reference(x);
    noreference(x);
    X *x_ptr = new X();
    std::vector<X> vec;
    vec.push_back(x);
    X x1;
    x1 = x;
}



