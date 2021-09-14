#include<iostream>
using namespace std;

int main()
{
    string flag;
    do {
        string v1, v2;
        cout << "Type two string:" << endl;
        cin >> v1 >> v2;
        cout << "The shoter string is:" << ( ( v1.size() < v2.size() ) ? v1 : v2 ) << endl;
        cout << "Do you want to continue? Type no or yes:";
        cin >> flag;
    } while( !flag.empty() && flag[0] != 'n' );
    cout << "Think for using." << endl;
    return 0;
}