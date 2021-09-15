#include<iostream>
#include<string>
using namespace std;

struct Person {
    string name;
    string address;

    // const Person::this
    string getName() const {
        return name;
    }
    string  getAddress() const {
        return address;
    }
    // 构造函数
    Person() : name(" "), address(" ") { };
    Person(istream &is) {
        read(is, *this);
    }
    Person(const string sname, const string addr) : name(sname), address(addr) { };
};

istream &
read( istream &is, Person &per )
{
    is >> per.name >> per.address;
    return is;
}

ostream &
print( ostream &os, Person &per )
{
    os << per.getName() << " " <<  per.getAddress();
    return os;
}