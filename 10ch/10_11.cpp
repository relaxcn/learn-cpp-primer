#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() > s2.size();
}

void
elimDups(vector<string> &v)
{
    sort(v.begin(), v.end());
    auto end_unique = unique(v.begin(), v.end());
    v.erase(end_unique, v.end());
}
int
main()
{
    vector<string> s{"apple", "apple", "append", "aapend"};
    // 首先按照字母顺序进行排序，并去除重复元素。
    elimDups(s);
    // 按照字符串长短进行排序，并保持长度相等元素之前的顺序。
    stable_sort(s.begin(), s.end(), isShorter);
    for (auto i : s) cout << i << " ";
    cout << endl;
}