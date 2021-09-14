#include<iostream>
using namespace std;
extern int fact(int x);
int main()
{
    int n = 0;
    while( cin >> n ) {
        cout << fact(n) << endl;
    }
    return 0;

}

int
fact( int x )
{
    int result = 1;
    for( int i = 1; i <= x; ++i) {
        result *= i;
    }
    return result;
}