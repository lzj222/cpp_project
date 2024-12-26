#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include"PoseEq.hpp"
namespace adas
{
//正常状态测试
//M测试
TEST(ExecutorBusTest,should_return_x_minus_1_given_status_is_nomal_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("M");
    const Location target({-1, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
//L测试
TEST(ExecutorBusTest,should_return_heading_S_and_x_minus_1_given_status_is_nomal_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("L");
    const Location target({-1, 0, 'S'});
    ASSERT_EQ(target, executor->GetInfo());
}
//R测试
TEST(ExecutorBusTest,should_return_heading_N_and_x_minus_1_given_status_is_normal_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("R");
    const Location target({-1, 0, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
////////////////////////////////////////////////////////////////
//B状态下测试
//M测试
TEST(ExecutorBusTest,should_return_x_plus_1_given_status_is_back_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("BM");
    const Location target({1, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
//L测试
TEST(ExecutorBusTest,should_return_heading_N_and_x_plus_1_given_status_is_back_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("BL");
    const Location target({1, 0, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
//R测试
TEST(ExecutorBusTest,should_return_heading_S_and_x_plus_1_given_status_is_back_and_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("BR");
    const Location target({1, 0, 'S'});
    ASSERT_EQ(target, executor->GetInfo());
}
/////////////////////////////////////////////////////
//F状态下进行测试
//M测试
TEST(ExecutorBusTest,should_return_x_minus_2_given_status_is_fast_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("FM");
    const Location target({-2, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
//L测试
TEST(ExecutorBusTest,should_return_heading_S_and_x_minus_2_given_status_is_fast_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("FL");
    const Location target({-2, 0, 'S'});
    ASSERT_EQ(target, executor->GetInfo());
}
//R测试
TEST(ExecutorBusTest,should_return_heading_N_and_x_minus_2_given_status_is_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("FR");
    const Location target({-2, 0, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
///////////////////////////////////////////////////////
//BF状态下进行测试
//M测试
TEST(ExecutorBusTest,should_return_x_plus_2_given_status_is_back_and_fast_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("BFM");
    const Location target({2, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
//L测试
TEST(ExecutorBusTest,should_return_heading_N_and_x_plus_2_given_status_is_back_and_fast_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("BFL");
    const Location target({2, 0, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
//R测试
TEST(ExecutorBusTest,should_return_heading_S_and_x_plus_2_given_status_is_back_and_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    executor->DoCommand("BFR");
    const Location target({2, 0, 'S'});
    ASSERT_EQ(target, executor->GetInfo());
}
}