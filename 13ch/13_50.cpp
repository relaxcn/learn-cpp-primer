#include"13_49_String.hpp"
#include<vector>
#include<iostream>

int main()
{
    std::vector<String> vec;
    // "hello" is a right value, so it will call move copy constructor
    vec.push_back("hello");
    std::cout << "-----------" << std::endl;
    vec.push_back("world");
    std::cout << "-----------" << std::endl;
    vec.push_back("ciel");
    std::cout << "-----------" << std::endl; 
    String s("hei");
    // s is a left-value, it will call copy constructor
    vec.push_back(s);
    std::cout << "-----------" << std::endl; 
}