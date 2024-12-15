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
    /*
    for (const auto command : commands) {
        std::unique_ptr<ExecuteCommand> doCommandPtr;//定义父类指针，并使用智能指针
        switch (command) {
        case 'M':
        {
        //减小代码圈复杂度，有利于代码的维护
            doCommandPtr=std::make_unique<MoveCommand>();//父类指针指向子类对象
            break;
        }
        case 'L':
        {
            doCommandPtr=std::make_unique<TurnLeftCommand>();
            break;
        }
        case 'R':
        {
            doCommandPtr=std::make_unique<TurnRightCommand>();
            break;
        }
        case 'F':
        {
            doCommandPtr=std::make_unique<FastCommand>();
        }
        }
        if(doCommandPtr!=nullptr)
        {
            doCommandPtr->DoOperate(locationHandler);//指向哪个子类，就用哪个子类的方法
        }
    }
    */
   //表驱动消减圈复杂度
    static std::unordered_map<char, std::unique_ptr<ExecuteCommand>> commandMap;
    commandMap.emplace('M', std::make_unique<MoveCommand>());
    commandMap.emplace('L', std::make_unique<TurnLeftCommand>());
    commandMap.emplace('R', std::make_unique<TurnRightCommand>());
    commandMap.emplace('F', std::make_unique<FastCommand>());
    for (const auto command : commands) {
        auto it = commandMap.find(command);
        if (it != commandMap.end()) {
            it->second->DoOperate(locationHandler);
        }
    }
}
Location ExecutorImpl::GetInfo(void) const noexcept
{
    return locationHandler.GetInfo();
}
}
