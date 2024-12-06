#include <gtest/gtest.h>
#include "Executor.hpp"
#include"PoseEq.hpp"
namespace adas
{
//F状态的影响仅对M L R指令执行产生变化，和当前车辆朝向无关，正交分解只要对MLR和F进行测试即可,此时已经变为二维数据的正交分解测试
//FM测试
TEST(ExecutorFastTest,should_return_x_minus_2_given_status_is_fast_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("FM");
    const Location target({-2, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
//FL测试
TEST(ExecutorFastTest,should_return_S_and_x_minus_1_given_status_is_fast_command_is_L_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("FL");
    const Location target({-1, 0, 'S'});
    ASSERT_EQ(target, executor->GetInfo());
}
//FR测试
TEST(ExecutorFastTest,should_return_N_and_x_minus_1_given_status_is_fast_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'}));
    executor->DoCommand("FR");
    const Location target({-1, 0, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
//FFM测试
TEST(ExecutorFastTest,should_return_y_plus_1_given_command_is_FFM_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'N'}));
    executor->DoCommand("FFM");
    const Location target({0, 1, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
//FFL测试
TEST(ExecutorFastTest,should_return_W_and_y_plus_0_given_command_is_FFL_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'N'}));
    executor->DoCommand("FFL");
    const Location target({0, 0, 'W'});
    ASSERT_EQ(target, executor->GetInfo());
}
//FFR测试
TEST(ExecutorFastTest,should_return_E_and_y_plus_0_given_command_is_FFR_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'N'}));
    executor->DoCommand("FFR");
    const Location target({0, 0, 'E'});
    ASSERT_EQ(target, executor->GetInfo());
}
//一些复杂指令测试
TEST(ExecutorFastTest,complex_command)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'N'}));
    executor->DoCommand("FLFRFFM");
    const Location target({0, 2, 'N'});
    ASSERT_EQ(target, executor->GetInfo());
}
}   