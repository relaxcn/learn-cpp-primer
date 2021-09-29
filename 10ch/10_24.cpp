#include<string>
#include<vector>
#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

int
main()
{
    vector<int> v{1, 7, 3, 4, 5, 6};
    string s{"hello"};
    auto wc = find_if(v.begin(), v.end(), bind(check_size, s, _1));
    if (wc != v.end())
        cout << *wc << endl;
    else
        cout << "Not Found" << endl;
}
