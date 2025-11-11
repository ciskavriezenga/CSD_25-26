cmake_minimum_required(VERSION 3.20)
project(CMakeTestProject LANGUAGES CXX)

add_executable(Hi hello.cpp)
set_property(TARGET Hi PROPERTY CXX_STANDARD 20)
