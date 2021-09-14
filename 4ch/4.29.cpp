#include<iostream>
using namespace std;
int main()
{
    int x[10]; int *p = x;
    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(p)/sizeof(*p) << endl;
    // int类型指针占8字节，int类型占4字节
    cout << sizeof(p) << " " << sizeof(*p) << endl;
    return 0;
}