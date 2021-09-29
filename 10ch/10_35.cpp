#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int
main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto end = vec.end(), beg = vec.begin();
    while (end != beg) 
        cout << *--end << " ";
}