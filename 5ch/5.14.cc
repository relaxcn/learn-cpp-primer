#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string curS, perS, mS;
    unsigned cnt = 0, mCnt = 0;
    // test have  a stream come
    if( cin >> curS) {
        perS = curS;
        while( cin >> curS ) {
            if( perS == curS )
                ++cnt;
            else {
                if( cnt > mCnt ) {
                    mCnt = cnt;
                    mS = perS;
                }
                perS = curS;
                cnt = 0;
            }
        }
    }
    if( mCnt == 0 )
        cout << "None" << endl;
    else
        cout << mS << ": " << mCnt+1 << endl;
    return 0;
}