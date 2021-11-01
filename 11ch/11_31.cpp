#include<map>
#include<string>
#include<iostream>

using std::string;

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
    string author = "xiuhuo";
    string work = "weihei";
    for (auto pos = authors.equal_range(author); pos.first != pos.second; ++pos.first) {
        if (pos.first->second == work) {
            authors.erase(pos.first);
        }
    }
    for (const auto &author : authors)
        std::cout << author.first << " : " << author.second << std::endl;
}