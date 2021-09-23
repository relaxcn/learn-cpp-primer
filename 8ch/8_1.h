#ifndef H_8_1
#define H_8_1
#include<iostream>
#include<string>
using namespace std;

istream &test(istream &is)
{
    while (is.eof() != true) {
        string s;
        is >> s;
        cout << s << endl;;
    }
    cout << "get eof state." << endl;
    is.clear();
    cout << "haved cleared istream." << endl;
    return is;
}
#endif