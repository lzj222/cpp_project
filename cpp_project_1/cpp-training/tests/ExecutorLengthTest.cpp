#include <gtest/gtest.h>
#include "Executor.hpp"
#include"PoseEq.hpp"
namespace adas
{
TEST(ExecutorLengthTest,should_return_1_given_status_is_Common)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Common));
    const int target=1;
    ASSERT_EQ(target, executor->GetVehicleLength());
}
TEST(ExecutorLengthTest,should_return_1_given_status_is_SportsCar)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::SportsCar));
    const int target=1;
    ASSERT_EQ(target, executor->GetVehicleLength());
}
TEST(ExecutorLengthTest,should_return_2_given_status_is_Bus)
{
    std::unique_ptr<Executor> executor(Executor::CreateExecutor({0, 0, 'W'},VehicleType::Bus));
    const int target=2;
    ASSERT_EQ(target, executor->GetVehicleLength());
}
}