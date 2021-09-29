#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;

string make_plural(const int count, const string &s1, const string &s2)
{
    return (count > 1) ? s1+s2 : s1;
}

void
elimDups(vector<string> &v)
{
    sort(v.begin(), v.end());
    auto end_unique = unique(v.begin(), v.end());
    v.erase(end_unique, v.end());
}

bool
check_size(const string &s, string::size_type size)
{
    return s.size() > size;
}

void bigests(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
    // 将lambda表达式换成bind形式的函数调用
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
        [] (const string &s) { cout << s << " "; });
    cout << endl;
}