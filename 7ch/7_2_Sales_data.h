#include<string>
struct Sales_data {
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

Sales_data add( const Sales_data &, const Sales_data & );
std::ostream &print( std::ostream &, const Sales_data & );
std::istream &read( std::istream &, Sales_data & );

// 成员函数外部实现
Sales_data &
Sales_data::combine( const Sales_data &rhs )
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double
Sales_data::avg_price() const
{
    if ( units_sold )
        return revenue / units_sold;
    else
        return 0;
}

std::istream &
read( std::istream &is, Sales_data &item )
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &
print( std::ostream &os, const Sales_data &item )
{
    os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return os;
}