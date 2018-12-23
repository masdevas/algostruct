#include "data_generation.h"

std::vector<DataType> GenerateRandomVector(size_t size, DataType lower_bound, DataType upper_bound) {
    std::random_device rnd;
    std::mt19937 generator(rnd());
    std::uniform_int_distribution<DataType> distribution(lower_bound, upper_bound);
    std::vector<DataType> res_vector(size);
    for (auto& elem : res_vector) {
        elem = distribution(generator);
    }
    return res_vector;
}