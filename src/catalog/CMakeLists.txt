add_library(minidb_catalog
    catalog.cpp
)

target_include_directories(minidb_catalog PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(minidb_catalog
    INTERFACE lib_compile_flags
    INTERFACE lib_strict_warnings
    PRIVATE minidb_table
)
