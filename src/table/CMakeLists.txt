add_library(minidb_table
    table.cpp
    table_handle.cpp
    table_manager.cpp
)

target_include_directories(minidb_table PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(minidb_table
    INTERFACE lib_compile_flags
    INTERFACE lib_strict_warnings
    PRIVATE minidb_common
    PRIVATE minidb_core
    PRIVATE minidb_catalog
    PRIVATE minidb_storage_ephemeral
    PRIVATE minidb_storage_on_disk
)
