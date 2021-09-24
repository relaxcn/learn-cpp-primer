#include<list>
using namespace std;

list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();

int main() {
    // it's wrong. Because the address of nodes of list can be not continuous.
    // while (iter1 < iter2)
    // {

    // }
}