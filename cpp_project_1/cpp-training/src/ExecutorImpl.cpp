#include "ExecutorImpl.hpp"
#include<memory>
namespace adas
{
char ToInt(char c)
{
    std::unordered_map<char, int> dirMap = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
    return dirMap[c];
}
char FromInt(int i)
{
    std::unordered_map<int, char> dirMap = {{0, 'N'}, {1, 'E'}, {2, 'S'}, {3, 'W'}};
    return dirMap[i];
}
// 抽象类的初始化函数
Executor* Executor::CreateExecutor(const Location& location) noexcept
{
    return new (std::nothrow) ExecutorImpl(location);  // 不会抛异常的new
}
ExecutorImpl::ExecutorImpl(const Location& location) noexcept : location(location)
{
}
void ExecutorImpl::DoCommand(const std::string& commands) noexcept
{
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
            doCommandPtr->DoOperate(*this);//指向哪个子类，就用哪个子类的方法
        }
    }
}
void ExecutorImpl::Move(void)noexcept
{
    switch (location.heading) 
    {
        case 'N':
            location.y++;
            break;
        case 'S':
            location.y--;
            break;
        case 'E':
            location.x++;
            break;
        case 'W':
            location.x--;
            break;
    }
}
void ExecutorImpl::TurnLeft(void)noexcept
{
    int dirIndex = ToInt(location.heading);  // 获得当前朝向的数字索引
    dirIndex = (dirIndex + 3) % 4;  // 用取模运算实现转向
    location.heading = FromInt(dirIndex);
}
void ExecutorImpl::TurnRight(void)noexcept
{
    int dirIndex = ToInt(location.heading);  // 获得当前朝向的数字索引
    dirIndex = (dirIndex + 1) % 4;
    location.heading = FromInt(dirIndex);
}
Location ExecutorImpl::GetInfo(void) const noexcept
{
    return location;
}
void ExecutorImpl::MoveCommand::DoOperate(ExecutorImpl&executor) const noexcept
{
    if(executor.IsFastMove())
    {
        executor.Move();
    }//如果处于加速状态，就再走一格
    executor.Move();
}
void ExecutorImpl::TurnLeftCommand::DoOperate(ExecutorImpl&executor) const noexcept
{
    if(executor.IsFastMove())
    {
        executor.Move();
    }//如果处于加速状态，就再走一格
    executor.TurnLeft();
}
void ExecutorImpl::TurnRightCommand::DoOperate(ExecutorImpl&executor) const noexcept
{
    if(executor.IsFastMove())
    {
        executor.Move();
    }//如果处于加速状态，就再走一格
    executor.TurnRight();
}
void ExecutorImpl::FastCommand::DoOperate(ExecutorImpl&executor) const noexcept
{
    executor.FastChange();
}
void ExecutorImpl::FastChange(void)noexcept
{
    isFastMove=!isFastMove;
}
bool ExecutorImpl::IsFastMove(void)const noexcept
{
    return isFastMove;
}
}
