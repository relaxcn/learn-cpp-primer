#include<iostream>
#include<string>
#include<utility>
#include<vector>
using std::pair;
using std::string;
using std::cin;
using std::vector;
using std::cout;


int
main()
{
    std::vector<std::pair<std::string, int>> vec;
    for (std::string word; cout<< "First:\n", std::cin >> word && word != "@q"; )
        for (int num; cout << "Second:\n", std::cin >> num && num != -1; ) {
            // 四种方法构造
            vec.push_back(std::make_pair(word, num));
            vec.push_back(pair<string, int>(word, num));
            vec.emplace_back(word, num);
            vec.push_back({word, num});
            break;
        }
    
    for (auto i : vec)
            cout << i.first << " " << i.second << "\n";
}