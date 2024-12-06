#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include"PoseEq.hpp"
namespace adas
{
// 重载==，便于后续测试（已放到PoseEq中）
// 测试
// 测试初始化
TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'E'}));  // 定义智能指针，唯一拥有所指对象
    const Location target({0, 0, 'E'});
    ASSERT_EQ(target, executor->GetInfo());
}

TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor());
    const Location target({0, 0, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
// 测试防护网：正交分解法

// 移动指令测试
TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'E'}));
    executor->DoCommand("M");
    const Location target({1, 0, 'E'});
    ASSERT_EQ(target, executor->GetInfo());
}
TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("M");
    const Location target({-1, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'N'}));
    executor->DoCommand("M");
    const Location target({0, 1, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'S'}));
    executor->DoCommand("M");
    const Location target({0, -1, 'S'});
    ASSERT_EQ(target, executor->GetInfo());
}

// 左转指令测试
TEST(ExecutorTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'E'}));
    executor->DoCommand("L");
    const Location target({0, 0, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'N'}));
    executor->DoCommand("L");
    const Location target({0, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
TEST(ExecutorTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("L");
    const Location target({0, 0, 'S'});
    ASSERT_EQ(target, executor->GetInfo());
}
TEST(ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'S'}));
    executor->DoCommand("L");
    const Location target({0, 0, 'E'});
    ASSERT_EQ(target, executor->GetInfo());
}

// 右转指令测试
TEST(ExecutorTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'E'}));
    executor->DoCommand("R");
    const Location target({0, 0, 'S'});
    ASSERT_EQ(target, executor->GetInfo());
}
TEST(ExecutorTest, should_return_facing_W_given_command_is_R_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'S'}));
    executor->DoCommand("R");
    const Location target({0, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
TEST(ExecutorTest, should_return_facing_N_given_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("R");
    const Location target({0, 0, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
TEST(ExecutorTest, should_return_facing_E_given_command_is_R_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'N'}));
    executor->DoCommand("R");
    const Location target({0, 0, 'E'});
    ASSERT_EQ(target, executor->GetInfo());
}

// 测试复杂指令
TEST(ExecutorTest, complex_command)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'E'}));
    executor->DoCommand("MRMMLLMR");
    const Location target({1, -1, 'E'});
    ASSERT_EQ(target, executor->GetInfo());
}
}  // namespace adas
