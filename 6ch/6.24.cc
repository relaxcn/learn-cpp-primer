#include<iostream>
using namespace std;
extern void print( const int ia[10] );

int
main()
{
    int ia[1];
    print( ia );
    return 0;

}

// 类似于 const int * 不能直接认为数组有十个元素
void
print( const int ia[10] )
{
    for( size_t i = 0; i != 10; ++i )
        cout << ia[i] << endl;
}