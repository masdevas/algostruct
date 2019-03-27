cmake_minimum_required(VERSION 3.12)

set(MAIN_HEADERS ${PROJECT_SOURCE_DIR}/algostruct/include)
set(MAIN_SRCS ${PROJECT_SOURCE_DIR}/algostruct/src)
set(CMAKE_CXX_FLAGS -fsanitize=address,undefined,leak)

include_directories(include)

add_subdirectory(src)
add_subdirectory(tests/unit)
