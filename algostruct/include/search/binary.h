#ifndef ALGOSTRUCT_BINARY_H
#define ALGOSTRUCT_BINARY_H

#include <iterator>
#include <iostream>

namespace algostruct {
    template<typename Iterator, typename T, typename Comparator = std::less<T>>
    Iterator lower_bound(Iterator begin, Iterator end, const T &value,
                         const Comparator &comparator = Comparator()) {
        typename std::iterator_traits<Iterator>::difference_type step, count;
        Iterator it;
        count = std::distance(begin, end);
        while (count > 0) {
            it = begin;
            step = count / 2;
            std::advance(it, step);
            if (comparator(*it, value)) {
                begin = ++it;
                count -= step + 1;
            } else {
                count = step;
            }
        }
        return begin;
    }
    template<typename Iterator, typename T, typename Comparator = std::less<T>>
    Iterator upper_bound(Iterator begin, Iterator end, const T &value,
                         const Comparator &comparator = Comparator()) {
        typename std::iterator_traits<Iterator>::difference_type step, count;
        Iterator it;
        count = std::distance(begin, end);
        while (count > 0) {
            it = begin;
            step = count / 2;
            std::advance(it, step);
            if (!comparator(value, *it)) {
                begin = ++it;
                count -= step + 1;
            } else {
                count = step;
            }
        }
        return begin;
    }
}
#endif //ALGOSTRUCT_BINARY_H
