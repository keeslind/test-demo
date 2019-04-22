[![Build Status](https://travis-ci.org/bast/gtest-demo.svg?branch=master)](https://travis-ci.org/bast/gtest-demo/builds)
[![Coverage Status](https://coveralls.io/repos/bast/gtest-demo/badge.png?branch=master)](https://coveralls.io/r/bast/gtest-demo?branch=master)
[![License](https://img.shields.io/badge/license-%20BSD--3-blue.svg)](../master/LICENSE)


# gtest-demo

C/C++ unit test demo using [Google Test](https://code.google.com/p/googletest) deployed to
[Travis-CI](https://travis-ci.org/bast/gtest-demo/builds) with test coverage
deployed to [Coveralls](https://coveralls.io/r/bast/gtest-demo).

- [Build and test history](https://travis-ci.org/bast/gtest-demo/builds)
- [Code coverage](https://coveralls.io/r/bast/gtest-demo)
- Licensed under [BSD-3](../master/LICENSE)

This demo uses the approach presented by Craig Scott in https://crascit.com/2015/07/25/cmake-gtest/.


## How to build this demo

```bash
git clone https://github.com/bast/gtest-demo.git
cd gtest-demo
mkdir target
cd target
cmake ..
cmake --build .
```


## Running the tests

Either using `ctest`:
```
$ ctest

Running tests...
Test project /home/user/gtest-demo/build
    Start 1: unit
1/1 Test #1: unit .............................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec
```

Or directly using `unit_tests`:
```
$ ./bin/unit_tests
[==========] Running 12 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 6 tests from ExampleTest
[ RUN      ] ExampleTest.add
[       OK ] ExampleTest.add (1 ms)
[ RUN      ] ExampleTest.subtract
[       OK ] ExampleTest.subtract (0 ms)
[ RUN      ] ExampleTest.multiply_with_zero
[       OK ] ExampleTest.multiply_with_zero (4 ms)
[ RUN      ] ExampleTest.multiply
[       OK ] ExampleTest.multiply (0 ms)
[ RUN      ] ExampleTest.devide_by_zero
[       OK ] ExampleTest.devide_by_zero (136 ms)
[ RUN      ] ExampleTest.divide
[       OK ] ExampleTest.divide (0 ms)
[----------] 6 tests from ExampleTest (142 ms total)

[----------] 6 tests from ForkingTest
[ RUN      ] ForkingTest.add
[       OK ] ForkingTest.add (4 ms)
[ RUN      ] ForkingTest.subtract
[       OK ] ForkingTest.subtract (3 ms)
[ RUN      ] ForkingTest.multiply_with_zero
[       OK ] ForkingTest.multiply_with_zero (9 ms)
[ RUN      ] ForkingTest.multiply
[       OK ] ForkingTest.multiply (3 ms)
[ RUN      ] ForkingTest.divide_by_zero
[       OK ] ForkingTest.divide_by_zero (176 ms)
[ RUN      ] ForkingTest.divide
[       OK ] ForkingTest.divide (3 ms)
[----------] 6 tests from ForkingTest (199 ms total)

[----------] Global test environment tear-down
[==========] 12 tests from 2 test cases ran. (341 ms total)
[  PASSED  ] 12 tests.
```

## Modifications

I Have modified the original test to use the fork as proposed by
[Daniel Goldfarb](https://github.com/DanielGoldfarb).
And added some testcases with some peculiar results to test the fork:
- It will now check for the programmed abort() when trying to do a divide by zero.
- It will also check for exit(1) if the result of a multiply results in 0.0. 

The test will run fine when run as `unit_tests --gtest_death_test_style=fast` but will fail 
with `unit_tests --gtest_death_test_style=threadsafe` :-(. I am still trying to figure out why...

## Acknowledgments

- Container Travis setup thanks to [Joan Massich](https://github.com/massich).
- Clean-up in CMake code thanks to [Claus Klein](https://github.com/ClausKlein).


## References

- https://crascit.com/2015/07/25/cmake-gtest/
