#include<memory>
#include<string>
#include<iostream>

int main()
{
    int n;
    std:: cin >> n;
    std::allocator<std::string> alloc;
    std::string* const p = alloc.allocate(n); // 使得p为指针常量，不可变
    std::string* q = p; // q指向第一个string
    std::string s;
    while (q != p + n && std::cin >> s) {
        alloc.construct(q++, s);
    }
    std::cout << "---------" << std::endl;
    while (q != p) {
        std::cout << *--q << std::endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
}