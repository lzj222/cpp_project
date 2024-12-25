#pragma once
#include"ExecutorImpl.hpp"
#include"LocationHandler.hpp"
#include<functional>
namespace adas
{

    class MoveCommand final
    {
    public:
        void operator()(LocationHandler& locationHandler) const noexcept
        {
            if(locationHandler.IsFastMove())
            {
                locationHandler.Move();
            }//如果处于加速状态，就再走一格
            locationHandler.Move();
        };
    };
    class TurnLeftCommand final
    {
    public:
        void operator()(LocationHandler& locationHandler) const noexcept
        {
            if(locationHandler.IsFastMove())
            {
                locationHandler.Move();
            }//如果处于加速状态，就再走一格
            locationHandler.TurnLeft();
        };
    };
    class TurnRightCommand final
    {
    public:
        void operator()(LocationHandler& locationHandler) const noexcept
        {
            if(locationHandler.IsFastMove())
            {
                locationHandler.Move();
            }//如果处于加速状态，就再走一格
            locationHandler.TurnRight();
        };
    };
    class FastCommand final
    {
    public:
        void operator()(LocationHandler& locationHandler) const noexcept
        {
            locationHandler.FastChange();
        };
    };
}