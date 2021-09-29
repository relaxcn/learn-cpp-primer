#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int
main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for_each(vec.crbegin(), vec.crend(), [](const int num){
        cout << num << " ";
    });
    cout << endl;
}