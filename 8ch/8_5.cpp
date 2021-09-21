#include<fstream>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int
main( int argc, char **argv )
{
    vector<string> v;
    if (argc < 2 || argc > 3) {
        cerr << "use: ./a.out [file.name]" << endl;
        return -1;
    }
    ifstream input(*(argv+1), ifstream::in);
    string s;
    while (input >> s)
    {
        v.push_back(s);
        cout << s << endl;
    }
    input.close();
}