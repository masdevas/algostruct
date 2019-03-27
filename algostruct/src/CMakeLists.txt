file(GLOB_RECURSE CORE_SRC "*.cpp")

add_library(libalgostruct STATIC ${CORE_SRC})