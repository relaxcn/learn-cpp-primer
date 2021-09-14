#include<iostream>
using namespace std;

extern void reset( int &a );

int
main()
{
    int n = -1;
    cout << "Type a number:";
    cin >> n;
    reset( n );
    cout << "Ok! now it is zero." << endl;
    cout << "number:" << n << endl;
    return 0;
}

void
reset( int &a )
{
    a = 0;
}