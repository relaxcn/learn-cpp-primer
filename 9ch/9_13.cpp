#include<list>
#include<iostream>
#include<vector>
using namespace std;

int
main()
{
    list<int> list1{1, 2, 3};
    vector<double> vd1(list1.begin(), list1.end());
    for(auto i : vd1)
        cout << i << " ";
    cout << endl;
    vector<int> v2{4, 5, 6};
    vector<double> vd2(v2.begin(), v2.end());
    for(auto i : vd2) cout << i << " ";
    cout << endl;
    return 0;
}