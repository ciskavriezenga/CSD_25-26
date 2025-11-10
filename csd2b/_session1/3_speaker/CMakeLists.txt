cmake_minimum_required(VERSION 3.10)
project(speaker)

add_executable(speaker main.cpp)
set_property(TARGET speaker PROPERTY CXX_STANDARD 20)
