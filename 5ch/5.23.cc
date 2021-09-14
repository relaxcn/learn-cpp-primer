#include<iostream>
#include<stdexcept>
using namespace std;

int main()
{
    cout << "Type two numbers:" << endl;
    int n1 = 0, n2 = 0;
    double sul = 0;
    cin >> n1 >> n2;
    try
    {
        sul = (static_cast<double>(n1))/n2;
        throw runtime_error("h");
    }
    catch( ... )
    {
        std::cerr << "err" << '\n';
    }
    cout << sul << endl;
    return 0;
    
}