#include "data_generation.h"

std::string GenerateRandomString(size_t size, std::mt19937& generator) {
    std::uniform_int_distribution<char> distribution('a', 'z');
    std::string res;
    for (size_t i = 0; i < size; ++i) {
        res.push_back(distribution(generator));
    }
    return res;
}

std::vector<std::string> GenerateRandomStrings(size_t size, size_t count_symbols) {
    std::random_device rnd;
    std::mt19937 generator(rnd());
    std::vector<std::string> res;
    for (size_t i = 0; i < size; ++i) {
        res.push_back(GenerateRandomString(count_symbols, generator));
    }
    return res;
}
