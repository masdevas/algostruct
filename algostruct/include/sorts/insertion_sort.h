#ifndef ALGOSTRUCT_INSERTION_SORT_H
#define ALGOSTRUCT_INSERTION_SORT_H

#include <algorithm>

template <typename Iterator, typename Comparator>
void InsertionSort(Iterator first, Iterator end, const Comparator& comparator) {
    for (Iterator it = first + 1; it != end; ++it) {
        for (Iterator it_second = it; it_second != first && comparator(*it_second, *(it_second - 1)); --it_second) {
            std::iter_swap(it_second - 1, it_second);
        }
    }
}

#endif
