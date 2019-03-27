#ifndef ALGOSTRUCT_QUICK_SORT_ELIMINATE_H
#define ALGOSTRUCT_QUICK_SORT_ELIMINATE_H

#include <random>

template <typename Iterator, typename Comparator, typename RandomGenerator, typename Partition>
void QuickSortEliminateCore(Iterator begin, Iterator end, RandomGenerator &generator,
                            const Comparator &comparator, const Partition &partition) {
    while (end - begin > 1) {
        auto pivot = partition(begin, end, generator, comparator);
        QuickSortEliminateCore(pivot, end, generator, comparator, partition);
        end = pivot;
    }
}

template <typename Iterator, typename Comparator, typename Partition>
void QuickSortEliminate(Iterator begin, Iterator end, const Comparator &comparator,
                        const Partition &partition) {
    std::random_device random_device;
    std::mt19937 generator(random_device());
    QuickSortEliminateCore(begin, end, generator, comparator, partition);
}

#endif
