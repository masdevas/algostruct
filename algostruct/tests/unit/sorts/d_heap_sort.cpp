#include <gtest/gtest.h>
#include <algorithm>
#include "sorts/d_heap_sort.h"
#include "data_generation.h"

TEST(TEST_DHEAP_SORT, RANDOM_TEST) {
    size_t size = 1000;
    auto data = GenerateRandomVector(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    size_t child = 2;
    DHeapSort(data.begin(), data.end(), child, comp);
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
    size_t child = 2;
    DHeapSort(data.begin(), data.end(), child, comp);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}

