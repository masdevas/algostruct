#include <gtest/gtest.h>
#include <algorithm>
#include "sort/insertion_sort.h"
#include "data_generation.h"

TEST(TEST_INSERTION_SORT, RANDOM_TEST) {
    size_t size = 100;
    using DataType = double;
    double lower_bound = 0, upper_bound = 10000;
    auto data = GenerateRandomVectorReal(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    InsertionSort(data.begin(), data.end(), comp);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}
