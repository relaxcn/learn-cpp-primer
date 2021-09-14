#include<iostream>
#include"Chapter6.h"

using namespace std;

int
main()
{
    int num = 0;
    while( cin >> num )
        cout << fact(num) << endl;
    return 0;
}