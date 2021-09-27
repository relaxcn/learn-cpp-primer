#include<vector>
#include<algorithm>
#include<iostream>
#include<iterator>
using namespace std;
int
main()
{
    vector<int> v{1, 2, 3, 4};
    fill_n(v.begin(), v.size(), 0);
    for(auto i : v) {
        cout << i << endl;
    }
}