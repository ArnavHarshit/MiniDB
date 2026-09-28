add_library(minidb_optimizer_operators
    file_scan_iterator.cpp
    projection_iterator.cpp
    selection_iterator.cpp
)

target_include_directories(minidb_optimizer_operators PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(minidb_optimizer_operators
    INTERFACE lib_compile_flags
    INTERFACE lib_strict_warnings
    PUBLIC sql_parser
    PRIVATE
    minidb_core
    minidb_common
    minidb_table
)
