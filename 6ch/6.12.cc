#include<iostream>
using namespace std;
// 引用版本
extern void exchange( int &a, int &b );

int
main()
{
    int a, b;
    cout << "Type two number." << endl;
    cout << "a:";
    cin >> a;
    cout << "b:";
    cin >> b;
    exchange( a, b );
    cout << "After exchangeing the a is " << a << ", b is " << b << endl;
    return 0;
}

void
exchange( int &a, int &b )
{
    int tmp = a;
    a = b;
    b = tmp;
}