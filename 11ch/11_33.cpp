#include<map>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

map<string, string> buildMap(ifstream &map_file);
void word_transform(ifstream &, ifstream &);
const string & transform(const string &, const map<string, string> &);

int main()
{
    ifstream map_file("./map_file.txt");
    ifstream input("./input.txt");
    word_transform(map_file, input);
    return 0;
}

void
word_transform(ifstream &map_file, ifstream &input) 
{
    auto strans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, strans_map);
        }
        cout << endl;
    }
}

map<string, string>
buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;

    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m)
{
    // find 返回一个指向查找元素的迭代器
    auto map_it = m.find(s);
    // if find
    if (map_it != m.cend()) {
        return map_it->second;
    } else {
        return s;
    }
}