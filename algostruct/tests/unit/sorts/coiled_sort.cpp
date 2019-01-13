#include <gtest/gtest.h>
#include <algorithm>
#include "sorts/coiled_sort.h"
#include "../data_generation/data_generation.h"

TEST(TEST_COILED_SORT, RANDOM_TEST) {
    size_t size = 1000000;
    uint32_t lower_bound = 0, upper_bound = UINT32_MAX;
    auto data = GenerateRandomVectorInt(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    CoiledCountSort(data.begin(), data.end(), 10000);
    //std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    //EXPECT_EQ(data, copy_of_data);
}
