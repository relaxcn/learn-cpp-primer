#include<vector>
#include<iostream>
using namespace std;

int
main()
{
    vector<int> v{1, 2, 3 ,4 ,5};
    auto begin = v.begin();
    while (begin != v.end()) {
        ++begin;
        // 插入后，begin失效，存储空间重新分配
        /*begin = */v.insert(begin, 42);
        ++begin;
    }
    for(auto i : v) cout << i << " ";
    cout << endl;
}