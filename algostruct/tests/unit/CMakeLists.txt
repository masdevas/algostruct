cmake_minimum_required(VERSION 3.12)

find_package(GTest REQUIRED)
find_package(Threads)
enable_testing()

set(SUPPORT_HEADERS ${PROJECT_SOURCE_DIR}/algostruct/tests/unit/support)

function(create_test)
    cmake_parse_arguments(CREATE_TEST "" "TEST_NAME" "SRC" ${ARGV})     #TODO what is ""?
    #message("'TEST_NAME' = [${CREATE_TEST_TEST_NAME}]")
    #message("'SRC' = [${CREATE_TEST_SRC}]")
    add_executable(${CREATE_TEST_TEST_NAME} ${CREATE_TEST_SRC} ${SUPPORT_HEADERS}/data_generation.cpp)
    target_link_libraries(${CREATE_TEST_TEST_NAME} ${GTEST_BOTH_LIBRARIES} Threads::Threads)
    target_include_directories(${CREATE_TEST_TEST_NAME} PUBLIC
            ${GTEST_INCLUDE_DIRS} ${MAIN_HEADERS} ${SUPPORT_HEADERS})
    add_test(NAME ${CREATE_TEST_TEST_NAME} COMMAND ${CREATE_TEST_TEST_NAME})
endfunction()



add_subdirectory(sorts)
add_subdirectory(structs)
add_subdirectory(search)