#include "ExecutorImpl.hpp"
#include"Command.hpp"
#include<memory>
#include<unordered_map>
namespace adas
{
// 定义 VehicleLength 数组
int VehicleLength[3] = {1, 1, 2};  // 车的长度
// 抽象类的初始化函数
Executor* Executor::CreateExecutor(const Location& location,VehicleType type,int length) noexcept
{
    if(type==VehicleType::Common) length=VehicleLength[0];
    if(type==VehicleType::SportsCar) length=VehicleLength[1];
    if(type==VehicleType::Bus) length=VehicleLength[2];
    return new (std::nothrow) ExecutorImpl(location,type,length);  // 不会抛异常的new
}
ExecutorImpl::ExecutorImpl(const Location& location,VehicleType type,int length) noexcept 
: locationHandler(location,type),
  vehicleType(type),
  vehicleLength(length)
{
}
void ExecutorImpl::DoCommand(const std::string& commands) noexcept
{
   //表驱动消减圈复杂度
   //初始化语义应用
    const std::unordered_map<char, std::function<void(LocationHandler& locationHandler)>> commandMap{
        {'M', MoveCommand()},
        {'L', TurnLeftCommand()},
        {'R', TurnRightCommand()},
        {'F', FastCommand()},
        {'B', ReverseCommand()}
    };
    for (const auto command : commands) {
        const auto it = commandMap.find(command);
        if (it != commandMap.end()) {
            it->second(locationHandler);
        }
    }
}
Location ExecutorImpl::GetInfo(void) const noexcept
{
    return locationHandler.GetInfo();
}
int ExecutorImpl::GetVehicleLength(void)const noexcept
{
    return vehicleLength;
}
}
