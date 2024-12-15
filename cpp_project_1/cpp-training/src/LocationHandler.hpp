#pragma once
#include"Executor.hpp"
namespace adas
{
    //解耦循环依赖，封装抽离ExecutorImpl状态数据
class LocationHandler final
{
private:
    Location location;
    bool isFastMove{false};//C++11新增的成员变量初始化方式,默认初始化为不加速
public:
//对象构造与析构相关
    LocationHandler(const Location& location) noexcept;  // 显式转换的单参数函数
    LocationHandler(const LocationHandler&) = delete;                // 不支持拷贝构造函数
    LocationHandler& operator=(const LocationHandler&) = delete;     // 不支持重载赋值运算符
    ~LocationHandler() noexcept = default;                        // 用默认析构函数
public:
    //其他成员函数
    void Move(void)noexcept;
    void TurnLeft(void)noexcept;
    void TurnRight(void)noexcept;
    void FastChange(void)noexcept;//改变加速状态
    bool IsFastMove(void)const noexcept;//判断是否处在加速状态
    Location GetInfo(void) const noexcept;
};
}