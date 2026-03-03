project(delay_simple VERSION 0.0.1)
juce_add_console_app(delay_simple PRODUCT_NAME "delay")
target_sources(delay_simple PRIVATE main.cpp callback.cpp effect.cpp delay.cpp)
target_compile_definitions(delay_simple PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(delay_simple PRIVATE
        oscillators
        audio

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        #        juce::juce_recommended_warning_flags
)

target_compile_features(delay_simple PRIVATE cxx_std_20)