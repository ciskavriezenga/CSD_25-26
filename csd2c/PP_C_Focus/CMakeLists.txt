project(FileWriter VERSION 1.0)
juce_add_console_app(FileWriter PRODUCT_NAME "File Writer Test")
target_sources(FileWriter PRIVATE main.cpp writeToFile.cpp)
target_compile_definitions(FileWriter PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(FileWriter 
    PRIVATE
    juce::juce_audio_basics
    juce::juce_audio_devices
    juce::juce_audio_formats
    juce::juce_audio_processors

    PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_warning_flags
)

target_compile_features(FileWriter PRIVATE cxx_std_20)

