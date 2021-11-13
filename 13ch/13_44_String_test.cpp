#include"13_44_String.hpp"
#include<vector>
#include<iostream>

int main()
{
    String s("hello");
    String o(s);
    std::cout << s.c_str() << std::endl;
    std::cout << o.c_str() << std::endl;
    o = String("world");
    std::cout << s.c_str() << std::endl;
    std::cout << o.c_str() << std::endl;
}