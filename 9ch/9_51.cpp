#include<string>
#include<iostream>
using namespace std;

class Test {
    unsigned year;
    unsigned month;
    unsigned day;
public:
    Test(string date) {
        unsigned format = -1;
        unsigned tag = 0;
        // 1/1/1990
        if(date.find_first_of('/') != string::npos) {
            format = 0;
        }
        // January 1,1900
        if(date.find_first_of(",") != string::npos) {
            format = 1;
        }
        // jan 1 1900
        if(date.find_first_of("/,") == string::npos) {
            format = 1;
            tag = 1;
        }

        switch (format) {
            case 0:
                day = stoi(date.substr(0, date.find('/')));
                month = stoi(date.substr(date.find('/')+1, date.find_last_of("/") - date.find_first_of("/") - 1));
                year = stoi(date.substr(date.find_last_of("/") + 1));
                break;
            case 1:
                if( date.find("Jan") != string::npos )  month = 1;
                if( date.find("Feb") != string::npos )  month = 2;
                if( date.find("Mar") != string::npos )  month = 3;
                if( date.find("Apr") != string::npos )  month = 4;
                if( date.find("May") != string::npos )  month = 5;
                if( date.find("Jun") != string::npos )  month = 6;
                if( date.find("Jul") != string::npos )  month = 7;
                if( date.find("Aug") != string::npos )  month = 8;
                if( date.find("Sep") != string::npos )  month = 9;
                if( date.find("Oct") != string::npos )  month =10;
                if( date.find("Nov") != string::npos )  month =11;
                if( date.find("Dec") != string::npos )  month =12;
                // January 1,1900
                if (tag == 0) {
                    day = stoi(date.substr(date.find_first_of("1234567890"), date.find(",") - date.find_first_of("1234567890")));
                    year = stoi(date.substr(date.find_first_of(",") + 1));
                }
                // Jan 1 1900
                else {
                    day = stoi(date.substr(date.find_first_of("1234567890"), date.find_last_of(" ") - date.find_first_of("1234567890")));
                    year = stoi(date.substr(date.find_last_of(" ") + 1));
                }
        }
    }
    void print() {
        cout << "year:" << year << endl;
        cout << "month:" << month << endl;
        cout << "day:" << day << endl;
    }
};

int
main()
{
    string s1{"January 1,1900"};
    Test date1(s1);
    date1.print();
    cout << "-------\n";
    Test("1/1/1900").print();
    cout << "-------\n";
    Test("Jan 1 1900").print();

}