#include"Direction.hpp"
namespace adas
{
    static const Position moves[]={
        Position(0,1),
        Position(1,0),
        Position(0,-1),
        Position(-1,0)
    };
    Direction::Direction(const unsigned index,const char heading) noexcept:index(index),heading(heading)
    {
    }
    static const Direction directions[]={
        Direction(0,'N'),
        Direction(1,'E'),
        Direction(2,'S'),
        Direction(3,'W')
    };//把朝不同方向的移动封装成一个数组
    //根据方向字符获取方向对象
    const Direction& Direction::GetDirection(const char heading) noexcept
    {
         // 遍历方向数组
        for(const auto& direction:directions)
        {
            // 如果找到匹配的方向字符
            if(direction.heading==heading)
            {
                // 返回该方向对象的引用
                return direction;
            }
        }
        return directions[0];
    }
    const char Direction::GetHeading(void) const noexcept
    {
        return heading;
    }
    const Position& Direction::Move(void) const noexcept
    {
        return moves[index];
    }//移动就是位置加上移动数组对应的元素
    const Direction& Direction::DirectionLeft(void) const noexcept
    {
        return directions[(index+3)%4];
    }//用取模运算实现转向
    const Direction& Direction::DirectionRight(void) const noexcept
    {
        return directions[(index+1)%4];
    }
}