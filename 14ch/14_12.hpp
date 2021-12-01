#ifndef CP5_CH14_EX14_12_H
#define CP5_CH14_EX14_12_H

#include <iostream>
#include <string>

class Book {
    friend std::istream& operator>>(std::istream&, Book&);
    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);

public:
    Book() = default;
    Book(unsigned no, std::string name, std::string author, std::string pubdate):no_(no), name_(name), author_(author), pubdate_(pubdate) { }
    Book(std::istream &in) { in >> *this; }

private:
    unsigned no_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};

// 输入运算符
std::istream& operator>>(std::istream& is, Book& book) {
    is >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_;
    if (is);
    else
        book = Book();
    return is;
}

std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);


#endif // CP5_CH14_EX14_12_H