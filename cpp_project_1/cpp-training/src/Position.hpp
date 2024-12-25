#pragma once
namespace adas
{
class Position final
{
private:
    int x;
    int y;
public:
//构造与析构函数
    Position() noexcept=default;
    Position(const int x,const int y) noexcept;
    Position(const Position& position) noexcept;
    Position& operator=(const Position& position) noexcept;
    Position& operator+=(const Position& position) noexcept;
    ~Position() noexcept = default;
//其他成员函数
    int GetX(void) const noexcept;
    int GetY(void) const noexcept;

};
}