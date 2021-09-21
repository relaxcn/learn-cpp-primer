#include"8_1.h"
#include<sstream>
using namespace std;
int
main()
{
    istringstream iss;
    iss.str("hello world");
    test(iss);
    return 0;
}