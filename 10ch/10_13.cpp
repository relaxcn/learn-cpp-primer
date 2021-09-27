#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

bool isBlowFive(const string &s)
{
    return s.size() >= 5;
}

int
main()
{
    vector<string> sv{"jj", "hello", "world", "six", "hi"};
    // 返回一个迭代器，只想最后一个使谓词为true的元素之后的位置。
    auto iter = partition(sv.begin(), sv.end(), isBlowFive);
    for (auto i = sv.begin(); i != iter; ++i)
        cout << *i << endl;
}