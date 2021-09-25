#include<vector>
#include<list>
#include<iostream>
using namespace std;

int
main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    // init
    vector<int> v(ia, end(ia));
    list<int> lst(v.begin(), v.end());

    // remove even value
    for(auto beg = v.begin(); beg != v.end();) {
        if (*beg % 2 == 0)
            beg = v.erase(beg);
        else
            ++beg;
    }

    // remove odd value
    for(auto beg = lst.begin(); beg != lst.end();) {
        if (*beg % 2 == 1)
            beg = lst.erase(beg);
        else
            ++beg;
    }
    // print
    for(auto i : v) cout << i << " ";
    cout << endl;
    for(auto i : lst) cout << i << " ";
    cout << endl;
}