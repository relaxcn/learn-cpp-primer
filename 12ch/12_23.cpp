#include<iostream>
#include<string>
#include<string.h>

int main()
{
    // 初始化
    char* p = new char[strlen("hello"" world")+1]();
    strcat(p, "hello ");
    strcat(p, "world");
    std::cout << p << std::endl;
    delete[] p;

    std::string str1{"hello"}, str2{" world"};
    std::cout << str1 << str2 << std::endl;
}