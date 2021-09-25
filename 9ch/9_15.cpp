#include<iostream>
#include<vector>
int
main()
{
    std::vector<int> v1{1, 2};
    std::vector<int> v2{1, 2};
    if (v1 > v2)
        std::cout << "v1 is bigger than v2." << std::endl;
    else if (v1 < v2)
        std::cout << "v2 is bigger than v1." << std::endl;
    else
        std::cout << "they are same." << std::endl;
    return 0;
}