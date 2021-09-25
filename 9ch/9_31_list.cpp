#include<iostream>
#include<list>
// comma-separated list in using-declaration only available with -std=c++17 or -std=gnu++17
using std::list, std::cout, std::endl;

int
main()
{
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto iter = lst.begin(); iter != lst.end();) {
        // odd value
        if (*iter % 2) {
            iter = lst.insert(iter, *iter);
            ++iter; ++iter;
        }
        // even value
        else {
            iter = lst.erase(iter);
        }
    }
    for(auto i : lst) cout << i << " ";
    cout << endl;
}