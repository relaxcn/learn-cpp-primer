// iter没有迭代
#include<vector>
using namespace std;

int
main()
{
    int some_val;
    vector<int> iv;
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
    while (iter != mid)
        if (*iter == some_val)
            // change the value of iter.
            iter = iv.insert(iter, 2 * some_val);
}