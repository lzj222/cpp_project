#pragma once
#include"ExecutorImpl.hpp"
#include"LocationHandler.hpp"
namespace adas
{
    class ExecuteCommand
    {
    public:
        ExecuteCommand()=default; // 默认构造函数，使用编译器生成的默认实现
        virtual ~ExecuteCommand()=default;
        virtual void DoOperate(LocationHandler& locationHandler) const noexcept=0;

    };
    class MoveCommand final:public ExecuteCommand
    {
    public:
        void DoOperate(LocationHandler& locationHandler) const noexcept override//override,如果基类中没有对应的虚函数，或者签名不匹配，编译器会报错，这有助于避免因拼写错误或签名不一致而导致的难以发现的bug
        {
            if(locationHandler.IsFastMove())
            {
                locationHandler.Move();
            }//如果处于加速状态，就再走一格
            locationHandler.Move();
        }
    };
    class TurnLeftCommand final:public ExecuteCommand
    {
    public:
        void DoOperate(LocationHandler& locationHandler) const noexcept override
        {
            if(locationHandler.IsFastMove())
            {
                locationHandler.Move();
            }//如果处于加速状态，就再走一格
            locationHandler.TurnLeft();
        }
    };
    class TurnRightCommand final:public ExecuteCommand
    {
    public:
        void DoOperate(LocationHandler& locationHandler) const noexcept override
        {
            if(locationHandler.IsFastMove())
            {
                locationHandler.Move();
            }//如果处于加速状态，就再走一格
            locationHandler.TurnRight();
        }
    };//建立指令的继承关系，便于实现多态
    class FastCommand final:public ExecuteCommand
    {
    public:
        void DoOperate(LocationHandler& locationHandler) const noexcept override
        {
            locationHandler.FastChange();
        }
    };
}