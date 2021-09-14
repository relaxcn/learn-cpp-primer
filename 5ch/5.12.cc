#include<iostream>
using namespace std;

int main()
{
    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char c = 0;
    while (cin >> c) {
        switch (c) {
            case 'f':
                {
                    cin >> c;
                    switch (c) {
                        case 'f':
                            ++ffCnt;
                            break;
                        case 'l':
                            ++flCnt;
                            break;
                        case 'i':
                            ++fiCnt;
                            break;
                        default:
                            break;
                    }
                }
            default:
                break;
        }
    }
    cout << "ffCnt:" << ffCnt << endl;
    cout << "flCnt:" << flCnt << endl;
    cout << "fiCnt:" << fiCnt << endl;
    return 0;
}