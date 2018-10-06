#include "ratGame.cpp"
#include "gtest/gtest.h"

class ratGameTests : public::testing::Test{};

TEST_F(ratGameTests, singleRatTest)
{
    Game game;
    Rat singleRat(game);

    ASSERT_EQ(1, singleRat.attack);
}

TEST_F(ratGameTests, fourRatsTest)
{
    Game game;
    Rat rat1(game);
    Rat rat2(game);
    Rat rat3(game);
    Rat rat4(game);

    ASSERT_EQ(4, rat1.attack);
    ASSERT_EQ(4, rat2.attack);
    ASSERT_EQ(4, rat3.attack);
    ASSERT_EQ(4, rat4.attack);
    
}

TEST_F(ratGameTests, threeRateOneDies)
{
    Game game;
    
    Rat rat1(game);
    Rat rat2(game);

    {
        Rat rat3(game);
        ASSERT_EQ(3, rat1.attack);
        ASSERT_EQ(3, rat2.attack);
        ASSERT_EQ(3, rat3.attack);
    }

    ASSERT_EQ(2, rat1.attack);
    ASSERT_EQ(2, rat2.attack);
}

int main(int argc, char* argv[])
{
  //::testing::GTEST_FLAG(catch_exceptions) = false;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

