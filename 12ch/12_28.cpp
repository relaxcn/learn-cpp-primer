#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<memory>
#include<sstream>
#include<algorithm>

int main()
{
    std::cout << "Please enter your text file: ";
    std::string file_name;
    std::cin >> file_name;
    std::ifstream ifs(file_name);
    std::vector<std::string> vec;
    std::set<unsigned> Set;
    std::map<std::string, std::set<unsigned>> Map;
    // read line
    std::string line;
    while ( std::getline(ifs, line) )
        vec.push_back(line);
    // 遍历vector，填充Map
    for (unsigned index = 0; index != vec.size(); ++index) {
        std::istringstream sstream(vec.at(index));
        std::string word;
        while (sstream >> word) {
            Map[word].insert(index);
        }
    }
    while(true) {
        std::cout << "Enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        auto result = Map.find(s);
        if (result != Map.end()) {
            auto Sset = result->second;
            std::cout << s << " occurs " << Sset.size() << ((Sset.size() > 1) ? " times\n" : " time\n");
            for (auto cbeg = Sset.cbegin(), cend = Sset.cend(); cbeg != cend; ++cbeg) {
                std::cout << "\t(line " << (*cbeg+1) << ") " << vec.at(*cbeg) << ";" << std::endl;
            }
        } else {
            std::cout << "Not Found!" << std::endl;
        }
    }
}