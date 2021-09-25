#include<iostream>
#include<deque>
#include<list>
#include<string>
using namespace std;

int
main()
{
    string s;
    list<string> d;
    while(cin >> s)
        d.push_back(s);
    for(auto i : d)
        cout << i << endl;
}