#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<utility>
using std::pair;

using Map = std::map<std::string, std::vector<pair<std::string, std::string>>>;
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
            for (string birthDay; cout << "BirthDay:\n", cin >> birthDay; ) {
                familys[ln].push_back(std::make_pair(cn, birthDay));
                break;
            }
    return familys;
}

void print(Map familys)
{
    for (auto const &family : familys) {
        cout << family.first << ":\n";
        for (auto const &child : family.second)
            cout << child.first << ":" << child.second << "* ";
        cout << endl;
    }
}

int
main()
{
    print(make_family());
}