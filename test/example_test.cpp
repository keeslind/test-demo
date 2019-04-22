#include <gtest/gtest.h>
#include "example.h"

class ExampleTest : public testing::Test {
public:
    void SetUp() override {
    }
    void TearDown() override {
        Example::res = 0.0;
    }
    bool isParent() { return false; }

    Example example;
};

TEST_F(ExampleTest, add)
{
    if (isParent()) return; // only children test

    double res;
    res = example.add_numbers(1.0, 2.0);
    EXPECT_NEAR(res, 3.0, 1.0e-11);
}

TEST_F(ExampleTest, subtract)
{
    if (isParent()) return; // only children test

    double res;
    res = example.subtract_numbers(1.0, 2.0);
    EXPECT_NEAR(res, -1.0, 1.0e-11);
}

TEST_F(ExampleTest, multiply_with_zero)
{
    if (isParent()) return; // only children test

    EXPECT_EXIT(example.multiply_numbers(2.0, 0.0), testing::ExitedWithCode(1),"");
}

TEST_F(ExampleTest, multiply)
{
    if (isParent()) return; // only children test

    double res;
    res = example.multiply_numbers(2.0, 4.0);
    EXPECT_NEAR(res, 8.0, 1.0e-11);
}

TEST_F(ExampleTest, devide_by_zero)
{
    if (isParent()) return; // only children test

    EXPECT_DEATH(example.divide_numbers(2.0, 0.0), "");
}

TEST_F(ExampleTest, divide)
{
    if (isParent()) return; // only children test

    double res;
    res = example.divide_numbers(2.0, 4.0);
    EXPECT_NEAR(res, 0.5, 1.0e-11);
}
