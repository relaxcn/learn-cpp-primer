#include<set>
#include<map>
#include<iostream>

using namespace std;

int main()
{
    std::multimap<string, string> authors = {
        {"alan", "DMA"},
        {"pezy", "LeetCode"},
        {"xiuhuo", "weihei"},
        {"xiuhuo", "houl"},
        {"pezy", "nini"},
        {"xiuhuo", "niubier"}
    };
    // 重要，将第二个key编程multiset，再将之前的数据导入
    std::map<string, multiset<string>> order_authors;
    for (const auto &author : authors) {
        order_authors[author.first].insert(author.second);
    }
    for (const auto &author : order_authors) {
        cout << author.first << " : ";
        for (const auto &work : author.second) {
            cout << work << " ";
        }
        cout << endl;
    }
}