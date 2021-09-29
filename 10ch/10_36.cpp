#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int
main()
{
    list<int> lst{1, 2, 3, 4, 0, 4, 5, 0, 1};
    auto wc = find(lst.crbegin(), lst.crend(), 0);    
}