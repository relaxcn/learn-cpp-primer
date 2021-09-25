#include<forward_list>
#include<iostream>
using namespace std;

int
main()
{
    forward_list<int> flist{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto curr = flist.begin(), prev = flist.before_begin(); curr != flist.end(); ) {
        // odd value
        if (*curr % 2) {
            curr = flist.insert_after(prev, *curr);
            ++curr; ++curr;
            ++prev; ++prev;
        }
        // even value
        else {
            curr = flist.erase_after(prev);
        }
    }
    for(auto i : flist) cout << i << " ";
    cout << endl;
}