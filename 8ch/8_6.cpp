#include"7ch/7_20.h"
#include<fstream>
#include<iostream>
using namespace std;

int
main(int argc, char **argv)
{
    ifstream input(*(argv+1), fstream::in);
    if(input) {
        cerr << "open file error:" << *(argv+1) << endl;
        return -1;
    }
    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No Data?!" << endl;
    }
    return 0;
}