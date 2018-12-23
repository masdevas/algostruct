#ifndef ALGOSTRUCT_BUBBLE_SORT_H
#define ALGOSTRUCT_BUBBLE_SORT_H

#include <cstdint>
#include <iterator>

template <typename Iterator, typename Comparator>
void BubbleSort(Iterator begin, Iterator end, const Comparator& comparator) {
    Iterator it = begin, last;
    while (std::distance(it, end) > 1) {
        ++it;
    }
    last = it;
    it = begin;
    while (last != it) {
        while (std::distance(it, last) > 0) {
            if (!comparator(*it, *(it + 1))) {
                std::swap(*it, *(it + 1));
            }
            ++it;
        }
        it = begin;
        --last;
    }
}

#endif
