add_subdirectory(operators)

add_library(minidb_optimizer
    external_sort.cpp
    optimizer.cpp
)

target_include_directories(minidb_optimizer PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(minidb_optimizer
    INTERFACE lib_compile_flags
    INTERFACE lib_strict_warnings
    PUBLIC sql_parser
    PRIVATE
    minidb_storage_on_disk
    minidb_optimizer_operators
)
