cmake_minimum_required(VERSION 3.10)
project(example)

add_executable(example)

target_sources(example PRIVATE
    1_oscillator.cpp
    #2_oscillator.cpp
    #3_oscillator.cpp
)
set_property(TARGET example PROPERTY CXX_STANDARD 20)
