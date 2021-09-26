#include<vector>
#include<string>
#include<iostream>
using namespace std;
int
main()
{
    string word;
    vector<string> sv;
    double sum;
    while (cin >> word) {
        double num = stod(word);
        sum += num;
    }
    cout << "sum: " << sum << endl;

}