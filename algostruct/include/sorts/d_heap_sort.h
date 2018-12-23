#ifndef ALGOSTRUCT_D_HEAP_SORT_H
#define ALGOSTRUCT_D_HEAP_SORT_H

#include <cstddef>
#include <vector>
#include <iterator>

template <typename DataType, typename Comparator>
class DHeap {
public:
    explicit DHeap(size_t size, size_t child, const Comparator& comparator) :
            child(child), comparator_(comparator) {
        data_.reserve(size);
    }

    DHeap(const DHeap& heap) = default;

    DHeap(DHeap&& heap) noexcept = delete;

    ~DHeap() = default;

    DHeap& operator=(const DHeap& heap) = default;

    DHeap& operator=(DHeap&& heap) noexcept = delete;

    size_t Size() const {
        return data_.size();
    }

    bool Insert(const DataType& value) {
        if (data_.size() == data_.capacity()) {
            return false;
        }
        data_.emplace_back(value);
        SiftUp(data_.size() - 1);
        return true;
    }

    DataType Extract() {
        if (data_.empty()) {
            return DataType{};
        }
        DataType result = data_[0];
        data_[0] = data_.back();
        data_.pop_back();
        SiftDown(0);
        return result;
    }

private:
    std::vector<DataType> data_;

    size_t child;

    Comparator comparator_;

    constexpr size_t CountParentIndex(size_t index) const {
        return (index - 1) / child;
    }

    constexpr size_t CountFirstChildIndex(size_t index) const {
        return index * child + 1;
    }

    void SiftUp(size_t index) {
        if (index > 0) {
            size_t parent_index = CountParentIndex(index);
            if (comparator_(data_[index], data_[parent_index])) {
                std::swap(data_[index], data_[parent_index]);
                SiftUp(parent_index);
            }
        }
    }

    size_t FindIndexOfExtremum(size_t index_value, size_t index_first_child) {
        size_t index_of_extremum = CountFirstChildIndex(index_value);
        for (size_t index_of_child = CountFirstChildIndex(index_value) + 1;
             index_of_child < CountFirstChildIndex(index_value) + child && index_of_child < data_.size();
             ++index_of_child) {
            if (!comparator_(data_[index_of_extremum], data_[index_of_child])) {
                index_of_extremum = index_of_child;
            }
        }
        return index_of_extremum;
    }

    void SiftDown(size_t index) {
        size_t index_first_child = CountFirstChildIndex(index);
        if (index_first_child > data_.size()) {
            return;
        }
        size_t index_of_extremum = FindIndexOfExtremum(index, index_first_child);
        if (comparator_(data_[index_of_extremum], data_[index])) {
            std::swap(data_[index], data_[index_of_extremum]);
            SiftDown(index_of_extremum);
        }
    }
};

template <typename Iterator, typename Comparator>
void DHeapSort(Iterator begin, Iterator end, size_t child, const Comparator& comparator) {
    DHeap<typename std::iterator_traits<Iterator>::value_type, Comparator> heap(static_cast<size_t>(
            std::distance(begin, end)), child, comparator);
    Iterator it = begin;
    while (it != end) {
        heap.Insert(*it);
        ++it;
    }
    while (begin != end) {
        *begin = heap.Extract();
        ++begin;
    }
}

#endif
