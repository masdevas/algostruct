#include <gtest/gtest.h>
#include <algorithm>
#include "sorts/quick_sort_eliminate.h"
#include "sorts/partitions.h"
#include "../support/data_generation.h"

TEST(TEST_QUICK_SORT_ELIMINATE, RANDOM_TEST_PARTITION) {
    size_t size = 100;
    using DataType = double;
    double lower_bound = 0, upper_bound = 10000;
    auto data = GenerateRandomVectorReal(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    QuickSortEliminate(data.begin(), data.end(), comp,
            Partition<std::vector<DataType>::iterator, decltype(comp), std::mt19937>);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}

TEST(TEST_QUICK_SORT_ELIMINATE, RANDOM_TEST_LOMUTO_PARTITION) {
    size_t size = 100;
    using DataType = double;
    double lower_bound = 0, upper_bound = 10000;
    auto data = GenerateRandomVectorReal(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    QuickSortEliminate(data.begin(), data.end(), comp,
            LomutoPartition<std::vector<DataType>::iterator, decltype(comp), std::mt19937>);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}

TEST(TEST_DHEAP_SORT, RANDOM_TEST_STRING) {
    size_t size = 1000, count_symbols = 20;
    auto data = GenerateRandomStrings(size, count_symbols);
    auto copy_of_data = data;
    auto comp = [](const std::string& data_first, const std::string& data_second) {
        return data_first < data_second;
    };
    LocalStringPartition = Partition;
    QuickSortEliminate(data.begin(), data.end(), comp, LocalStringPartition);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}


TEST(TEST_DHEAP_SORT, RANDOM_TEST_STRING_LOMUTO) {
    size_t size = 3, count_symbols = 20;
    auto data = GenerateRandomStrings(size, count_symbols);
    auto copy_of_data = data;
    auto comp = [](const std::string& data_first, const std::string& data_second) {
        return data_first < data_second;
    };
    LocalStringPartition = LomutoPartition;
    QuickSortEliminate(data.begin(), data.end(), comp, LocalStringPartition);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}

