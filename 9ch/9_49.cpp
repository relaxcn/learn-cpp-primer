#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

int
main()
{
    ifstream ifs("./test.txt");
    if (!ifs) return -1;
    string longest;
    string word;
    while (ifs >> word) {
        if (word.find_first_not_of("aceimnorsuvwxz") == string::npos) {
            longest = longest.size() > word.size() ? longest : word;
        }
    }
    cout << longest << endl;
}