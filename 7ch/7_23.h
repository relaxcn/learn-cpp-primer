#include<string>
class Screen {
public:
    typedef std::string::size_type pos;
    // 构造函数
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) { }
    // 内联函数 隐式
    char get() const {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

// 内敛成员函数 外部实现 显式声明 inline
char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}