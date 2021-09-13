#include<string>
using namespace std;
// 错误，必须是常量表达式，而size()函数显然不是
constexpr bool
isShorter(const string &s1, const string &s2)
{
    return s1.size() > s2.size();
}
int main()
{
    return 0;
}