cmake_minimum_required(VERSION 3.22)
project(OpenLadder VERSION 0.0.1)

juce_add_plugin(OpenLadder
        VERSION 0.0.1
        # ICON_BIG ...
        # ICON_SMALL ...
        COMPANY_NAME CSD
        # IS_SYNTH TRUE/FALSE
        # NEEDS_MIDI_INPUT TRUE/FALSE
        # NEEDS_MIDI_OUTPUT TRUE/FALSE
        # IS_MIDI_EFFECT TRUE/FALSE
        # EDITOR_WANTS_KEYBOARD_FOCUS TRUE/FALSE
        # COPY_PLUGIN_AFTER_BUILD TRUE/FALSE
        PLUGIN_MANUFACTURER_CODE Csd2
        PLUGIN_CODE Opl1
        FORMATS AU VST3 Standalone
        PRODUCT_NAME "OpenLadder"
)

target_sources(OpenLadder
        PRIVATE
        PluginEditor.cpp
        PluginProcessor.cpp
)

target_compile_definitions(OpenLadder
        PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)


target_link_libraries(OpenLadder
        PRIVATE

        juce::juce_audio_utils
        juce::juce_product_unlocking
        juce::juce_data_structures

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
#        juce::juce_recommended_warning_flags
)


if(MSVC)
    add_definitions(-DNOMINMAX)
endif()

target_compile_features(OpenLadder PRIVATE cxx_std_20)

