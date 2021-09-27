#include<list>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int
main()
{
    list<string> sv{"hello", "hello", "world"};
    cout << count(sv.begin(), sv.end(), "hello") << endl;    
}