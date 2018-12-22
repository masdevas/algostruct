cmake_minimum_required(VERSION 3.12)

set(MAIN_HEADERS ${PROJECT_SOURCE_DIR}/algostruct/include)

add_subdirectory(src/sorts)
add_subdirectory(tests/unit)
