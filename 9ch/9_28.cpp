#include<forward_list>
#include<string>
using namespace std;

void
insert( forward_list<string> slist, string first, string second )
{
    
    auto ptr = slist.before_begin();
    for(auto curr = slist.begin(); curr != slist.end(); ptr = curr++) {
        if (*curr == first) {
            slist.insert_after(curr, second);
            return;
        }
    }
    // curr = slist.end()
    slist.insert_after(ptr, second);
}