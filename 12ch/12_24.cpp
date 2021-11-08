#include<string>
#include<iostream>

int main()
{
    std::cout << "type your string length:";
    size_t size{0};
    std::cin >> size;
    std::cin .ignore();
    std::cout << "type your string:";
    char* pstr = new char[size+1]();
    std::cin.get(pstr, size+1);
    std::cout << pstr << std::endl;
    delete [] pstr;
}