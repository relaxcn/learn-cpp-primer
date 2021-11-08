#include"12_32.hpp"
#include <string>
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs("query.txt");
    TextQuery query(ifs);
    std::string word("hello");
    QueryResult qr = query.query(word);
    print(std::cout, qr);
}