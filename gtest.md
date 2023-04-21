# gtest

In UCB CS61B, test is introduced for efficient development and deployment. May be I can use `gtest` here for practice, complementing coding in this exercise.

## Configuration

The latest version is 1.13.0 available at [gtest](https://github.com/google/googletest), which requires at least C++14. It's fine we use the standard C++17. Download this version source code [here](https://github.com/google/googletest/archive/refs/tags/v1.13.0.tar.gz).

- You can install `gtest` follow these commands.

```bash
tar -xvf v1.13.0.tar.gz
cd googletest-1.13.0
mkdir build && cd build && cmake ..
make -j$(nproc)
sudo make install
```

- Afterwards, switch to folder `googletest/samples`. We can use the `gtest` provided samples to test itself.

```bash
cd googletest/samples
g++ ../src/gtest_main.cc sample1.cc sample1_unittest.cc -o test -lgtest -lgmock -lpthread -std=c++17
```

You will get the output that tells you everything is fine.

```bash
Running main() from ../src/gtest_main.cc
[==========] Running 6 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 3 tests from FactorialTest
[ RUN      ] FactorialTest.Negative
[       OK ] FactorialTest.Negative (0 ms)
[ RUN      ] FactorialTest.Zero
[       OK ] FactorialTest.Zero (0 ms)
[ RUN      ] FactorialTest.Positive
[       OK ] FactorialTest.Positive (0 ms)
[----------] 3 tests from FactorialTest (0 ms total)

[----------] 3 tests from IsPrimeTest
[ RUN      ] IsPrimeTest.Negative
[       OK ] IsPrimeTest.Negative (0 ms)
[ RUN      ] IsPrimeTest.Trivial
[       OK ] IsPrimeTest.Trivial (0 ms)
[ RUN      ] IsPrimeTest.Positive
[       OK ] IsPrimeTest.Positive (0 ms)
[----------] 3 tests from IsPrimeTest (0 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 2 test suites ran. (0 ms total)
[  PASSED  ] 6 tests.
```
