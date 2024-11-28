#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
namespace adas  // 有利于防止命名冲突
{
struct Location {
    int x;
    int y;         // 车的位置
    char heading;  // 车的朝向
};
// 实现数字与字母方向的转化，便于取模运算
char ToInt(char c);
char FromInt(int i);
// 将Executor定义为抽象类，只提供接口
class Executor
{
public:
    // 有关构造与析构的函数
    static Executor* CreateExecutor(const Location& location = {0, 0, 'N'}) noexcept;  // 不用实例化，所有子类都能用
    Executor(void) = default;                                                          // 用默认的构造函数
    Executor(const Executor&) = delete;                                                // 不能进行拷贝构造
    virtual ~Executor(void) = default;  // 使得用基类的指针或者引用析构派生类的时候能调用派生类的析构函数
    Executor& operator=(const Executor&) = delete;  // 不能重载等号运算符赋值对象
    // 有关具体功能的函数接口
    virtual void DoCommand(const std::string& command) noexcept = 0;  // 提供执行命令的接口，不会抛异常
    virtual Location GetInfo(void) const noexcept = 0;  // 提供查询接口，为常函数，且不会抛异常
};
}
