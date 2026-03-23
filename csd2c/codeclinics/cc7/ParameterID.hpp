#pragma once 

#include <juce_audio_processors/juce_audio_processors.h>

namespace plugin_focus::id {
    const juce::ParameterID CUTOFF {"uCutoff", 1};
    const juce::ParameterID RESO {"uResonance", 1};
    const juce::ParameterID TYPE {"uType", 1};
}
