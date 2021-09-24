#include<vector>
bool find(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int i)
{
    while(begin != end) {
        if (*begin == i)
            return true;
        ++begin;
    }
    return false;
}