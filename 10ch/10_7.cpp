#include<iterator>
#include<iostream>
#include<vector>
#include<list>
using namespace std;

int
main()
{
    // (a)错误，因为目标容器没有足够的空间。
    vector<int> vec; list<int> lst; int i;
    while (cin >> i)
        lst.push_back(i);
    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
    // vec没有这么大的空间，所以需要使用back_inserter插入迭代器
    // copy(lst.cbegin(), lst.cend(), vec.begin());
    for(auto i : vec) cout << i << ' ';
    cout << endl;
    // (b)错误，reserver只是改变系统为vector预留的内存空间，实际上并没有分配，所以空间不足。
    vector<int> vec2;
    vec2.reserve(10);
    // 使用resize改变实际的大小
    vec2.resize(10);
    // 或者使用插入迭代器
    fill_n(back_inserter(vec2), 10, 0);
    for (auto i : vec2) cout << i << " ";
    cout << endl;
}