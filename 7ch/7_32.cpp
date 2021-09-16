#include"7_27.h"
#include<vector>
#include<string>

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);
private:
    // 初始化屏幕
    std::vector<Screen> screens{Screen(24, 80, ' 1')};
};

// 友元类中的成员方法可以访问Screen中的成员变量
inline void
Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}