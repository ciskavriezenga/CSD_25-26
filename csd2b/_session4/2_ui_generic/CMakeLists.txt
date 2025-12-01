get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} VERSION 0.0.1)

cmake_minimum_required(VERSION 3.20)

add_executable(${ProjectId} main.cpp)
target_compile_features(${ProjectId} PRIVATE cxx_std_20)