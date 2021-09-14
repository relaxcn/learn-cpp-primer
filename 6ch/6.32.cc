#include<iostream>
using namespace std;
extern int &get( int *array, int index );
int
main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
    for (int *ptr = ia; ptr < (ia+10); ++ptr)
        cout << *ptr << " ";

    return 0;
}

int &
get( int *array, int index )
{
    return array[index];
}