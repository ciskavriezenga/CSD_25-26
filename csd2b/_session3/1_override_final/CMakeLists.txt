project(01_override_final VERSION 0.0.1)
juce_add_console_app(01_override_final PRODUCT_NAME "example")
target_sources(01_override_final PRIVATE main.cpp oscillator.cpp sine.cpp saw.cpp)
target_compile_definitions(01_override_final PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(01_override_final
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(01_override_final PRIVATE cxx_std_20)