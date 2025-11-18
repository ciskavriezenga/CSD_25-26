cmake_minimum_required(VERSION 3.10)
project(hello)

add_executable(4_sine)

target_sources(4_sine PRIVATE
    main.cpp
    sine.cpp
    writeToFile.cpp
)
set_property(TARGET 4_sine PROPERTY CXX_STANDARD 20)
