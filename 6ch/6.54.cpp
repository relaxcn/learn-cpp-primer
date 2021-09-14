#include<vector>
using namespace std;

extern int func(int, int);

typedef int (*fp)(int, int);

using FP = int(*)(int, int);
int
main()
{
    vector<int (*)(int, int)> v{func};

    fp func_ptr = func;
    vector<fp> v1 = {func_ptr};

    FP FUNC_PTR = func;
    vector<FP> v2 = {FUNC_PTR};

    decltype(func) * dFP = func;
    vector<decltype(func) *> v3 = {dFP};
}
