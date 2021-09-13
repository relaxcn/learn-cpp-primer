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