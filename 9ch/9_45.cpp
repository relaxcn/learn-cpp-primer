#include<string>
#include<iostream>
using namespace std;

string
change_name( string const name, string const perfix, string const suffix )
{
    string new_name(name);
    new_name.append(" "+suffix);
    // https://www.cplusplus.com/reference/string/string/insert/
    new_name.insert(name.cbegin(), perfix.begin(), perfix.end());
    return new_name;
}

int
main()
{
    string new_name = change_name("Chen", "Mr.", "Jr.");
    cout << new_name << endl;
}