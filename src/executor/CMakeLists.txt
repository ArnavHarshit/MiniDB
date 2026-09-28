add_library(minidb_executor
    executor.cpp
)

target_include_directories(minidb_executor PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(minidb_executor
    INTERFACE lib_compile_flags
    INTERFACE lib_strict_warnings
    PRIVATE sql_parser
    PRIVATE minidb_catalog
    PRIVATE minidb_storage_ephemeral
    PRIVATE minidb_optimizer
)
