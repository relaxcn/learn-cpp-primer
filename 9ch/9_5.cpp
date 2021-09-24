#include<vector>
using namespace std;

//  未找到则返回end
vector<int>::iterator
find( vector<int>::iterator begin, vector<int>::iterator end, int i)
{
    while(begin != end) {
        if (*begin == i) {
            return begin;
        }
        ++begin;
    }
    return end;
}