#ifndef ALGOSTRUCT_RADIX_SORT_H
#define ALGOSTRUCT_RADIX_SORT_H

#include <iterator>
#include <vector>

template <typename Iterator, typename DigitExtractor>
void RadixSort(Iterator begin, Iterator end, size_t count_digits, size_t count_values,
               const DigitExtractor& extractor) {
    using ValueType = typename std::iterator_traits<Iterator>::value_type;
    size_t index_digit = 0;
    while (index_digit < count_digits) {
        std::vector<std::vector<ValueType>> buckets(static_cast<size_t>(count_values) + 1);
        Iterator it = begin;
        while (it != end) {
            auto val = extractor(*it, index_digit);
            buckets[val].emplace_back(*it);
            ++it;
        }
        it = begin;
        for (auto& bucket : buckets) {
            for (auto& element : bucket) {
                *it = element;
                ++it;
            }
        }
        ++index_digit;
    }
}

#endif
