get_filename_component(libName ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" libName ${libName})

add_library(${libName} STATIC oscillator.cpp sine.cpp saw.cpp square.cpp fastSine.cpp)
target_compile_features(${libName} PUBLIC cxx_std_20)
target_include_directories(${libName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})