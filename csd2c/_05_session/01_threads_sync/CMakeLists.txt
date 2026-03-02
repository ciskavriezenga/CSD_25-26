cmake_minimum_required(VERSION 3.20)
project(01_threads_sync VERSION 0.0.1)

add_executable(01_threads_sync main.cpp)
target_compile_definitions(01_threads_sync PRIVATE SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(01_threads_sync PRIVATE cxx_std_20)