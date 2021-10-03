#include<map>
#include<utility>
#include<string>
#include<iostream>
using Map = std::multimap<std::string, std::string>;

int
main()
{
    Map map;
    for (std::string first; std::cout << "First:", std::cin >> first && first != "@q"; )
        for (std::string second; std::cout << "Second:", std::cin >> second && second != "@q"; ) {
            map.insert({first, second});
            break;
        }
    for (auto i : map)
        std::cout << i.first << ": " << i.second << std::endl;
}