#include <gtest/gtest.h>

#include <stdlib.h> // WIFEXITED, et
#include <sys/wait.h> // waitpid

#include "example.h"

class ForkingTest : public testing::Test {
public:
     ForkingTest() {
        m_pid = fork();
    }

    ~ForkingTest() {
        if (isChild()) {
            exit(testing::Test::HasFailure());
        } else {
            EXPECT_EQ(waitForChildFork(), 0);
        }
    }

    bool isChild() { return m_pid == 0; }
    bool isParent() { return m_pid != 0; }

    int  waitForChildFork()
    {
        int status;
        if ( 0 > waitpid( m_pid, &status, 0 ) ) {
            std::cerr << "[----------]  Waitpid error!" << std::endl;
            return (-1);
        }
        if ( WIFEXITED(status) ) {
            const int exit_status = WEXITSTATUS(status);
            if ( exit_status != 0 ) {
                std::cerr << "[----------]  Non-zero exit status " << exit_status << " from test!" << std::endl;
            }
            return exit_status;
        } else {
            std::cerr << "[----------]  Non-normal exit from child!" << std::endl;
            return (-2);
        }
    }

    Example example; 
    int m_pid = 0;
};

TEST_F(ForkingTest, add)
{
    if (isParent()) return; // only children test

    double res;
    res = example.add_numbers(1.0, 2.0);
    EXPECT_NEAR(res, 3.0, 1.0e-11);
}

TEST_F(ForkingTest, subtract)
{
    if (isParent()) return; // only children test

    double res;
    res = example.subtract_numbers(1.0, 2.0);
    EXPECT_NEAR(res, -1.0, 1.0e-11);
}

TEST_F(ForkingTest, multiply_with_zero)
{
    if (isParent()) return; // only children test

    EXPECT_EXIT(example.multiply_numbers(2.0, 0.0), testing::ExitedWithCode(1),"");
}

TEST_F(ForkingTest, multiply)
{
    if (isParent()) return; // only children test

    double res;
    res = example.multiply_numbers(2.0, 4.0);
    EXPECT_NEAR(res, 8.0, 1.0e-11);
}

TEST_F(ForkingTest, divide_by_zero)
{
    if (isParent()) return; // only children test

    EXPECT_DEATH(example.divide_numbers(2.0, 0.0), "");
}

TEST_F(ForkingTest, divide)
{
    if (isParent()) return; // only children test

    double res;
    res = example.divide_numbers(2.0, 4.0);
    EXPECT_NEAR(res, 0.5, 1.0e-11);
}
