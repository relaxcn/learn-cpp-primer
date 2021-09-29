#include<fstream>
#include<iterator>
#include<iostream>
#include<vector>
using namespace std;

int
main()
{
    ifstream input("./numbers.txt");
    istream_iterator<int> iter(input), eof;
    vector<int> vec(iter, eof);
    ofstream out1("./out1.txt"), out2("./out2.txt");
    ostream_iterator<int> out1_iter(out1, " "), out2_iter(out2, "\n");
    for(auto i : vec) {
        // odd
        if (i % 2)
            *out1_iter = i;
        else
            *out2_iter = i;
    }
}