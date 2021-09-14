#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<string> v = {"F", "D", "C", "B", "A", "A++"};
    int grade;
    string letgrade;
    cin >> grade;
    letgrade = (grade < 60) ? 
        v[0] : 
        ((grade != 100) ? 
            ((grade % 10 > 7) ? 
                v[(grade-50)/10] + '+' : 
                ((grade % 10 < 3) ? 
                    v[(grade-50)/10] + '-' : 
                    v[(grade-50)/10])): 
            v[(grade-50)/10]);
    cout << letgrade << endl;
    return 0;
}