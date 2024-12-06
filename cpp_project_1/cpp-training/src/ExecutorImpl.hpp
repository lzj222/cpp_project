#pragma once

#include "Executor.hpp"
namespace adas
{
class ExecutorImpl final : public Executor  // ExecutorImpl不能再作为基类
{
private:
    Location location;
    //添加有关F指令接口
    bool isFastMove{false};//C++11新增的成员变量初始化方式,默认初始化为不加速
    void FastChange(void)noexcept;//改变加速状态
    bool IsFastMove(void)const noexcept;//判断是否处在加速状态
    class ExecuteCommand
    {
    public:
        ExecuteCommand()=default; // 默认构造函数，使用编译器生成的默认实现
        virtual ~ExecuteCommand()=default;
        virtual void DoOperate(ExecutorImpl&executor) const noexcept=0;

    };
    class MoveCommand final:public ExecuteCommand
    {
    public:
        void DoOperate(ExecutorImpl&executor) const noexcept override;//override,如果基类中没有对应的虚函数，或者签名不匹配，编译器会报错，这有助于避免因拼写错误或签名不一致而导致的难以发现的bug
    };
    class TurnLeftCommand final:public ExecuteCommand
    {
    public:
        void DoOperate(ExecutorImpl&executor) const noexcept override;
    };
    class TurnRightCommand final:public ExecuteCommand
    {
    public:
        void DoOperate(ExecutorImpl&executor) const noexcept override;
    };//建立指令的继承关系，便于实现多态
    class FastCommand final:public ExecuteCommand
    {
    public:
        void DoOperate(ExecutorImpl&executor) const noexcept override;
    };
public:
    // 构造函数和析构函数
    explicit ExecutorImpl(const Location& location) noexcept;  // 显式转换的单参数函数
    ExecutorImpl(const ExecutorImpl&) = delete;                // 不支持拷贝构造函数
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;     // 不支持重载赋值运算符
    ~ExecutorImpl() noexcept = default;                        // 用默认析构函数
    // 其他函数
    void DoCommand(const std::string& command) noexcept override;  // 重写了父类的函数
    void Move(void)noexcept;
    void TurnLeft(void)noexcept;
    void TurnRight(void)noexcept;
    Location GetInfo(void) const noexcept override;
};
}  // namespace adas