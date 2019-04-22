#include "gtest/gtest.h"

int main(int argc, char** argv)
{
    ::testing::FLAGS_gtest_death_test_style = "threadsafe";   // this doesn't work
//    ::testing::FLAGS_gtest_death_test_style = "fast";         // this does
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
