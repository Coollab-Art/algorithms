cmake_minimum_required(VERSION 3.8)

set(WARNINGS_AS_ERRORS_FOR_ALGORITHMS OFF CACHE BOOL "ON iff you want to treat warnings as errors")

add_library(algorithms)
add_library(algorithms::algorithms ALIAS algorithms)
target_compile_features(algorithms PUBLIC cxx_std_20)

# ---Add source files---
target_sources(algorithms PRIVATE
    src/algorithms.cpp
)

if(WARNINGS_AS_ERRORS_FOR_ALGORITHMS)
    target_include_directories(algorithms PUBLIC include)
else()
    target_include_directories(algorithms SYSTEM PUBLIC include)
endif()

# Set warning level
if(MSVC)
    target_compile_options(algorithms PRIVATE /W4)
else()
    target_compile_options(algorithms PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
endif()

# Maybe enable warnings as errors
set(WARNINGS_AS_ERRORS_FOR_ALGORITHMS OFF CACHE BOOL "ON iff you want to treat warnings as errors")
if(WARNINGS_AS_ERRORS_FOR_ALGORITHMS)
    if(MSVC)
        target_compile_options(algorithms PRIVATE /WX)
    else()
        target_compile_options(algorithms PRIVATE -Werror)
    endif()
endif()