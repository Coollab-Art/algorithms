cmake_minimum_required(VERSION 3.8)

add_library(algorithms)
add_library(algorithms::algorithms ALIAS algorithms)
target_compile_features(algorithms PUBLIC cxx_std_20)

# ---Add source files---
target_include_directories(algorithms PUBLIC include)
target_sources(algorithms PRIVATE
    src/algorithms.cpp
)

# ---Setup warnings---
if (ALGORITHMS_ENABLE_WARNINGS_AS_ERRORS)
    message("-- [algorithms] Enabling warnings as errors for algorithms")
    if(MSVC)
        target_compile_options(algorithms PRIVATE /WX /W4)
    else()
        target_compile_options(algorithms PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
    endif()
else()
    message("-- [algorithms] Not using warnings as errors for algorithms")
endif()
