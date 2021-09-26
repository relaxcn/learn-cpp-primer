#include<string>
#include<iostream>
using namespace std;
int
main()
{
    string s("1/1/1990");
    cout << s.substr(0, s.find_first_of("/")) << endl;
    cout << s.substr(s.find_first_of("/")+1, s.find_last_of("/") - s.find_first_of("/")-1) << endl;;
    cout << s.substr(s.find_last_of("/") + 1) << endl;
}