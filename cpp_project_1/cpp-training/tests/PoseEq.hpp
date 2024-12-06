#pragma once
#include"Executor.hpp"
//将==重载独立出来
namespace adas
{
    bool operator==(const Location& lhs, const Location& rhs);
}