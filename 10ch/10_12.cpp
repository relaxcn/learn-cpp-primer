#include<string>
#include"7ch/7_20.h"
#include<vector>
#include<algorithm>
using namespace std;

bool isShroter(const Sales_data &s1, const Sales_data &s2)
{
    return s1.isbn() < s2.isbn();
}

void
compareIsbn(vector<Sales_data> &v)
{
    sort(v.begin(), v.end(), isShroter); 
}