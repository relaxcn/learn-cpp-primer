#include<iostream>
#include<cctype>
using namespace std;
extern bool isHaveUpper( const string s );
extern void sToUpper( string &s );

int
main()
{
    cout << "Type a string:";
    string s;
    cin >> s;
    cout << "Does the string have upper words? " << ( (isHaveUpper(s)) ? "yes!" : "no!" ) << endl;
    cout << "To be upper is:" << endl;
    sToUpper( s );
    cout << s << endl;
    return 0;
}

bool
isHaveUpper( const string s )
{
    for( auto c : s )
        if(isupper(c))
            return true;
    return false;
}

void
sToUpper( string &s )
{
    for( auto &c : s )
        c = toupper(c);
}