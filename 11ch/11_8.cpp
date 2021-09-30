#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::find;

vector<string>
make_vector()
{
    vector<string> vec;
    for (string word; cin >> word; ) {
        if (find(vec.begin(), vec.end(), word) == vec.end())
            vec.push_back(word);
    }
    return vec;
}

void print( vector<string> vec )
{
    for (auto word : vec)
        cout << word << " ";
    cout << endl;
}

int
main()
{
    print(make_vector());
}