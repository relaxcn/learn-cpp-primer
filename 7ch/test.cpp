#include<iostream>
using namespace std;
#include"7_27.h"
int
main()
{
    system("chcp 65001");
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << '\n';
    myScreen.display(cout);
    cout << '\n';
    cout << "你好" << endl;
}