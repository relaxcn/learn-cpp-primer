#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
// 包含bind
#include<functional>
using namespace std;
using namespace std::placeholders;

bool above6(const string &s, const unsigned size)
{
    return s.size() >= size;
}
int
main()
{
    vector<string> v{"hello", "world", "lulalulalei", "123456"};
    int count = 0;
    // 使用bind，相当于适配器，用来适配只有一个参数的接口函数
    count = count_if(v.begin(), v.end(), bind(above6, _1, 6));
    cout << count << endl;

}