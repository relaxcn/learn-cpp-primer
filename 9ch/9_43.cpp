#include<iostream>
#include<sstream>
#include<string>
using namespace std;
// need change s
void test(string &s, string const &oldVal, string const &newVal);

int main()
{
    string s{ "To drive straight thru is a foolish, tho courageous act." };
    // test(s, "tho", "though");
    test(s, "thru", "through");
    cout << s << endl;

    return 0;
}

void
test(string &s, string const &oldVal, string const &newVal)
{
    for(auto beg = s.begin(); beg < s.end() - oldVal.size(); ) {
        if (oldVal == string(beg, beg + oldVal.size())) {
            beg = s.erase(beg, beg + oldVal.size());
            beg = s.insert(beg, newVal.begin(), newVal.end());
            beg += newVal.size();
        }
        else
            ++beg;
    }
}