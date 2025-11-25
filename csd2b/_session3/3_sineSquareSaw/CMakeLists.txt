project(3_sineSquareSaw VERSION 0.0.1)
juce_add_console_app(3_sineSquareSaw PRODUCT_NAME "example")
target_sources(3_sineSquareSaw PRIVATE main.cpp audioToFile.cpp oscillator.cpp sine.cpp square.cpp callback.cpp)
target_compile_definitions(3_sineSquareSaw PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR=".")

target_link_libraries(3_sineSquareSaw
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(3_sineSquareSaw PRIVATE cxx_std_20)
