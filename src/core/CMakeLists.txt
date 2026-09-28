add_library(minidb_core
    shared_spinlock.cpp
    row_builder.cpp
    row_reader.cpp
)

target_include_directories(minidb_core PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(minidb_core
    INTERFACE lib_compile_flags
    INTERFACE lib_strict_warnings
    PRIVATE minidb_common
    PUBLIC $<$<NOT:$<CONFIG:Release>>:stdc++exp>
)
