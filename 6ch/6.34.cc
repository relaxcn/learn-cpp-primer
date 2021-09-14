#include<iostream>
using namespace std;
extern int factorial( int val );
int
main()
{
    cout << factorial(1);
    return 0;
}

int
factorial( int val )
{
    if( val != 0 )
        return factorial( val - 1 ) * ( val );
    return 1;
}