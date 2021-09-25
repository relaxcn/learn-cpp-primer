#include<vector>
#include<iostream>
using namespace std;
int
main()
{
    vector<int> vi{1, 2, 3, 4, 5, 6, 7};
    auto iter = vi.begin();
    // 无限循环
    while (iter != vi.end()) {
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
        ++iter;
    }
    for(auto i : vi) cout << i << " ";
    cout << endl;
}