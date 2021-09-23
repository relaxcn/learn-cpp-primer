#include<sstream>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int
main(int argc, char **argv)
{
    ifstream ifs(*(argv+1));
    string line, word;
    while(getline(ifs, line)) {
        istringstream iss(line);
        while (iss >> word) {
            cout << word << endl;
        }
    }
    return 0;
}