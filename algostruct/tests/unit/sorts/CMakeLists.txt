cmake_minimum_required(VERSION 3.12)

set(TESTING_SRC quick_sort_nonrec.cpp)
set(TEST_NAME TestQuickSortNonrec)
add_executable(${TEST_NAME} ${TESTING_SRC})
target_link_libraries(${TEST_NAME} gtest gtest_main pthread)
target_include_directories(${TEST_NAME} PUBLIC ${GTEST_INCLUDE_DIRS})
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})