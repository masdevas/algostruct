#ifndef ALGOSTRUCT_DATATYPE_H
#define ALGOSTRUCT_DATATYPE_H

#include <cstdint>
#include <random>
#include <vector>
#include <functional>

using DataType = int32_t;

static std::vector<DataType>::iterator (*LocalPartition)(std::vector<DataType>::iterator,
                                                         std::vector<DataType>::iterator,
                                                         std::mt19937&,
                                                         const std::function<bool(const DataType&,
                                                                                  const DataType&)>&);

std::vector<DataType> GenerateRandomVector(size_t size, DataType lower_bound, DataType upper_bound);

#endif