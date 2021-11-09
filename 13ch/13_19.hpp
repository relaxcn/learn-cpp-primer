/* 
    不需要，因为在现实中，员工不能被复制
*/
#include<string>

class Employee {
public:
    Employee() {
        num = ++snum;
    };
    Employee(std::string sname):name(sname), num(++snum){ }
    // copy constructor
    Employee(const Employee& ris) = default;
    // copy-assignmnet operator
    Employee &operator=(const Employee &) = default;
    
    const std::string get_name() { return name; }
private:
    std::string name;
    int num;
    static int snum;
};

int Employee::snum = 0;