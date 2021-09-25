#include<vector>
using std::vector;
int
main()
{
    vector<int> vec(25, -1);
    //  将新增的75个元素初始化放到vec的后面
    vec.resize(100);
    // 从末尾截断，vec只剩下10个元素
    vec.resize(10);
}