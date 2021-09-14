#include<iostream>
using namespace std;
extern void f();
extern void f(int);
extern void f(int, int);
// 声明中可以制定默认初始值
extern void f(double, double = 3.14);

int
main()
{
    // 二义性，错误
    // f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
}

void
f()
{
    cout << "This is f()." << endl;
}
void
f(int)
{
    cout << "This is f(int)." << endl;
}
void
f(int, int)
{
    cout << "This is f(int, int)." << endl;
}
void
f(double, double)
{
    cout << "This is f(double, double = 3.14)." << endl;
}