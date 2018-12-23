#ifndef ALGOSTRUCT_RADIX_SORT_H
#define ALGOSTRUCT_RADIX_SORT_H

#include <iterator>
#include <algorithm>
#include <iostream>

template <typename Iterator, typename DigitExtractor, typename Comparator>
void RadixSort(Iterator begin, Iterator end, size_t count_digits, const DigitExtractor& extractor,
               const Comparator& comparator) {
    using ValueType =  typename std::iterator_traits<Iterator>::value_type;
    size_t index_digit = 0;
    auto comp = [&extractor, &index_digit, &comparator](const ValueType& value_left,
                                                        const ValueType& value_right) {
        return comparator(extractor(value_left, index_digit),
                          extractor(value_right, index_digit));
    };
    while (index_digit < count_digits) {
        std::stable_sort(begin, end, comp);
        ++index_digit;
    }
}

#endif
