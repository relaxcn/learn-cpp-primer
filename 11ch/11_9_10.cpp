#include<map>
#include<list>
#include<string>
#include<vector>
#include<list>

int
main()
{
    std::map<std::string, std::list<int>> m;

    // can be declared
    // because < is definded.
    std::map<std::vector<int>::iterator, int> mv;
    std::map<std::list<int>::iterator, int> lv;
}