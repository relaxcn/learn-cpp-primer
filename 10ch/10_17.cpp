#include<string>
#include"7ch/7_20.h"
#include<vector>
#include<algorithm>
using namespace std;

void
compareIsbn(vector<Sales_data> &v)
{
    // 使用lambda表达式代替传递的函数参数。
    sort(v.begin(), v.end(), 
        [](const Sales_data &s1, const Sales_data &s2) { return s1.isbn() < s2.isbn(); }); 
}