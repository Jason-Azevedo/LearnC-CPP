cmake_minimum_required(VERSION 3.26)

project(
    TextRPGGame
    VERSION 1.0
    DESCRIPTION "This is a simple text based rpg console game."
    LANGUAGES CXX
    ) 

add_executable(TextRPGGame 
    src/main.cpp
    src/entity/entity.cpp
    )

target_include_directories(
    TextRPGGame
    PRIVATE 
        src/entity)
