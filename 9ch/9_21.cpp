#include<iostream>
#include<vector>
#include<string>
using namespace std;

int
main()
{
    string word;
    vector<string> v;
    auto iter = v.begin();
    while( cin >> word )
        iter = v.insert(iter, word);
    for(auto i : v)
        cout << i << endl;
}