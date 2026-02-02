# header only files need INTERFACE
add_library(audio_header INTERFACE)
target_include_directories(audio_header INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/audiocomponent.h)

add_library(csd_lib STATIC)
target_compile_features(csd_lib PUBLIC cxx_std_20)
target_include_directories(csd_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/oscillators
)
target_link_libraries(csd_lib
    PUBLIC
        audio_header
        juce::juce_audio_basics
        juce::juce_audio_devices

        utils
        oscillators
        effects
)

add_subdirectory(effects)
add_subdirectory(oscillators)
add_subdirectory(utils)
