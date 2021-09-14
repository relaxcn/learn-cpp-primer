#include<iostream>
using namespace std;

int main()
{
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, other = 0;
    char c = 0;
    while( cin >> c )
        switch( c ) {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            default:
                ++other;
                break;
        }
    cout << "aCnt:" << aCnt << endl;
    cout << "eCnt:" << eCnt << endl;
    cout << "iCnt:" << iCnt << endl;
    cout << "oCnt:" << oCnt << endl;
    cout << "uCnt:" << uCnt << endl;
    cout << "other:" << other << endl;
    return 0;
}