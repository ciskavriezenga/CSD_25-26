project(delay_signal_interpolation VERSION 0.0.1)
juce_add_console_app(delay_signal_interpolation PRODUCT_NAME "delay")
target_sources(delay_signal_interpolation PRIVATE main.cpp callback.cpp signal.cpp line.cpp effect.cpp delay.cpp)
target_compile_definitions(delay_signal_interpolation PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(delay_signal_interpolation PRIVATE
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

target_compile_features(delay_signal_interpolation PRIVATE cxx_std_20)