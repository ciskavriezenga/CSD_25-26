cmake_minimum_required(VERSION 3.22)
project(CSD LANGUAGES CXX)
get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} VERSION 0.0.1)

find_package(OpenCV REQUIRED)

add_executable(${ProjectId} main.cpp)
target_include_directories(${ProjectId} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${ProjectId} PRIVATE ${OpenCV_LIBS})
