# audio lib
get_filename_component(libName ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" libName ${libName})
add_library(${libName} STATIC)
target_compile_features(${libName} PUBLIC cxx_std_20)
target_include_directories(${libName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# header only files need INTERFACE
add_library(audio_header INTERFACE)
target_include_directories(audio_header INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/audiocomponent.h)
target_link_libraries(${libName} PUBLIC audio_header juce::juce_audio_basics juce::juce_audio_devices)