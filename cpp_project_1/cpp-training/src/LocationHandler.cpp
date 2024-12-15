#include"LocationHandler.hpp"
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
LocationHandler::LocationHandler(const Location& location) noexcept : location(location)
{
}
void LocationHandler::Move(void)noexcept
{
    switch (location.heading) 
    {
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
}
void LocationHandler::TurnLeft(void)noexcept
{
    int dirIndex = ToInt(location.heading);  // 获得当前朝向的数字索引
    dirIndex = (dirIndex + 3) % 4;  // 用取模运算实现转向
    location.heading = FromInt(dirIndex);
}
void LocationHandler::TurnRight(void)noexcept
{
    int dirIndex = ToInt(location.heading);  // 获得当前朝向的数字索引
    dirIndex = (dirIndex + 1) % 4;
    location.heading = FromInt(dirIndex);
}
Location LocationHandler::GetInfo(void) const noexcept
{
    return location;
}
void LocationHandler::FastChange(void)noexcept
{
    isFastMove=!isFastMove;
}
bool LocationHandler::IsFastMove(void)const noexcept
{
    return isFastMove;
}
}