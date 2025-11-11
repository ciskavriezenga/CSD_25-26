cmake_minimum_required(VERSION 3.10)
project(example)

add_executable(example)

target_sources(example PRIVATE
    main.cpp
    oscillator.cpp
)
set_property(TARGET example PROPERTY CXX_STANDARD 20)
