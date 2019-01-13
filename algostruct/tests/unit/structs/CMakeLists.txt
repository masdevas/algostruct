cmake_minimum_required(VERSION 3.12)

set(TEST_NAME TestDHeap)
add_executable(${TEST_NAME} dheap.cpp)
target_link_libraries(${TEST_NAME} gtest gtest_main pthread)
target_include_directories(${TEST_NAME} PUBLIC ${GTEST_INCLUDE_DIRS} ${MAIN_HEADERS})
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})