#include<vector>
#include<iostream>
using namespace std;
int
main()
{
    // [begin, end)
    vector<int> v{1, 2, 3, 4};
    v.erase(v.begin(), ++v.begin());
    for(auto i : v) cout << i << " ";
    cout << endl;
}