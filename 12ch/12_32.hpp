#ifndef EX_12_32_HPP
#define EX_12_32_HPP
// use StrBlob class
#include"test.h"
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
    // only use StrBlob object to instand 'file'
    // std::shared_ptr<std::vector<std::string>> file;
    StrBlob file;
    // 映射
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream& ifs) {
    std::string text;
    while (std::getline(ifs, text)) {
        // 填充vector
        // file->push_back(text);
        file.push_back(text);
        // 填充Map
        // line number
        // int n = file->size() - 1;
        int n = file.size() - 1;
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
    friend std::ostream& print(std::ostream&, QueryResult&);
public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, StrBlob f) :
        sought(s), lines(p), file(f) { }

private:
    std::string sought; // query word string
    std::shared_ptr<std::set<line_no>> lines; // a set of lines number
    StrBlob file; // vector for lines of file
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

std::ostream &print(std::ostream &os, QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " " << (qr.lines->size() > 1 ? "times" : "time") << std::endl;
    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") " << StrBlobPtr(qr.file, num).deref() << std::endl;
    }
    return os;
}

#endif