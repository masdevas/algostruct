#ifndef ALGOSTRUCT_COUNT_SORT_H
#define ALGOSTRUCT_COUNT_SORT_H

#include <vector>
#include <iterator>

template <typename Iterator>
void CountSort(Iterator begin, Iterator end, size_t buffer_size) {
    std::cout << "LLL222" << std::endl;
    std::vector<typename std::iterator_traits<Iterator>::value_type> buffer(buffer_size);
    std::cout << "LLL" << std::endl;
    Iterator it = begin;
    while (it != end) {
        ++(buffer[*it]);
        ++it;
    }
    for (size_t index = 0; index < buffer.size(); ++index) {
        while (buffer[index] != 0) {
            *begin = index;
            ++begin;
            --(buffer[index]);
        }
    }
}

#endif
