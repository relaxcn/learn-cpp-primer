#include<map>
#include<string>
#include<iostream>

int
main()
{
    std::map<std::string, int> Map;
    std::string word;
    while (std::cin >> word) {
        auto ret = Map.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }
    for (auto i : Map)
        std::cout << i.first << " occors:" << i.second << " times." << std::endl;
}