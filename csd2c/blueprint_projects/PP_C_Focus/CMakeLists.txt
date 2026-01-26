cmake_minimum_required(VERSION 3.20)
project(PP_Focus VERSION 1.0)
add_subdirectory(JUCE)
juce_add_console_app(PP_Focus PRODUCT_NAME "PP Focus")
target_sources(PP_Focus PRIVATE main.cpp writeToFile.cpp)
target_compile_definitions(PP_Focus PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(PP_Focus 
    PRIVATE
    juce::juce_audio_basics
    juce::juce_audio_devices
    juce::juce_audio_formats
    juce::juce_audio_processors

    PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_warning_flags
)

target_compile_features(PP_Focus PRIVATE cxx_std_20)

