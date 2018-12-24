#ifndef ALGOSTRUCT_DATATYPE_H
#define ALGOSTRUCT_DATATYPE_H

#include <cstdint>
#include <random>
#include <vector>
#include <functional>
#include <string>

using DataType = float;

extern DataType lower_bound;
extern DataType upper_bound;

static std::vector<DataType>::iterator (*LocalPartition)(std::vector<DataType>::iterator,
                                                         std::vector<DataType>::iterator,
                                                         std::mt19937&,
                                                         const std::function<bool(const DataType&,
                                                                                  const DataType&)>&);

static std::vector<std::string>::iterator
(*LocalStringPartition)(std::vector<std::string>::iterator,std::vector<std::string>::iterator,
                        std::mt19937&, const std::function<bool(const std::string&, const std::string&)>&);

template <typename DataType>
std::vector<DataType> GenerateRandomVector(size_t size, DataType lower_bound, DataType upper_bound) {
    std::random_device rnd;
    std::mt19937 generator(rnd());
    std::uniform_real_distribution<DataType> distribution(lower_bound, upper_bound);
    std::vector<DataType> res_vector(size);
    for (auto& elem : res_vector) {
        elem = distribution(generator);
    }
    return res_vector;
}

template <typename DataType>
std::vector<DataType> GenerateRandomVectorInt(size_t size, DataType lower_bound, DataType upper_bound) {
    std::random_device rnd;
    std::mt19937 generator(rnd());
    std::uniform_int_distribution<DataType> distribution(lower_bound, upper_bound);
    std::vector<DataType> res_vector(size);
    for (auto& elem : res_vector) {
        elem = distribution(generator);
    }
    return res_vector;
}

std::vector<std::string> GenerateRandomStrings(size_t size, size_t count_symbols);

#endif