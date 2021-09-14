#include<iostream>
#include<vector>
using namespace std;

int main()
{
    unsigned int cnt = 0;
    unsigned int other = 0;
    char c = 0;
    while( cin >> c ) {
        switch( c ) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++cnt;
                break;
            default:
                ++other;
                break;
        }
    }
    cout << "cnt:" << cnt << " other:" << other << endl;
    return 0;
}