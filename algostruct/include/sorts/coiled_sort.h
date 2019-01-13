#ifndef ALGOSTRUCT_COILED_COUNT_SORT_H
#define ALGOSTRUCT_COILED_COUNT_SORT_H

#include <vector>
#include <iterator>

template <typename ValueType>
class CoiledBuffer {
public:

    explicit CoiledBuffer(size_t buffer_size, size_t reserve_in_sub = 0, size_t shape_start_capacity = 0)
        : buffer_(buffer_size) {
        shape_.reserve(shape_start_capacity);
        for (auto& sub : buffer_) {
            sub.reserve(reserve_in_sub);
        }
    }

    void Add(ValueType value) {
        size_t coiled_count = value / buffer_.size();
        if (coiled_count >= shape_.size()) {
            shape_.resize(coiled_count + 1);       // what doing resize if have needed capacity? recopying or just change size?
        }
        ++(shape_[coiled_count]);
        buffer_[value % buffer_.size()].emplace_back(coiled_count);
    }

    template <typename Iterator>
    void Fill(Iterator begin, Iterator end) {
        auto offsets = Offsets();
        for (typename std::iterator_traits<Iterator>::value_type index = 0; index < buffer_.size(); ++index) {
            for (auto& coiled_count : buffer_[index]) {
                *(begin + offsets[coiled_count]) = index;
                ++(offsets[coiled_count]);
            }
        }
    }

private:
    std::vector<size_t> Offsets() {
        std::vector<size_t> offsets(shape_.size());
        offsets[0] = 0;
        for (size_t index = 1; index < offsets.size(); ++index) {
            offsets[index] = offsets[index - 1] + shape_[index - 1];
        }
        return offsets;
    }

    std::vector<std::vector<size_t>> buffer_;

    std::vector<size_t> shape_;
};

template <typename Iterator>
void CoiledCountSort(Iterator begin, Iterator end, size_t buffer_size) {
    CoiledBuffer<typename std::iterator_traits<Iterator>::value_type> buffer(buffer_size);
    Iterator it = begin;
    while (it != end) {
        buffer.Add(*it);
        ++it;
    }
    buffer.Fill(begin, end);
}

#endif