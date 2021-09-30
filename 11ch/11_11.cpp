#include<set>
#include"7ch/7_20.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    // they are all ok
    // Less is a pointer of function which receive two arguments and return bool value.
    // bool (*Less)(const Sales_data &, const Sales_data &);
    using Less = bool (*)(const Sales_data &, const Sales_data &);
    std::multiset<Sales_data, Less> bookstore(compareIsbn);
}