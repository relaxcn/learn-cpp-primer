#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int
main()
{
    istream_iterator<int> iter(cin), eof;
    ostream_iterator<int> out(cout);
    vector<int> vec(iter, eof);
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), out);
}