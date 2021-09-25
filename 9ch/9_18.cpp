#include<iostream>
#include<deque>
#include<string>
using namespace std;

int
main()
{
    string s;
    deque<string> d;
    while(cin >> s)
        d.push_back(s);
    for(auto i : d)
        cout << i << endl;
}