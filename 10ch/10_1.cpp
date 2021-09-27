#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int
main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 6, 6, 6, 2};
    cout << count(v.begin(), v.end(), 2) << endl;
}