cmake_minimum_required(VERSION 3.10)
project(hello)

add_executable(4_simpleInheritance)

target_sources(4_simpleInheritance PRIVATE
    main.cpp
    pet.cpp
    dog.cpp
    cat.cpp
)
set_property(TARGET 4_simpleInheritance PROPERTY CXX_STANDARD 20)
