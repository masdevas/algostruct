#ifndef ALGOSTRUCT_K_MERGE_SORT_H
#define ALGOSTRUCT_K_MERGE_SORT_H

#include <vector>
#include <iterator>

template <typename Iterator, typename Comparator>
void KMergeSort(Iterator begin, Iterator end, const Comparator& comparator, size_t count_parts) {
    std::vector<typename std::iterator_traits<Iterator>::value_type> buffer(
            static_cast<size_t>(std::distance(begin, end)));
    std::copy(begin, end, buffer.begin());

}

#endif
