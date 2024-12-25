#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include"PoseEq.hpp"
namespace adas
{
//BM测试
TEST(ExecutorBackTest,should_return_x_plus_1_given_status_is_back_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("BM");
    const Location target({1, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
//BL测试
TEST(ExecutorBackTest,should_return_heading_N_given_status_is_back_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("BL");
    const Location target({0, 0, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
//BR测试
TEST(ExecutorBackTest,should_return_heading_S_given_status_is_back_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("BR");
    const Location target({0, 0, 'S'});
    ASSERT_EQ(target, executor->GetInfo());
}
//BFM测试
TEST(ExecutorBackTest,should_return_x_plus_2_given_status_is_back_and_fast_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("BFM");
    const Location target({2, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
//BFL测试
TEST(ExecutorBackTest,should_return_heading_N_and_x_plus_1_given_status_is_back_and_fast_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("BFL");
    const Location target({1, 0, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
//BFR测试
TEST(ExecutorBackTest,should_return_heading_S_and_x_plus_1_given_status_is_back_and_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("BFR");
    const Location target({1, 0, 'S'});
    ASSERT_EQ(target, executor->GetInfo());
}
//BBM测试
TEST(ExecutorBackTest,should_return_y_plus_1_given_status_is_back_and_back_command_is_M_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'N'}));
    executor->DoCommand("BBM");
    const Location target({0, 1, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
//BBL测试
TEST(ExecutorBackTest,should_return_heading_W_given_status_is_back_and_back_command_is_L_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'N'}));
    executor->DoCommand("BBL");
    const Location target({0, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
//BBR测试
TEST(ExecutorBackTest,should_return_heading_E_given_status_is_back_and_back_command_is_R_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'N'}));
    executor->DoCommand("BBR");
    const Location target({0, 0, 'E'});
    ASSERT_EQ(target, executor->GetInfo());
}
}