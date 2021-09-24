#include<vector>
using namespace std;

int
main()
{
    // v1 is empty
    vector<int> v1;
    // 0
    vector<int> v2(10);
    // -1
    vector<int> v3(10, -1);
    // {1, 2, 3}
    vector<int> v4{1, 2, 3};
    // same as v1
    vector<int> v5(v1);
    // same as v1
    vector<int> v6(v1.begin(), v2.end());
}