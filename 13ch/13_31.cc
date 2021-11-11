#include"13_31.hpp"
#include<vector>
#include<algorithm>

int main()
{
    HasPtr s{"s"}, a{"a"}, c{"c"};
    std::vector<HasPtr> vec{s, a, c};
    std::sort(vec.begin(), vec.end());
    for (auto has : vec) has.show();
}