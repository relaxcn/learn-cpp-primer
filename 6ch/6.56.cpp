#include<iostream>
#include<vector>
using namespace std;

extern int add(int, int);
extern int sub(int, int);
extern int mul(int, int);
extern int div_u(int, int);

using fp = int(*)(int, int);
typedef int(*FP)(int, int);

int
main()
{
    vector<fp> v = {add, sub, mul, div_u};
    for( auto beg = v.begin(); beg != v.end(); ++beg)
        cout << (*beg)(4, 2) << endl;
    return 0;
}

int
add(int a, int b)
{
    return a+b;
}

int
sub(int a, int b)
{
    return a-b;
}

int
mul(int a, int b)
{
    return a*b;
}

int
div_u(int a, int b)
{
    return a/b;
}