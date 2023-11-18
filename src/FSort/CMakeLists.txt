cmake_minimum_required(VERSION 3.26)

project(
    FSort
    VERSION 0.0.1
    DESCRIPTION "A simple c style cpp file sorter program"
    LANGUAGES CXX
)

add_subdirectory(src/config)
add_subdirectory(src/logging)
add_subdirectory(src/fileSorting)

add_executable(FSort 
    src/main.cpp
)