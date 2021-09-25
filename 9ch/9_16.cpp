#include<iostream>
#include<vector>
#include<list>
int
main()
{
    std::vector<int> v1{1, 2};
    std::vector<int> v2{1, 2, 3};
    std::list<int> li{1, 2};
    std::cout << (std::vector<int>(li.begin(), li.end()) == v1 ? "true" : "false") << std::endl;
    std::cout << (std::vector<int>(li.begin(), li.end()) == v2 ? "true" : "false") << std::endl;
}