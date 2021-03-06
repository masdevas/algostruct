#ifndef ALGOSTRUCT_BUCKET_SORT_H
#define ALGOSTRUCT_BUCKET_SORT_H

#include <vector>
#include <algorithm>

#include "insertion_sort.h"
#include "bubble_sort.h"

template <typename Iterator, typename Comparator,
          typename ValueType = typename std::iterator_traits<Iterator>::value_type>
void BucketSort(Iterator begin, Iterator end,
                ValueType lower_bound, ValueType upper_bound/* (!)non-include */,
                const Comparator& comparator) {
    auto count_buckets = static_cast<size_t>(std::distance(begin, end));
    std::vector<std::vector<ValueType>> buckets(static_cast<size_t>(count_buckets) + 1);
    Iterator it = begin;
    double percent_for_bucket = ((static_cast<int64_t>(upper_bound) - lower_bound) / static_cast<double>(count_buckets))
            / (static_cast<int64_t>(upper_bound) - lower_bound);
    while (it != end) {
        double percent_for_value = (static_cast<double>(*it) - lower_bound)
                                   / (static_cast<int64_t>(upper_bound) - lower_bound);
        auto number_bucket_for_value = static_cast<size_t>(percent_for_value / percent_for_bucket);
        buckets[number_bucket_for_value].emplace_back(*it);
        ++it;
    }
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end(), comparator);
    }
    for (auto& bucket : buckets) {
        for (auto& element : bucket) {
            *begin = element;
            ++begin;
        }
    }

}

#endif
