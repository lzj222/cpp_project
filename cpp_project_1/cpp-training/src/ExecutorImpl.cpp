#include "ExecutorImpl.hpp"
#include"Command.hpp"
#include<memory>
#include<unordered_map>
namespace adas
{
// 抽象类的初始化函数
Executor* Executor::CreateExecutor(const Location& location) noexcept
{
    return new (std::nothrow) ExecutorImpl(location);  // 不会抛异常的new
}
ExecutorImpl::ExecutorImpl(const Location& location) noexcept : locationHandler(location)
{
}
void ExecutorImpl::DoCommand(const std::string& commands) noexcept
{
   //表驱动消减圈复杂度
    static std::unordered_map<char, std::function<void(LocationHandler& locationHandler)>> commandMap;
    commandMap.emplace('M', MoveCommand());
    commandMap.emplace('L', TurnLeftCommand());
    commandMap.emplace('R', TurnRightCommand());
    commandMap.emplace('F', FastCommand());
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
}
