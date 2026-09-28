add_library(minidb_config
    config.cpp
)

target_include_directories(minidb_config PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(minidb_config
    PUBLIC spdlog::spdlog
    INTERFACE lib_compile_flags
    INTERFACE lib_strict_warnings
)
