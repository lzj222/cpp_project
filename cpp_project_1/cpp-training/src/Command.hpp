#pragma once
#include"ExecutorImpl.hpp"
#include"LocationHandler.hpp"
#include<functional>
namespace adas
{

    class MoveCommand final
    {
    public:
    // 定义一个 std::function 类型的可调用对象 operate，接收一个 LocationHandler 的引用，返回类型为 void 
        const std::function<void(LocationHandler& locationHandler)> operate=[](LocationHandler& locationHandler) noexcept
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
        const std::function<void(LocationHandler& locationHandler)> operate=[](LocationHandler& locationHandler) noexcept
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
        const std::function<void(LocationHandler& locationHandler)> operate=[](LocationHandler& locationHandler) noexcept
        {
            if(locationHandler.IsFastMove())
            {
                locationHandler.Move();
            }//如果处于加速状态，就再走一格
            locationHandler.TurnRight();
        };
    };//建立指令的继承关系，便于实现多态
    class FastCommand final
    {
    public:
        const std::function<void(LocationHandler& locationHandler)> operate=[](LocationHandler& locationHandler) noexcept
        {
            locationHandler.FastChange();
        };
    };
}