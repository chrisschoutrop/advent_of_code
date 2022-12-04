cmake_minimum_required(VERSION 3.17)
project(advent_of_code)
enable_testing()

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
    add_compile_options(/Ox)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
    add_compile_options(-O3 -march=native)
endif()

add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
add_subdirectory(4)
