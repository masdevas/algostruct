#include <gtest/gtest.h>
#include <algorithm>
#include <functional>
#include "sorts/quick_sort_nonrec.h"
#include "sorts/partitions.h"
#include "data_generation.h"

std::vector<DataType>::iterator (*f2)(std::vector<DataType>::iterator,
        std::vector<DataType>::iterator,
        std::mt19937&,
        const std::function<bool(const DataType&, const DataType&)>&);

TEST(TEST_QUICK_SORT_NONREC, RANDOM_TEST) {
    size_t size = 200;
    DataType lower_bound = -1000, upper_bound = 1000;
    auto data = GenerateRandomVector(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    f2 = Partition;
    QuickSortNonRecursion(data.begin(), data.end(), comp, f2);
    std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    EXPECT_EQ(data, copy_of_data);
}
