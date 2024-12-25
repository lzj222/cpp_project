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
                if(locationHandler.IsReverse())
                {
                    locationHandler.BackMove();
                }
                else
                {
                    locationHandler.Move();
                }
            }//如果处于加速状态，就再走一格
            if(locationHandler.IsReverse())
            {
                locationHandler.BackMove();
            }
            else
            {
                locationHandler.Move();
            }
        };
    };
    class TurnLeftCommand final
    {
    public:
        void operator()(LocationHandler& locationHandler) const noexcept
        {
            if(locationHandler.IsFastMove())
            {
                if(locationHandler.IsReverse())
                {
                    locationHandler.BackMove();
                }
                else
                {
                    locationHandler.Move();
                }
                
            }//如果处于加速状态，就再走一格
            if(locationHandler.IsReverse())
            {
                locationHandler.TurnRight();
            }
            else
            {
                locationHandler.TurnLeft();
            }
        };
    };
    class TurnRightCommand final
    {
    public:
        void operator()(LocationHandler& locationHandler) const noexcept
        {
            if(locationHandler.IsFastMove())
            {
                if(locationHandler.IsReverse())
                {
                    locationHandler.BackMove();
                }
                else
                {
                    locationHandler.Move();
                }
            }//如果处于加速状态，就再走一格
            if(locationHandler.IsReverse())
            {
                locationHandler.TurnLeft();
            }
            else
            {
                locationHandler.TurnRight();
            }
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
    class ReverseCommand final
    {
    public:
        void operator()(LocationHandler& locationHandler) const noexcept
        {
            locationHandler.Reverse();
        };
    };
}