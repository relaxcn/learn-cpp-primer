#include<iostream>
#include<string>
struct Sales_data {
public:
    // 友元 可以访问私有成员变量
    friend std::istream &read( std::istream &is, Sales_data &item );
    friend std::ostream &print( std::ostream &, const Sales_data & );
    // 构造函数 重载
    Sales_data( const std::string &s, unsigned n, double p ) : 
                bookNo(s) , units_sold(n), revenue(p*n) { std::cout << "三参构造函数已执行。" << std::endl; };
    // 委托构造函数
    Sales_data() : Sales_data("", 0, 0.0) { std::cout << "Sales_data()已执行。" << std::endl; };
    Sales_data( const std::string &s ) : Sales_data(s, 0, 0.0) { std::cout << "Sales_data( const std::string &s )已执行。" << std::endl;; }
    Sales_data( std::istream &is ) : Sales_data() {
        read( is, *this );
        std::cout << "Sales_data( std::istream &is )已执行。" << std::endl;
    }
    // 成员函数
    // 内部实现
    std::string isbn() const {
        return bookNo;
    }
    // 在外部实现
     Sales_data &combine( const Sales_data &);
private:
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

int
main()
{
    system("chcp 65001");
    Sales_data s2();
    Sales_data s1("hello");
    Sales_data s3(std::cin);
    return 0;
}