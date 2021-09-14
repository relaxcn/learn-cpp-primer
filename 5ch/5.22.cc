#include<iostream>
using namespace std;
extern int get_size();
int main()
{
    while( int sz = get_size() )
        if( sz <= 0 )
            continue;
    return 0;
}