#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    for( vector<int>::size_type index = 0, size = (v1.size() < v2.size()) ? v1.size() : v2.size();
    index < size; ++index ) {
        if( v1[index] != v2[index] ) {
            cout << "flase" << endl;
            return -1;
        }
    }
    cout << "true" << endl;
    return 0;
}