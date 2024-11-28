#include "ExecutorImpl.hpp"
namespace adas
{
char ToInt(char c)
{
    std::unordered_map<char, int> dirMap = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
    return dirMap[c];
}
char FromInt(int i)
{
    std::unordered_map<int, char> dirMap = {{0, 'N'}, {1, 'E'}, {2, 'S'}, {3, 'W'}};
    return dirMap[i];
}
// 抽象类的初始化函数
Executor* Executor::CreateExecutor(const Location& location) noexcept
{
    return new (std::nothrow) ExecutorImpl(location);  // 不会抛异常的new
}
ExecutorImpl::ExecutorImpl(const Location& location) noexcept : location(location)
{
}
void ExecutorImpl::DoCommand(const std::string& commands) noexcept
{
    int dirIndex = ToInt(location.heading);  // 获得当前朝向的数字索引
    for (const auto command : commands) {
        switch (command) {
        case 'M':
            switch (location.heading) {
            case 'N':
                location.y++;
                break;
            case 'S':
                location.y--;
                break;
            case 'E':
                location.x++;
                break;
            case 'W':
                location.x--;
                break;
            }
            break;
        case 'L':
            dirIndex = (dirIndex + 3) % 4;  // 用取模运算实现转向
            location.heading = FromInt(dirIndex);
            break;
        case 'R':
            dirIndex = (dirIndex + 1) % 4;
            location.heading = FromInt(dirIndex);
            break;
        }
    }
}
Location ExecutorImpl::GetInfo(void) const noexcept
{
    return location;
}
}
