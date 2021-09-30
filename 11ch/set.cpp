#include<set>
#include<iostream>
int
main()
{
    std::set<int> s = {1, 2, 5, 3, -1};
    for (auto i : s)
        std::cout << i << " ";
    // Sets are containers that store unique elements following a specific order.
    // set 具有顺序
    std::cout << std::endl;
}