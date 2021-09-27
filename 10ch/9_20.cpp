#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int
main()
{
    vector<string> v{"hello", "world", "lulala", "lulalulalaei", "weihei", "hi"};
    int count = 0;
    // count_if 类似于 find_if，统计有多少为第三个函数返回为真。
    count = count_if(v.cbegin(), v.cend(), 
        [](const string &s) { return (s.size() > 6) ? true : false; }); 

    cout << count << endl;
}