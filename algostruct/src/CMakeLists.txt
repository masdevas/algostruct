file(GLOB CORE_SRC_SEARCH "search/*.cpp")
file(GLOB CORE_SRC_SORTS "sorts/*.cpp")
file(GLOB CORE_SRC_STRUCTS "structs/*.cpp")

add_library(libalgostruct STATIC ${CORE_SRC_SEARCH} ${CORE_SRC_SORTS} ${CORE_SRC_STRUCTS})