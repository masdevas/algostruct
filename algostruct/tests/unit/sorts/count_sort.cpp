#include <gtest/gtest.h>
#include <algorithm>
#include "sorts/count_sort.h"
#include "data_generation.h"

TEST(TEST_COUNT_SORT, RANDOM_TEST) {
    size_t size = 1000000;
    uint32_t lower_bound = 0, upper_bound = UINT32_MAX / 10;
    auto data = GenerateRandomVectorInt<uint32_t>(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    CountSort(data.begin(), data.end(), UINT32_MAX);
    //std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    //EXPECT_EQ(data, copy_of_data);
}