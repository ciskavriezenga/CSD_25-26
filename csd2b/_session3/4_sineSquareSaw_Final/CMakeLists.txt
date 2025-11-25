
project(4_sineSquareSaw_Final VERSION 0.0.1)
juce_add_console_app(${PROJECT_NAME} PRODUCT_NAME "example")
target_sources(${PROJECT_NAME} PRIVATE main.cpp audioToFile.cpp oscillator.cpp sine.cpp square.cpp callback.cpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
