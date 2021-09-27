#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void
elimDups(vector<string> &v)
{
    sort(v.begin(), v.end());
    auto index = unique(v.begin(), v.end());
    for(auto i : v) cout << i << " ";
    cout << "--";
    cout << v.size();
    cout << endl;
    v.erase(index, v.end());
}

int
main()
{
    vector<string> v{"hello", "world", "hello", "apple"};
    elimDups(v);
    for (auto i : v) cout << i << " ";
    cout << "--";
    cout << v.size();
    cout << endl;
}