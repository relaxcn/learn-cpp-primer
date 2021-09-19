#ifndef EX8_1_H
#define EX8_1_H

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