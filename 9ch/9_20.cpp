#include<list>
#include<deque>
#include<iostream>
using namespace std;

int
main()
{
    list<int> li{1, 2, 3, 4, 5};
    deque<int> d1;
    deque<int> d2;
    for(auto i : li) {
        if(i % 2 == 0)
            d2.push_back(i);
        else
            d1.push_back(i);
    }
    for(auto i : d1)
        cout << i << " ";
    cout << endl;
    for(auto i : d2)    cout << i << " ";
    cout << endl;
    return 0;
}