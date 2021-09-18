#include<vector>
#include<iostream>
using namespace std;
// example.h
class Example {
public:
    static constexpr double rate = 6.5;
    static constexpr int vecSize = 20;
    //错误！vector是模板不是字面值常量类型，所以不满足第一条。应该改为 static vector vec; //仅仅且只能进行声明，不能定义
    static vector<double> vec;
};

// example.C
constexpr double Example::rate;
// 在类外面定义
vector<double> Example::vec(Example::vecSize);

int
main()
{
    vector<double> vec(10);
    for( auto beg = vec.begin(); beg != vec.end(); ++beg )
        cout << *beg << endl;
}