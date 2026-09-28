#pragma once

#include <cstdlib>
#include <iostream>
#ifndef NDEBUG
#include <stacktrace>
#endif

/**
 * Custom assertion macro for MiniDB
 *
 * MiniDB_ASSERT(condition, message)
 *   - Only active in debug builds (disabled when NDEBUG is defined)
 *   - Prints detailed error information including the condition, custom message,
 *     file location, line number, and function name
 *   - Aborts the program if the condition is false
 *
 * Usage:
 *   MiniDB_ASSERT(ptr != nullptr, "Pointer must not be null");
 *   MiniDB_ASSERT(count > 0, "Count must be positive");
 */

#ifdef NDEBUG
#define MiniDB_ASSERT(condition, message) ((void)0)
#else
#define MiniDB_ASSERT(condition, message)                                                       \
    do {                                                                                      \
        if (!(condition)) {                                                                   \
            minidb::detail::AssertionFailed(#condition, message, __FILE__, __LINE__, __func__); \
        }                                                                                     \
    } while (0)
#endif

namespace minidb::detail {
/**
 * Called when an assertion fails
 *
 * This function prints detailed error information to stderr and aborts
 * the program. It should not be called directly - use MiniDB_ASSERT instead.
 */
[[noreturn]] inline void AssertionFailed(
    const char* condition,
    const char* message,
    const char* file,
    int line,
    const char* func)
{
    std::cerr << "\n=== Assertion Failed ===\n"
              << "Condition: " << condition << "\n"
              << "Message:   " << message << "\n"
              << "Location:  " << file << ":" << line << "\n"
              << "Function:  " << func << "\n"
              << "Stacktrace:\n" << std::stacktrace::current() << "\n"
              << "========================\n"
              << std::flush;
    std::abort();
}
}
