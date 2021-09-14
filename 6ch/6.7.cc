#include<iostream>
using namespace std;
extern int count_calls();

int
main()
{
    for( int i = 0; i < 10; ++i )
        cout << count_calls() << " ";
    return 0;
}

int
count_calls()
{
    static int count = 0;
    return ++count;
}