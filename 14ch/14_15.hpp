#ifndef CP5_CH14_EX14_15_H
#define CP5_CH14_EX14_15_H

#include <iostream>
#include <string>

class Book {
    friend std::istream& operator>>(std::istream&, Book&);
    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
    friend bool operator>(const Book&, const Book&);
    friend bool operator<(const Book&, const Book&);
    friend Book operator+(const Book&, const Book&);

public:
    Book() = default;
    Book(unsigned no, std::string name, std::string author, std::string pubdate):no_(no), name_(name), author_(author), pubdate_(pubdate) { }
    Book(std::istream &in) { in >> *this; }

    Book &operator+=(const Book &rhs) {
        if (*this == rhs)
            this->number_ += rhs.number_;
        return *this;
    }

private:
    unsigned no_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
    unsigned number_;
};

// 输入运算符
std::istream& operator>>(std::istream& is, Book& book) {
    is >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_;
    if (is);
    else
        book = Book();
    return is;
}

// 输出运算符
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << book.no_ << " " << book.name_ << " " << book.author_ << " " << book.pubdate_;
    return os;
}

bool operator==(const Book& book1, const Book& book2) {
    return book1.no_ == book2.no_;
}

bool operator!=(const Book& lsh, const Book& rsh) {
    return !(lsh == rsh);
}

bool operator<(const Book& lhs, const Book& rhs) {
    return lhs.no_ < rhs.no_;
}

bool operator>(const Book& lhs, const Book& rhs) {
    return lhs.no_ > rhs.no_;
}

Book operator+(const Book& lhs, const Book& rhs) {
    Book sum = lhs;
    sum += rhs;
    return sum;
}


#endif // CP5_CH14_EX14_12_H