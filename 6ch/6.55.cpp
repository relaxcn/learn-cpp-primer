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
}