#include <iostream>
#include <string>
#include "realvector.h"
#include <gtest/gtest.h>

namespace
{
    TEST(RealVectorTest, DefaultConstructor) {
        RealVector<int> int_vec;

        EXPECT_EQ(0, int_vec.size());
        EXPECT_EQ(int_vec.kInitialSize, int_vec.capacity());
        EXPECT_TRUE(int_vec.empty());
    }

    TEST(RealVectorTest, ConstructorWithInitialValue) {
        int value = 9;
        int size = 6;
        RealVector<int> int_vec(size, value);
        
        EXPECT_EQ(size, int_vec.size());
        EXPECT_EQ(size * 2, int_vec.capacity());
        EXPECT_FALSE(int_vec.empty());
    }

    TEST(RealVectorTest, PushbackAndPopback) {
        int val = 3;
        RealVector<int> int_vec;

        int_vec.push_back(val);
        EXPECT_EQ(val, int_vec.back());
        EXPECT_EQ(val, int_vec.front());

        int_vec.pop_back();
        EXPECT_TRUE(int_vec.empty());
    }

    TEST(RealVectorTest, InsertAndErase) {
        int val = 3;
        RealVector<int> int_vec;

        // basic insert
        int_vec.insert(int_vec.begin(), val);
        EXPECT_EQ(val, int_vec.back());
        EXPECT_EQ(val, int_vec.front());

        // basic erase
        int_vec.erase(int_vec.begin());
        EXPECT_TRUE(int_vec.empty());

        // insert a group
        RealVector<int>::value_type count = 6;
        int_vec.insert(int_vec.begin(), count, val);
        for (int i = 0; i < count; i++) {
            EXPECT_EQ(int_vec.at(i), val);
        }
        EXPECT_EQ(int_vec.size(), count);
        EXPECT_EQ(int_vec.capacity(), 8);

        // erase a range
        int_vec.erase(int_vec.begin(), int_vec.end());
        EXPECT_TRUE(int_vec.empty());

        // margin test
        int_vec.erase(int_vec.begin());
        EXPECT_TRUE(int_vec.empty());

        int_vec.erase(int_vec.end());
        EXPECT_TRUE(int_vec.empty());

        int_vec.erase(int_vec.begin(), int_vec.end());
        EXPECT_TRUE(int_vec.empty());
    }

    TEST(RealVectorTest, RvalueTest) {
        RealVector<int> int_vec;
        RealVector<int>::value_type val = 3;

        // test rvalue
        int_vec.push_back(1);
        int_vec.insert(int_vec.begin(), 2);

        // test normal
        int_vec.insert(int_vec.end(), val);
        int_vec.insert(int_vec.begin(), 3, val);

        EXPECT_EQ(val, int_vec.back());
        EXPECT_EQ(val, int_vec.front());
        EXPECT_EQ(val, int_vec[1]);
        EXPECT_EQ(val, int_vec.at(2));
    }
}

int main() 
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}