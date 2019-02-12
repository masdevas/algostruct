#include <gtest/gtest.h>
#include <algorithm>
#include "sorts/bucket_sort.h"
#include "../support/data_generation.h"

TEST(TEST_BUCKET_SORT, RANDOM_TEST) {
    size_t size = 1000;
    using DataType = float;
    DataType lower_bound = 0;
    DataType upper_bound = 1000;
    auto data = GenerateRandomVectorReal(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    BucketSort(data.begin(), data.end(), lower_bound, upper_bound, comp);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}