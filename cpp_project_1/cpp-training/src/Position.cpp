#include"Position.hpp"
namespace adas
{
    Position::Position(const int x,const int y) noexcept:x(x),y(y)
    {
    }
    Position::Position(const Position& position) noexcept
    {
        x=position.x;
        y=position.y;
    }
    Position& Position::operator=(const Position& position) noexcept
    {
        x=position.x;
        y=position.y;
        return *this;
    }
    Position& Position::operator+=(const Position& position) noexcept
    {
        x+=position.x;
        y+=position.y;
        return *this;
    }
    int Position::GetX(void) const noexcept
    {
        return x;
    }
    int Position::GetY(void) const noexcept
    {
        return y;
    }
}