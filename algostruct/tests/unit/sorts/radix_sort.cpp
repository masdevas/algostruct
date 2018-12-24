#include <gtest/gtest.h>
#include <algorithm>
#include <climits>
#include "sorts/radix_sort.h"
#include "data_generation.h"

TEST(TEST_RADIX_SORT, RANDOM_TEST) {
    size_t size = 1000;
    using LocalDataType = uint16_t;
    size_t max_value = UINT16_MAX;
    using DataType = uint64_t;
    DataType lower_bound = 0, upper_bound = UINT64_MAX;
    auto data = GenerateRandomVector(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    auto extractor = [](const DataType& data, size_t index_digit) -> LocalDataType {
        DataType mask = static_cast<DataType>(~0) >> ((sizeof(DataType) - sizeof(LocalDataType)) * 8);
        return static_cast<LocalDataType>((data & (mask << 8 * sizeof(LocalDataType) * index_digit)) >> 8 * sizeof(LocalDataType) * index_digit);
    };
    RadixSort(data.begin(), data.end(), sizeof(DataType) / sizeof(LocalDataType), max_value, extractor);
    //std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    //EXPECT_EQ(data, copy_of_data);
}
