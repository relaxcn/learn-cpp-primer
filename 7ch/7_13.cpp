// 使用 istream 构造函数重写第229页的程序
#include<iostream>
#include"7_12.h"
using namespace std;

int
main()
{
    Sales_data total(cin);
    if (!total.isbn().empty()) {
        // 检测输入流中是否还有数据
        while (cin) {
            Sales_data trans(cin);
            if(!cin) break;
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No Data?" << endl;
    }
}