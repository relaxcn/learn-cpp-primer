#include<iostream>
using namespace std;
extern void print( const int *a, size_t size );

int 
main()
{
    int i = 0;
    int j[2] = {0, 1};
    print( &i, 1 );
    print( j, 2 );
    return 0;
}

void
print( const int *a, size_t size )
{
    for( size_t i = 0; i < size; ++i )
        cout << a[i] << endl;
}