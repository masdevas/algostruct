#include <gtest/gtest.h>
#include <algorithm>
#include "sort/bubble_sort.h"
#include "data_generation.h"

TEST(TEST_BUBBLE_SORT, RANDOM_TEST) {
    size_t size = 1000;
    using DataType = float;
    DataType lower_bound = 0;
    DataType upper_bound = 1000;
    auto data = GenerateRandomVectorReal(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    BubbleSort(data.begin(), data.end(), comp);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}
