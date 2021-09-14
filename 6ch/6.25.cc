#include<iostream>
#include<cstring>
using namespace std;
int
main( int argc, char *argv[] )
{
    if( argc != 3 ) {
        cerr << "Wrong arguments!" << endl;
        return -1;
    }
    char sum[100];
    strcpy( sum, argv[1] );
    strcat( sum, argv[2] );
    string s = sum;
    cout << s << endl;
    return 0;
}