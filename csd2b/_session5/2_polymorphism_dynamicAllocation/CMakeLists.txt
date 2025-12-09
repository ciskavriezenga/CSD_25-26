cmake_minimum_required(VERSION 3.10)
get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} VERSION 0.0.1)

add_executable(${ProjectId})
target_sources(${ProjectId} PRIVATE main.cpp)
target_compile_definitions(${ProjectId} PRIVATE SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")


target_compile_features(${ProjectId} PRIVATE cxx_std_20)




