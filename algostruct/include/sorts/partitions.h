#ifndef AACA_PARTITIONS_H
#define AACA_PARTITIONS_H

#include <iterator>
#include <iostream>

#include "random_iterator.h"

template <typename Iterator, typename Comparator, typename RandomGenerator>
Iterator LomutoPartition(Iterator begin, Iterator end, RandomGenerator& generator,
                       const Comparator& comparator) {
    Iterator iterator_middle = GenerateRandomIterator(begin, end, generator),
            current_parts_divider = begin;
    typename std::iterator_traits<Iterator>::value_type middle_value =
            *iterator_middle;
    for (Iterator for_check = begin; for_check < end; ++for_check) {
        if (comparator(*for_check, *middle_value)) {
            std::swap(*for_check, *current_parts_divider);
            ++current_parts_divider;
        }
    }
    if (current_parts_divider == begin) {
        std::swap(*begin, *iterator_middle);
        ++current_parts_divider;
    }
    return current_parts_divider;
}

template <typename Iterator, typename Comparator, typename RandomGenerator>
Iterator Partition(Iterator begin, Iterator end, RandomGenerator& generator,
                   const Comparator& comparator) {
    Iterator iterator_middle = GenerateRandomIterator(begin, end, generator);
    auto pivot = *(iterator_middle);
    while (true) {
        while (comparator(*begin, pivot)) {
            ++begin;
        }
        --end;
        while (comparator(pivot, *end)) {
            --end;
        }
        if (begin >= end) {
            return begin;
        }
        std::swap(*begin, *end);
        ++begin;
    }
}

#endif
