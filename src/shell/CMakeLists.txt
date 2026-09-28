add_executable(minidb-shell
    main.cpp
    result_printer.cpp
)

target_include_directories(minidb-shell PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(minidb-shell
    INTERFACE lib_compile_flags
    INTERFACE lib_strict_warnings
    PUBLIC replxx
    PUBLIC sql_parser
    PUBLIC minidb_executor
)
