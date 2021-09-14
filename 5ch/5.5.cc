#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char **argv)
{
    vector<string> s = {"F", "D", "C", "B", "A", "A++"};
    string letgrade;
    int grade;
    cin >> grade;
    if( grade < 60 )
        letgrade = s[0];
    else {
        letgrade = s[(grade-50)/10];
        if ( grade != 100 )
            if( grade % 10 > 7 )
                letgrade += '+';
            else if ( grade % 10 < 3 )
                letgrade += '-';
    }
    cout << letgrade << endl;
    return 0;
}