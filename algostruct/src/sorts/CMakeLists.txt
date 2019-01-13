cmake_minimum_required(VERSION 3.12)

set(SRC_LIB_ALGOSTRUCT quick_sort_nonrec.cpp quick_sort_eliminate.cpp partitions.cpp
                       tree_sort.cpp bucket_sort.cpp radix_sort.cpp k_merge_sort.cpp
                       bubble_sort.cpp insertion_sort.cpp d_heap_sort.cpp coiled_sort.cpp
                       count_sort.cpp)
add_library(libalgostruct SHARED ${SRC_LIB_ALGOSTRUCT})
target_include_directories(libalgostruct PUBLIC ${MAIN_HEADERS})
