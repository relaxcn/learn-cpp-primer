#include"13_42_TextQuery.hpp"
// #include"../12ch/searchText/TextQuery.hpp"
#include<iostream>
#include<string>
int main()
{
    std::string file_name("../12ch/query.txt");
    while(true) {
        std::ifstream ifs(file_name);
        TextQuery query(ifs);
        std::string word;
        std::cout << "Type your word for searching: ";
        std::cin >> word;
        auto result = query.query(word);
        print(std::cout, result);
    }
}