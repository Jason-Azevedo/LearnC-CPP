cmake_minimum_required(VERSION 3.26)

# Define our hello world project
project(
    HelloWorld 
    VERSION 1.0 
    DESCRIPTION "This is a simple hello world project!"
    )

# What are we building
add_executable(HelloWorld ./src/main.cpp)

