#include<iostream>
using namespace std;

int main()
{
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, other = 0;
    unsigned int spaceCnt = 0, tabCnt = 0, returnCnt = 0;
    string s;

    
    while( getline(cin, s) ) {
        for( char c : s ) {
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
                case ' ':
                    ++spaceCnt;
                    break;
                case '\t':
                    ++tabCnt;
                    break;
                case '\n':
                    ++returnCnt;
                    break;
                default:
                    ++other;
                    break;
            }
        }
    }
    cout << "aCnt:" << aCnt << endl;
    cout << "eCnt:" << eCnt << endl;
    cout << "iCnt:" << iCnt << endl;
    cout << "oCnt:" << oCnt << endl;
    cout << "uCnt:" << uCnt << endl;
    cout << "spaceCnt:" << spaceCnt << endl;
    cout << "tabCnt:" << tabCnt << endl;
    cout << "returnCnt:" << returnCnt << endl;
    cout << "other:" << other << endl;
    return 0;
}