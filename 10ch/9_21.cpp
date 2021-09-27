#include<algorithm>
#include<iostream>

int
main()
{
    int a = 0;
    [&a] ()-> bool {
        while (a != 0)
            --a;
        return true;
    }
}