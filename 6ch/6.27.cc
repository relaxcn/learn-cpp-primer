#include<iostream>
#include<initializer_list>
#include<vector>
#include<cstdlib>
using namespace std;
extern int sum( initializer_list<int> list );
int 
main( int argc, char **argv )
{
    cout << sum({1,2,3,4,5}) << endl;
    return EXIT_SUCCESS;
}

int
sum( initializer_list<int> list )
{
    int sum = 0;
    for( auto num : list )
        sum += num;
    return sum;
}