#include"test.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    ifstream ifs("./book.txt");
    StrBlob blob;
    for (string str; getline(cin, str); ) {
        blob.push_back(str);
    }

    for (StrBlobPtr pbeg = blob.begin(), pend = blob.end(); pbeg != pend; pbeg.incr()) {
        cout << pbeg.deref() << endl;
    }

}