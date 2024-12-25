#pragma once
#include"Position.hpp"
namespace adas
{
class Direction final
{
private:
    unsigned index;
    char heading;
public:
//构造与析构函数
    Direction() noexcept=default;
    Direction(const unsigned index,const char heading) noexcept;
    ~Direction() noexcept = default;
//获取方向
    static const Direction& GetDirection(const char heading) noexcept;
    const char GetHeading(void) const noexcept;
//移动
    const Position& Move(void) const noexcept;
//转向
    const Direction& DirectionLeft(void) const noexcept;
    const Direction& DirectionRight(void) const noexcept;
};
}