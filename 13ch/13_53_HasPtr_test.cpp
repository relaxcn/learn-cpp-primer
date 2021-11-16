#include"13_53_HasPtr.hpp"
#include<string>
#include<iostream>

int main()
{
    HasPtr hp1("hello"), hp2("world"), *hp = new HasPtr("World");
    std::cout << "-------------" << std::endl;
    hp1 = hp2;
    std::cout << "-------------" << std::endl;
    hp1 = std::move(*hp);
    std::cout << "-------------" << std::endl;
}