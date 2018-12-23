#ifndef ALGOSTRUCT_QUICK_SORT_NONREC_H
#define ALGOSTRUCT_QUICK_SORT_NONREC_H

#include <stack>
#include <random>

template <typename Iterator>
struct Interval {
    Iterator begin;

    Iterator end;
};

template <typename Iterator, typename Comparator, typename RandomGenerator, typename Partition>
void QuickSortNonRecursionCore(Iterator begin, Iterator end, RandomGenerator &generator,
                               const Comparator &comparator, const Partition &partition) {
    std::stack<Interval<Iterator>> stack_intervals;
    stack_intervals.push(Interval<Iterator>{begin, end});
    if (std::distance(begin, end) <= 1) {
        return;
    }
    while (!stack_intervals.empty()) {
        Interval current_interval = stack_intervals.top();
        stack_intervals.pop();
        Iterator start_second_part = partition(current_interval.begin,
                                               current_interval.end, generator, comparator);
        if (std::distance(current_interval.begin, start_second_part) > 1) {
            stack_intervals.push(Interval<Iterator>{current_interval.begin,
                                                    start_second_part});
        }
        if (std::distance(start_second_part, current_interval.end) > 1) {
            stack_intervals.push(Interval<Iterator>{start_second_part,
                                                    current_interval.end});
        }
    }
}

template <typename Iterator, typename Comparator, typename Partition>
void QuickSortNonRecursion(Iterator begin, Iterator end, const Comparator &comparator,
                           const Partition &partition) {
    std::random_device random_device;
    std::mt19937 generator(random_device());
    QuickSortNonRecursionCore(begin, end, generator, comparator, partition);
}


#endif
