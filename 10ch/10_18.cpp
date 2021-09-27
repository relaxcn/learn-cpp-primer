#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

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

void bigests(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
    // 这里将find_if更换成partition
    auto wc = partition(words.begin(), words.end(), 
        [sz](const string &s1){ return s1.size() > sz;});
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
        [] (const string &s) { cout << s << " "; });
    cout << endl;
}