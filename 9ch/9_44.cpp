#include<iostream>
#include<sstream>
#include<string>
using namespace std;
// need change s
void test(string &s, string const &oldVal, string const &newVal);

int main()
{
    string s{ "straight thru is a foolish, tho courageous act." };
    // test(s, "tho", "though");
    test(s, "thru", "through");
    cout << s << endl;

    return 0;
}

void
test(string &s, string const &oldVal, string const &newVal)
{
    for(string::size_type i = 0; i < s.size() - oldVal.size(); ) {
        if (oldVal == s.substr(i, oldVal.size())) {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
        }
        else
            ++i;
    }
}