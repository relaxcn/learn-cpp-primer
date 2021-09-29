#include<algorithm>
#include<vector>
#include<iostream>
#include<deque>
#include<iterator>

using namespace std;
int
main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v1, v2;
    deque<int> v3;
    // insterter 返回 An insert_iterator that inserts elements into x at the position indicated by it.
    copy(v.begin(), v.end(), inserter(v1, v1.begin()));
    copy(v.begin(), v.end(), back_inserter(v2));
    copy(v.begin(), v.end(), front_inserter(v3));
    for (auto i : v1) cout << i << " "; cout << endl;
    for (auto i : v2) cout << i << " "; cout << endl;
    for (auto i : v3) cout << i << " "; cout << endl;
    cout << "-------" << endl;
    ostream_iterator<int> out(cout, " ");
    copy(v1.begin(), v1.end(), out);
    cout << endl;
    copy(v2.begin(), v2.end(), out);
    cout << endl;
    copy(v3.begin(), v3.end(), out);
    cout << endl;
}