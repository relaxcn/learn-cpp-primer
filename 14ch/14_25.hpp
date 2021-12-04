#ifndef CP5_CH14_EX14_24_H
#define CP5_CH14_EX14_24_H

#include <iostream>
#include <string>

class Book {
    friend std::istream& operator>>(std::istream&, Book&);
    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
    friend Book operator+ (const Book&, const Book&);
    friend Book operator- (const Book&, const Book&);
    friend bool operator< (const Book&, const Book&);
    friend bool operator> (const Book&, const Book&);
    friend bool operator<=(const Book&, const Book&);
    friend bool operator>=(const Book&, const Book&);

public:
    Book() = default;
    Book(unsigned no, std::string name, std::string author, std::string pubdate):no_(no), name_(name), author_(author), pubdate_(pubdate) { }
    Book(std::istream &in) { in >> *this; }

    // copy constructor
    Book(const Book& book) : no_(book.no_), name_(book.name_), author_(book.author_), pubdate_(book.pubdate_) { }
    // move constructor
    Book(Book &&rhs) noexcept : no_(std::move(rhs.no_)), name_(std::move(rhs.name_)), author_(std::move(rhs.author_)), pubdate_(rhs.pubdate_) { std::cout << "move constructor call." << std::endl; }

    // copy operator=
    Book& operator=(const Book& book) {
        no_ = book.no_;
        name_ = book.name_;
        author_ = book.author_;
        pubdate_ = book.pubdate_;
    }

    // move operator=
    Book& operator=(Book&& rhs) noexcept {
        if (*this != rhs) {
            no_ = rhs.no_;
            name_ = rhs.name_;
            author_ = rhs.author_;
            pubdate_ = rhs.pubdate_;
        }
        std::cout << "move operator=" << std::endl;
        return *this;
    }
    Book operator+=(const Book& rhs) {
        pubdate_ += rhs.pubdate_;
        return *this;
    }

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

Book operator+(const Book& lhs, const Book& rhs) {
    Book sum = lhs;
    if (lhs == rhs)
        sum += rhs;
    return sum;
}

bool operator<(const Book& lhs, const Book& rhs) {
    return lhs.no_ < rhs.no_;
}

bool operator>(const Book& lhs, const Book& rhs) {
    return lhs.no_ > rhs.no_;
}

bool operator<=(const Book& lhs, const Book& rhs) {
    return !(lhs.no_ > rhs.no_);
}

bool operator>=(const Book& lhs, const Book& rhs) {
    return !(lhs.no_ < rhs.no_);
}

#endif // CP5_CH14_EX14_12_H