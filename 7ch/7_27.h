#include<string>
class Screen {
public:
    typedef std::string::size_type pos;
    // 构造函数
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) { }
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
    // 内联函数 隐式
    char get() const {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    // 区分常量和非常量的重载函数
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    // 内部私有小函数
    void do_display(std::ostream &os) const {os << contents;}
};

inline Screen &
Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &
Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}

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