#include<map>
#include<string>

int main()
{
    std::map<int ,std::string> map;
    map[25] = "first";
    std::map<int, std::string>::iterator it = map.begin();
    it->second = "second";
}