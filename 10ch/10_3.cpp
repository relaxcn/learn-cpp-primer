#include<numeric>
#include<iostream>
#include<vector>
using namespace std;

int
main()
{
    vector<int> v{1, 2, 3, 4, 5};
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;
}