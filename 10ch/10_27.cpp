#include<algorithm>
#include<vector>
#include<list>
#include<iostream>
using namespace std;

int
main()
{
    vector<int> v{1, 1, 2, 2, 3, 4, 4};
    list<int> lst;
    // unique_copy 不重复的拷贝
    unique_copy(v.begin(), v.end(), back_inserter(lst));
    for (auto i : lst) cout << i << endl;
}