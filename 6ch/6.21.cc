#include<iostream>
using namespace std;
extern int bigger( int a, int *b );

int
main()
{

}

int
bigger( int a, int *b )
{
    return ( a > *b ) ? a : *b;
}