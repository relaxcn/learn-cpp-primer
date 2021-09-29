#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

// 使用list类型的特定算法
void
elimDups(list<string> &lst)
{
    lst.sort();
    lst.unique();
}

int
main()
{
    list<string> lst{"hello", "world", "hello", "apple"};
    elimDups(lst);
    for (auto i : lst) cout << i << " ";
    cout << endl;
}