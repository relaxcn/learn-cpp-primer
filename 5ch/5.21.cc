#include<iostream>
using namespace std;

int main()
{
    string currS, perS;
    if( cin >> currS ) {
        perS = currS;
        while( cin >> currS ) {
            if( perS == currS && perS[0] == '_' ) {
                cout << "get it!:" << currS << endl;
                cout << "end" << endl;
                return 0;
            } else {
                perS = currS;
            }
        }
    }
    cout << "None" << endl;
    return -1;
}