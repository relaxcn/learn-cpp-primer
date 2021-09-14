#include<iostream>
#include<string>
using namespace std;
// 默认实参
extern string make_pulural(size_t ctr, const string &word, const string &ending = "s" );

int 
main()
{
    const string word = {"apple"};
    size_t size = 2;
    string result = make_pulural( size, word );
    cout << result << endl;
    return 0;
}

string
make_pulural( size_t ctr, const string &word, const string &ending )
{
    return (ctr > 1) ? word + ending : word;
}