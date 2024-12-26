#pragma once

#include "Executor.hpp"
#include"LocationHandler.hpp"
namespace adas
{
class ExecutorImpl final : public Executor  // ExecutorImpl不能再作为基类
{
private:
    LocationHandler locationHandler;
    VehicleType vehicleType;
    int vehicleLength;
public:
    // 构造函数和析构函数
    explicit ExecutorImpl(const Location& location,VehicleType type,int length) noexcept; 
    ExecutorImpl(const ExecutorImpl&) = delete;                // 不支持拷贝构造函数
    ExecutorImpl& operator=(const ExecutorImpl&) = delete;     // 不支持重载赋值运算符
    ~ExecutorImpl() noexcept = default;                        // 用默认析构函数
    // 其他函数
    void DoCommand(const std::string& command) noexcept override;  // 重写了父类的函数
    Location GetInfo(void) const noexcept override;
    int GetVehicleLength(void)const noexcept override;
};
}  // namespace adas