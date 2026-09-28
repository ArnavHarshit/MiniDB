add_library(minidb_common
    definitions.cpp
)

target_include_directories(minidb_common PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(minidb_common
    INTERFACE lib_compile_flags
    PRIVATE lib_strict_warnings
)
