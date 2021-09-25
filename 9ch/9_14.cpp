#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

int
main()
{
    list<char *> L1{"hello", "world", "lulala"};
    vector<string> v(5);
    v.assign(L1.begin(), L1.end());
    for(auto i : v) {
        cout << i << endl;
    }
    cout << v.size() << endl;
    return 0;
}
