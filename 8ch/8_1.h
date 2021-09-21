#ifndef H_8_1
#define H_8_1
#include<iostream>
#include<string>
using namespace std;


istream &
test(istream &is)
{
    string s;
    while(is >> s) {
        cout << s << endl;
    }
    is.clear();
    return is;
}
#endif