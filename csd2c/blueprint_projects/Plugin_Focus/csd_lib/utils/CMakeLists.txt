get_filename_component(libName ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" libName ${libName})

# STATIC means it will be baked into the binary (shared is also an option where that doesn't happen)
add_library(${libName} STATIC writeToFile.cpp bufferDebugger.cpp wavetableGenerator.cpp osc.cpp)
target_compile_features(${libName} PUBLIC cxx_std_20)
target_include_directories(${libName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${libName} 
    PRIVATE
    oscillators  
    PUBLIC 
    audio_header 
    juce::juce_audio_basics 
    juce::juce_audio_devices 
)
