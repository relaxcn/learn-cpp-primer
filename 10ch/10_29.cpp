#include<iterator>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int
main()
{
    ifstream ifs("./test.txt");
    istream_iterator<string> iter(ifs) ,eof;
    vector<string> vec(iter, eof);
    ostream_iterator<string> out(cout);
    for (auto i : vec) cout << i << " ";
    cout << endl;
}