#include <gtest/gtest.h>
#include <algorithm>
#include "sort/count_sort.h"
#include "../support/data_generation.h"

TEST(TEST_COUNT_SORT, RANDOM_TEST) {
    size_t size = 1000000;
    using DataType = uint16_t;
    DataType lower_bound = 0, upper_bound = 10000;
    auto data = GenerateRandomVectorInt(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    CountSort(data.begin(), data.end(), UINT16_MAX);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}