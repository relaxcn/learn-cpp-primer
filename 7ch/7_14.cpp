#include<iostream>
#include<string>
struct Sales_data {
    // 构造函数 重载
    // 显式初始化
    Sales_data() : bookNo("book"), units_sold(0), revenue(0) { };
    Sales_data( const std::string &s ) : bookNo(s) { }
    Sales_data( const std::string &s, unsigned n, double p ) : 
                bookNo(s) , units_sold(n), revenue(p*n) { };
    Sales_data( std::istream & );
    // 成员函数
    // 内部实现
    std::string isbn() const {
        return bookNo;
    }
    // 在外部实现
    Sales_data &combine( const Sales_data &);
    double avg_price() const;
    // 成员变量
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};