//
// Created by ravas on 2022. 05. 26..
//

#include <gtest/gtest.h>
#include "../Direction.h"
#include "../Direction.cpp"

class DirectionTest : ::testing::Test{

};

/*Right Turn*/
TEST(DirectionTest, RightTurn_UpIncrementedTurnsRight)
{
    Direction d = Direction::UP;
    ++d;
    ASSERT_EQ(d,Direction::RIGHT);
}

TEST(DirectionTest, RightTurn_RightIncrementedTurnsDown)
{
    Direction d = Direction::RIGHT;
    ++d;
    ASSERT_EQ(d,Direction::DOWN);
}

TEST(DirectionTest, RightTurn_DownIncrementedTurnsLeft)
{
    Direction d = Direction::DOWN;
    ++d;
    ASSERT_EQ(d, Direction::LEFT);
}

TEST(DirectionTest, RightTurn_LeftIncrementedTurnsUp)
{
    Direction d = Direction::LEFT;
    ++d;
    ASSERT_EQ(d, Direction::UP);
}

/*LEFT_TURN*/
TEST(DirectionTest, LeftTurn_UpDecrementedTurnsLeft)
{
    Direction d = Direction::UP;
    --d;
    ASSERT_EQ(d, Direction::LEFT);
}

TEST(DirectionTest, LeftTurn_LeftDecrementedTurnsDown)
{
    Direction d = Direction::LEFT;
    --d;
    ASSERT_EQ(d,Direction::DOWN);
}

TEST(DirectionTest, LeftTurn_DownDecrementedTurnsRight)
{
    Direction d = Direction::DOWN;
    --d;
    ASSERT_EQ(d,Direction::RIGHT);
}

TEST(DirectionTest, LeftTurn_RightDecrementedTurnsUp)
{
    Direction d = Direction::RIGHT;
    --d;
    ASSERT_EQ(d, Direction::UP);
}