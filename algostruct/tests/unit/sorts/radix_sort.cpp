#include <gtest/gtest.h>
#include <algorithm>
#include <climits>
#include "sorts/radix_sort.h"
#include "../support/data_generation.h"

TEST(TEST_RADIX_SORT, RANDOM_TEST) {
    size_t size = 1000000;
    using LocalDataType = uint8_t;
    size_t max_value_local_datatype = UINT8_MAX;
    using DataType = uint32_t;
    DataType lower_bound = 0, upper_bound = UINT32_MAX;
    auto data = GenerateRandomVectorInt(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    auto extractor = [](const DataType& data, size_t index_digit) -> LocalDataType {
        DataType mask = static_cast<DataType>(~0) >> ((sizeof(DataType) - sizeof(LocalDataType)) * 8);
        return static_cast<LocalDataType>((data & (mask << 8 * sizeof(LocalDataType) * index_digit))
            >> 8 * sizeof(LocalDataType) * index_digit);
    };
    RadixSort(data.begin(), data.end(), sizeof(DataType) / sizeof(LocalDataType),
            max_value_local_datatype, extractor);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}
