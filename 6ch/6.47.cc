#include<string>
using namespace std;
using arrT = string[10];
extern arrT &func();
auto func2() -> string (&)[10];

string arrS[10];
decltype(arrS) &func3();
