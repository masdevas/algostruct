#include <gtest/gtest.h>
#include <algorithm>
#include <climits>
#include <vector>
#include "heap/dheap.h"
#include "../sort/data_generation.h"

TEST(TEST_DHEAP, SIMPLE_TESTS_INSERT_EXTRACT) {
    {
        size_t size = 20;
        size_t child = 3;
        using DataType = int32_t;
        auto comparator = [](const DataType& lhs, const DataType& rhs){
            return lhs >= rhs;
        };
        DHeap<DataType> heap(size, child, comparator);
        std::vector<DataType> data = {5, 7, 2, 4, -6};
        size_t count = 0;
        for (auto& value : data) {
            heap.Insert(value);
            ++count;
            EXPECT_EQ(count, heap.Size());
        }
        data.clear();
        while (!heap.IsEmpty()) {
            data.emplace_back(heap.Extract());
            --count;
            EXPECT_EQ(count, heap.Size());
        }
        for (size_t index = 1; index < data.size(); ++index) {
            EXPECT_TRUE(comparator(data[index - 1], data[index]));
        }
    }
}

TEST(TEST_DHEAP, RANDOM_TESTS_INSERT_EXTRACT) {
    {
        size_t size = 20;
        size_t child = 3;
        using DataType = int32_t;
        DataType lower_bound = 50, upper_bound = 1000;
        auto comparator = [](const DataType& lhs, const DataType& rhs){
            return lhs >= rhs;
        };
        DHeap<DataType> heap(size, child, comparator);
        auto data = GenerateRandomVectorInt<DataType>(size, lower_bound, upper_bound);
        size_t count = 0;
        for (auto& value : data) {
            heap.Insert(value);
            ++count;
            EXPECT_EQ(count, heap.Size());
        }
        data.clear();
        while (!heap.IsEmpty()) {
            data.emplace_back(heap.Extract());
            --count;
            EXPECT_EQ(count, heap.Size());
        }
        for (size_t index = 1; index < data.size(); ++index) {
            EXPECT_TRUE(comparator(data[index - 1], data[index]));
        }
    }
}