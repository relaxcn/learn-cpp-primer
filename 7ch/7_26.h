#include<iostream>
#include<string>
struct Sales_data {
    // 成员函数
    // 内部实现
    std::string isbn() const {
        return bookNo;
    }
    // 在外部实现
    Sales_data &combine( const Sales_data &);
    inline double avg_price() const;
    // 成员变量
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline double
Sales_data::avg_price() const
{
    if ( units_sold )
        return revenue / units_sold;
    else
        return 0;
}