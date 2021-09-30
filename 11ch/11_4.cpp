#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<cctype>

using std::find_if;
using std::map;
using std::string;
using std::cout;
using std::cin;
using std::endl;

auto strip(string& str) -> string const&
{
    for (auto& ch : str) ch = tolower(ch);
    str.erase(find_if(str.begin(), str.end(), ispunct), str.end());
    return str;
}

auto strip_and_count()
{
    map<string, size_t> counts;
    for (string w; cin >> w; ++counts[strip(w)]);
    return counts;
}

int
main()
{
    map<string, size_t> word_count = strip_and_count();
    for (const auto &w: word_count)
        cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << endl;
}