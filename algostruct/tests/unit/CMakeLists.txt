cmake_minimum_required(VERSION 3.12)

find_package(GTest REQUIRED)
find_package(Threads)
enable_testing()

set(SUPPORT_HEADERS ${PROJECT_SOURCE_DIR}/algostruct/tests/unit/support)

include(AlgostructUnitTest)

add_subdirectory(heap)
add_subdirectory(search)
add_subdirectory(sort)
add_subdirectory(tree_traverse)

