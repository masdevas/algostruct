#include <gtest/gtest.h>
#include <algorithm>
#include <functional>
#include "sorts/quick_sort_nonrec.h"
#include "sorts/partitions.h"
#include "data_generation.h"

TEST(TEST_QUICK_SORT_NONREC, RANDOM_TEST_PARTITION) {
    size_t size = 200;
    DataType lower_bound = -1000, upper_bound = 1000;
    auto data = GenerateRandomVector(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    LocalPartition = Partition;
    QuickSortNonRecursion(data.begin(), data.end(), comp, LocalPartition);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}


TEST(TEST_QUICK_SORT_NONREC, RANDOM_TEST_LOMUTO_PARTITION) {
    size_t size = 200;
    DataType lower_bound = -1000, upper_bound = 1000;
    auto data = GenerateRandomVector(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    LocalPartition = LomutoPartition;
    QuickSortNonRecursion(data.begin(), data.end(), comp, LocalPartition);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}
