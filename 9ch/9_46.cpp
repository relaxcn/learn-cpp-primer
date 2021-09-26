#include<string>
#include<iostream>
using namespace std;

string
change_name( string const name, string const perfix, string const suffix )
{
    string new_name(name);
    new_name.insert(0, perfix);
    new_name.insert(new_name.size(), " "+suffix);
    return new_name;
}

int
main()
{
    string new_name = change_name("Chen", "Mr.", "Jr.");
    cout << new_name << endl;
}