#include<iostream>
using namespace std;
extern unsigned absolute_value(int num);

int
main()
{
    int num;
    while( cin >> num )
        cout << absolute_value(num) << endl;
    return 0;
}

// return the absolute value of num
unsigned
absolute_value( int num )
{
    return ( num >= 0 ) ? num : (-num);
}