project(delay_calc_delta VERSION 0.0.1)
juce_add_console_app(delay_calc_delta PRODUCT_NAME "delay")
target_sources(delay_calc_delta PRIVATE main.cpp callback.cpp effect.cpp delay.cpp)
target_compile_definitions(delay_calc_delta PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(delay_calc_delta PRIVATE
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

target_compile_features(delay_calc_delta PRIVATE cxx_std_20)