#include<string>

class Employee {
public:
    Employee() {
        num = ++snum;
    };
    Employee(std::string sname):name(sname), num(++snum){ }
    int num;
    static int snum;
private:
    std::string name;
};

int Employee::snum = 0;
