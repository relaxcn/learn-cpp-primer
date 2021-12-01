#ifndef CP5_CH14_EX14_13_H
#define CP5_CH14_EX14_13_H

#include <string>
#include <iostream>

class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&); // input
    friend std::ostream& operator<<(std::ostream&, const Sales_data&); // output
    friend Sales_data operator+(const Sales_data&, const Sales_data&); // addition
    friend Sales_data operator-(const Sales_data&, const Sales_data&); // sub

public:
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p){ }
    Sales_data() : Sales_data("", 0, 0.0f){ }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f){ }
    Sales_data(std::istream &is) : Sales_data() {
        is >> *this;
    }

    // += operator
    Sales_data& operator+=(const Sales_data& lhs) {
        units_sold += lhs.units_sold;
        revenue += lhs.revenue;
        return *this;
    } // compound-assignment

    Sales_data& operator-=(const Sales_data &lhs) {
        units_sold -= lhs.units_sold;
        revenue -= lhs.revenue;
        return *this;
    }
    std::string isbn() const { return bookNo; }

private:
    inline double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// 输入运算符
std::istream& operator>>(std::istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = item.units_sold * price;
    // 如果出错，则返回一个空的实例
    else
        item = Sales_data();
    return is;
}

// 输出运算符
std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data operator-(const Sales_data& lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum -= rhs;
    return sum;
}

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}

#endif // CP5_CH14_EX14_02_H