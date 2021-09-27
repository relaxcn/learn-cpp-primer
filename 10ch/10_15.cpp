#include<iostream>
using namespace std;

int
main()
{
    int a = 1;
    auto add = [a](int b) -> int { return a+b; };
}