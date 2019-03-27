#ifndef ALGOSTRUCT_TREE_SORT_H
#define ALGOSTRUCT_TREE_SORT_H

#include <set>
#include <iterator>
#include <functional>

template <typename Iterator, typename Comparator>
void TreeSort(Iterator begin, Iterator end, const Comparator& comparator) {
    std::multiset<typename std::iterator_traits<Iterator>::value_type, Comparator> set(comparator);
    Iterator it = begin;
    while (it != end) {
        set.insert(*it);
        ++it;
    }
    for (auto& elem : set) {
        *begin = elem;
        ++begin;
    }
}

#endif
