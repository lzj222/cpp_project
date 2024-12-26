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
            if(locationHandler.GetVehicleType()==VehicleType::SportsCar)
            {
                if(!locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.Move();
                    locationHandler.Move();
                }
                else if(locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.BackMove();
                    locationHandler.BackMove();
                }
                else if(!locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.Move();
                    locationHandler.Move();
                    locationHandler.Move();
                    locationHandler.Move();
                }
                else if(locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.BackMove();
                    locationHandler.BackMove();
                    locationHandler.BackMove();
                    locationHandler.BackMove();
                }
            }
            else if(locationHandler.GetVehicleType()==VehicleType::Bus)
            {
                if(!locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.Move();
                }
                else if(locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.BackMove();
                }
                else if(!locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.Move();
                    locationHandler.Move();
                }
                else if(locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.BackMove();
                    locationHandler.BackMove();
                }
            }
            //正常车辆
            else
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
            }
        };
    };
    class TurnLeftCommand final
    {
    public:
        void operator()(LocationHandler& locationHandler) const noexcept
        {
            if(locationHandler.GetVehicleType()==VehicleType::SportsCar)
            {
                if(!locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.TurnLeft();
                    locationHandler.Move();
                }
                else if(locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.TurnRight();
                    locationHandler.BackMove();
                }
                else if(!locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.Move();
                    locationHandler.TurnLeft();
                    locationHandler.Move();
                }
                else if(locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.BackMove();
                    locationHandler.TurnRight();
                    locationHandler.BackMove();
                }
            }
            else if(locationHandler.GetVehicleType()==VehicleType::Bus)
            {
                if(!locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.Move();
                    locationHandler.TurnLeft();
                }
                else if(locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.BackMove();
                    locationHandler.TurnRight();
                }
                else if(!locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.Move();
                    locationHandler.Move();
                    locationHandler.TurnLeft();
                }
                else if(locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.BackMove();
                    locationHandler.BackMove();
                    locationHandler.TurnRight();
                }
            }
            //正常车辆
            else
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
            }
        };
    };
    class TurnRightCommand final
    {
    public:
        void operator()(LocationHandler& locationHandler) const noexcept
        {
            if(locationHandler.GetVehicleType()==VehicleType::SportsCar)
            {
                if(!locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.TurnRight();
                    locationHandler.Move();
                }
                else if(locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.TurnLeft();
                    locationHandler.BackMove();
                }
                else if(!locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.Move();
                    locationHandler.TurnRight();
                    locationHandler.Move();
                }
                else if(locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.BackMove();
                    locationHandler.TurnLeft();
                    locationHandler.BackMove();
                }
            }
            else if(locationHandler.GetVehicleType()==VehicleType::Bus)
            {
                if(!locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.Move();
                    locationHandler.TurnRight();
                }
                else if(locationHandler.IsReverse()&&!locationHandler.IsFastMove())
                {
                    locationHandler.BackMove();
                    locationHandler.TurnLeft();
                }
                else if(!locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.Move();
                    locationHandler.Move();
                    locationHandler.TurnRight();
                }
                else if(locationHandler.IsReverse()&&locationHandler.IsFastMove())
                {
                    locationHandler.BackMove();
                    locationHandler.BackMove();
                    locationHandler.TurnLeft();
                }
            }
            else
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