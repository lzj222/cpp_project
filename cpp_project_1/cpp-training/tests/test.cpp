#include <gtest/gtest.h>

#include "executor.h"
class ExecutorTest : public ::testing::Test
{
protected:
    Executor car;  // 被测试的Executor对象
    void SetUp() override
    {
        car = Executor();  // 初始化
    }
};
// 测试初始化
TEST_F(ExecutorTest, Initialization)  // 在运行测试用例时，知道是将这个测试用例和ExecutorTest类关联起来
{
    auto loc = car.GetInfo();
    EXPECT_EQ(loc.first.first, 0);
    EXPECT_EQ(loc.first.second, 0);
    EXPECT_EQ(loc.second, 'N');
}
// 测试前进指令
TEST_F(ExecutorTest, MoveForward)
{
    car.DoCommand("M");
    auto loc = car.GetInfo();
    EXPECT_EQ(loc.first.first, 0);   // x应该仍为0
    EXPECT_EQ(loc.first.second, 1);  // y应该增加到1
    EXPECT_EQ(loc.second, 'N');      // 方向应该仍然是N
}

// 测试左转指令
TEST_F(ExecutorTest, TurnLeft)
{
    car.DoCommand("L");
    auto loc = car.GetInfo();
    EXPECT_EQ(loc.first.first, 0);   // x应该为0
    EXPECT_EQ(loc.first.second, 0);  // y应该为0
    EXPECT_EQ(loc.second, 'W');      // 方向应变为W
}

// 测试右转指令
TEST_F(ExecutorTest, TurnRight)
{
    car.DoCommand("R");
    auto loc = car.GetInfo();
    EXPECT_EQ(loc.first.first, 0);   // x应该为0
    EXPECT_EQ(loc.first.second, 0);  // y应该为0
    EXPECT_EQ(loc.second, 'E');      // 方向应变为E
}

// 测试组合指令
TEST_F(ExecutorTest, CombinedCommands)
{
    car.DoCommand("MMM");
    car.DoCommand("L");
    car.DoCommand("M");
    car.DoCommand("R");
    car.DoCommand("M");
    auto loc = car.GetInfo();
    EXPECT_EQ(loc.first.first, -1);  // x应变为-1
    EXPECT_EQ(loc.first.second, 4);  // y应该变为4
    EXPECT_EQ(loc.second, 'N');      // 方向应该为N
}
// 测试查询接口，顺便再测试一组组合指令
TEST_F(ExecutorTest, Query)
{
    car.DoCommand("MRMMLLLM");
    auto loc = car.GetInfo();
    EXPECT_EQ(loc.first.first, 2);   // x应变为2
    EXPECT_EQ(loc.first.second, 0);  // y应该变为0
    EXPECT_EQ(loc.second, 'S');      // 方向应该为S
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}