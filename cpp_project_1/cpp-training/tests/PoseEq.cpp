#include"PoseEq.hpp"
#include<tuple>
//将==重载独立出来
namespace adas
{
    bool operator==(const Location& lhs, const Location& rhs)
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }
}