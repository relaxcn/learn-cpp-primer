#include<iostream>
class Test {
    Test(std::istream &is) :ist(is) { };
    std::istream &ist;
};