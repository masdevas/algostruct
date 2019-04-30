cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_FLAGS -fsanitize=address,undefined,leak)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/algostruct/CMakeModules)
set(MAIN_HEADERS ${PROJECT_SOURCE_DIR}/algostruct/include)
set(MAIN_SRCS ${PROJECT_SOURCE_DIR}/algostruct/src)

include_directories(include)

add_subdirectory(src)
add_subdirectory(tests)
