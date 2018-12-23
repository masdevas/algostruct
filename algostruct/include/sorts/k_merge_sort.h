#ifndef ALGOSTRUCT_K_MERGE_SORT_H
#define ALGOSTRUCT_K_MERGE_SORT_H

#include <vector>
#include <iterator>

#include "bubble_sort.h"

template <typename Iterator>
struct Part {
    Iterator begin;

    Iterator end;
};

template <typename Iterator, typename Comparator>
std::vector<Part<Iterator>> SortParts(std::vector<typename std::iterator_traits<Iterator>::value_type>& buffer,
                                      const Comparator& comparator, size_t count_parts) {
    size_t size_of_part = buffer.size() / count_parts;
    std::vector<Part<Iterator>> parts(count_parts);
    for (size_t part_number = 0; part_number < count_parts - 1; ++part_number) {
        parts[part_number] = {buffer.begin() + size_of_part * part_number,
                              buffer.begin() + size_of_part * (part_number + 1)};
        BubbleSort(parts[part_number].begin, parts[part_number].end, comparator);
    }
    parts[count_parts - 1] = {buffer.begin() + size_of_part * (count_parts - 1), buffer.end()};
    BubbleSort(parts[count_parts - 1].begin, parts[count_parts - 1].end, comparator);
    return parts;
}

template <typename Iterator, typename Comparator>
void MergeParts(Iterator begin, Iterator end, std::vector<Part<Iterator>>& parts,
                const Comparator& comparator) {
    auto limit = static_cast<size_t>(std::distance(begin, end));
    for (size_t index_copying_element = 0; index_copying_element < limit;
         ++index_copying_element) {
        size_t current_checking_part = 0;
        size_t number_best_part = 0;
        while (current_checking_part < parts.size()) {
            if (parts[current_checking_part].begin != parts[current_checking_part].end) {
                number_best_part = current_checking_part;
                break;
            }
            ++current_checking_part;
        }
        ++current_checking_part;
        for (; current_checking_part < parts.size(); ++current_checking_part) {
            if (parts[current_checking_part].begin != parts[current_checking_part].end) {
                if (comparator(*(parts[current_checking_part].begin), *(parts[number_best_part].begin))) {
                    number_best_part = current_checking_part;
                }
            }
        }
        *begin = *(parts[number_best_part].begin);
        ++(parts[number_best_part].begin);
        ++begin;
    }
}
template <typename Iterator, typename Comparator>
void KMergeSort(Iterator begin, Iterator end, const Comparator& comparator, size_t count_parts) {
    std::vector<typename std::iterator_traits<Iterator>::value_type> buffer(
            static_cast<size_t>(std::distance(begin, end)));
    std::copy(begin, end, buffer.begin());
    auto parts = SortParts<Iterator>(buffer, comparator, count_parts);
    MergeParts(begin, end, parts, comparator);
}

#endif
