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