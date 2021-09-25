#include<vector>
#include<iostream>
using namespace std;
int
main()
{
    // 验证可知，capacity每次增加一倍
    vector<int> v{1, 2, 3, 4};
    cout << "capacity:" << v.capacity() << endl;
    cout << "size:" << v.size() << endl;
    v.push_back(5);
    cout << "-------" << endl;
    cout << "capacity:" << v.capacity() << endl;
    cout << "size:" << v.size() << endl;
    for(int i = 0; i < 3; ++i)
        v.push_back(0);
    cout << "-------" << endl;
    cout << "capacity:" << v.capacity() << endl;
    cout << "size:" << v.size() << endl;
    v.push_back(0);
    cout << "-------" << endl;
    cout << "capacity:" << v.capacity() << endl;
    cout << "size:" << v.size() << endl;
}