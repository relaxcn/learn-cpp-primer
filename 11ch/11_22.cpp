#include<map>
#include<string>
#include<vector>
#include<utility>

int main()
{
    std::map<std::string, std::vector<int>> Map;
    std::pair<std::map<std::string, std::vector<int>>::iterator, bool> it = Map.insert({"first", {1}});
}