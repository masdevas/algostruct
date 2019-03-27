#ifndef AACA_RANDOM_ITERATOR_H
#define AACA_RANDOM_ITERATOR_H

#include <iterator>
#include <random>

template <typename Iterator, typename RandomGenerator>
Iterator GenerateRandomIterator(Iterator lower_bound, Iterator upper_bound,
                                RandomGenerator& generator) {
    auto distance = std::distance(lower_bound, upper_bound);
    std::uniform_int_distribution<typename std::iterator_traits<Iterator>::difference_type>
            distribution(0, distance - 1);
    return lower_bound + distribution(generator);
}

#endif
