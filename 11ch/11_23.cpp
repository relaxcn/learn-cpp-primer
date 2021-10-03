#include<map>
#include<vector>
#include<string>
#include<iostream>


using Map = std::multimap<std::string, std::string>;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

Map make_family()
{
    Map familys;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "Child name:\n", cin >> cn && cn != "@q";)
            familys.insert({ln, cn});
    return familys;
}

void print(Map familys)
{
    for (auto const &family : familys) {
        cout << family.first << ": " << family.second << endl;
    }
}

int
main()
{
    print(make_family());
}