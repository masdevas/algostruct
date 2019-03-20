#include <gtest/gtest.h>
#include "data_generation.h"
#include <search/binary.h>
#include <algorithm>

void TestLowerBound(const std::vector<int>& vector, int value) {
    auto it = algostruct::lower_bound(vector.begin(), vector.end(), value);
    auto required_it = std::find(vector.begin(), vector.end(), value);
    ASSERT_EQ(std::distance(vector.begin(), it), std::distance(vector.begin(), required_it));
}

void TestUpperBound(const std::vector<int>& vector, int value) {
    auto it = algostruct::upper_bound(vector.begin(), vector.end(), value);
    auto required_it = std::find(vector.rbegin(), vector.rend(), value);
    ASSERT_EQ(std::distance(vector.begin(), it), vector.size()
        - std::distance(vector.rbegin(), required_it));
}

TEST(TEST_BINARY, LOWER_BOUND) {
    std::vector<int> example_first{1, 1, 2, 2, 3, 3, 4};
    {
        int value = 1;
        TestLowerBound(example_first, value);
        TestUpperBound(example_first, value);
    }
    {
        int value = 2;
        TestLowerBound(example_first, value);
        TestUpperBound(example_first, value);
    }
    {
        int value = 3;
        TestLowerBound(example_first, value);
        TestUpperBound(example_first, value);
    }
    {
        int value = 4;
        TestLowerBound(example_first, value);
        TestUpperBound(example_first, value);
    }
}
