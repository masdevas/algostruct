cmake_minimum_required(VERSION 3.12)

set(SRC_LIB_ALGOSTRUCT quick_sort_nonrec.cpp quick_sort_eliminate.cpp tree_sort.cpp partitions.cpp)
add_library(libalgostruct SHARED ${SRC_LIB_ALGOSTRUCT})
target_include_directories(libalgostruct PUBLIC ${MAIN_HEADERS})
