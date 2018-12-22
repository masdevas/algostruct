cmake_minimum_required(VERSION 3.12)

set(SRC_LIB_ALGOSTRUCT src/sorts/quick_sort_nonrec.cpp src/sorts/partitions.cpp)       #TODO create in src/
add_library(libalgostruct SHARED ${SRC_LIB_ALGOSTRUCT})
target_include_directories(libalgostruct PUBLIC include)