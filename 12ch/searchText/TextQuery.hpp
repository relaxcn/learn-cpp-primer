#ifndef TEXT_QUERY_HPP
#define TEXT_QUERY_HPP
#include<sstream>
#include<fstream>
#include<set>
#include<memory>
#include<map>
#include<vector>
#include<string>

class QueryResult;
class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    // query function
    QueryResult query(const std::string &) const;
private:
    // the lines of string of reading from file.
    std::shared_ptr<std::vector<std::string>> file;
    // 映射
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream& ifs) : file(new std::vector<std::string>) {
    std::string text;
    while (std::getline(ifs, text)) {
        // 填充vector
        file->push_back(text);
        // 填充Map
        // line number
        int n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        // process lines for each other
        while (line >> word) {
            // a pointer of share_prt for set<line_no>
            auto &lines = wm[word];
            // 如果为空
            if (!lines) {
                // 分配空间
                lines.reset(new std::set<line_no>);
                // lines = std::make_shared<std::set<line_no>>();
            }
            lines->insert(n);
        }
    }
}



class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f) :
        sought(s), lines(p), file(f) { }

private:
    std::string sought; // query word string
    std::shared_ptr<std::set<line_no>> lines; // a set of lines number
    std::shared_ptr<std::vector<std::string>> file; // vector for lines of file
};

QueryResult
TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<line_no>> nodata = std::make_shared<std::set<line_no>>();
    auto loc = wm.find(sought);
    if (loc == wm.end()) 
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " " << (qr.lines->size() > 1 ? "times" : "time") << std::endl;
    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") " << qr.file->at(num) << std::endl;
    }
    return os;
}

#endif