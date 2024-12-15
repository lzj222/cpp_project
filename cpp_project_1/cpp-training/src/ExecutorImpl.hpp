#pragma once

#include "Executor.hpp"
#include"LocationHandler.hpp"
namespace adas
{
class ExecutorImpl final : public Executor  // ExecutorImpl不能再作为基类
{
private:
    LocationHandler locationHandler;
public:
    void Move(void)noexcept;
    void TurnLeft(void)noexcept;
    void TurnRight(void)noexcept;
    void FastChange(void)noexcept;//改变加速状态
    bool IsFastMove(void)const noexcept;//判断是否处在加速状态
    

public:
    // 构造函数和析构函数
    explicit ExecutorImpl(const Location& location) noexcept;  // 显式转换的单参数函数
    ExecutorImpl(const ExecutorImpl&) = delete;                // 不支持拷贝构造函数
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;     // 不支持重载赋值运算符
    ~ExecutorImpl() noexcept = default;                        // 用默认析构函数
    // 其他函数
    void DoCommand(const std::string& command) noexcept override;  // 重写了父类的函数
    Location GetInfo(void) const noexcept override;
};
}  // namespace adas