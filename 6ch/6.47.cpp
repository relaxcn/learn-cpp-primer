#include<iostream>
#include<vector>
// #define NDEBUG
using namespace std;
extern void print_t( vector<int> v, vector<int>::size_type size );

int
main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    print_t( v, v.size() );
    return 0;
}

void
print_t( vector<int> v, vector<int>::size_type size )
{
    // 终止条件
    if( size == 0 )
        return;
    cout << v[--size] << " ";
    #ifndef NDEBUG
    cerr << __func__ << " :time :" << __TIME__ << endl;
    #endif
    print_t( v, size );
    
}