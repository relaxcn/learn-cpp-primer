#include<numeric>
#include<iostream>
#include<vector>
using namespace std;

int
main()
{
    vector<double> v{1.1, 2.2, 3.3, 4.4, 5.1};
    // 将会把所有元素转换为int类型的之后进行相加，忽略小数点之后的数字。
    double sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;
}