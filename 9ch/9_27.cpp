#include<forward_list>
#include<iostream>
using namespace std;
int
main()
{
    forward_list<int> flst{1, 2, 3, 4 ,5, 6 , 7};
    auto per = flst.before_begin();
    for(auto curr = flst.begin(); curr != flst.end();) {
        // remove odd value
        if (*curr % 2)
            curr = flst.erase_after(per);
        // if value is even
        else {
            per = curr;
            ++curr;
        }
    }
    // print
    for(auto i : flst) cout << i << ' ';
    cout << endl;
}