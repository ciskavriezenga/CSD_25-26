#pragma once

#include "PluginProcessor.h"
#include "ParameterID.hpp"
//==============================================================================
namespace plugin_focus {
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    AudioPluginAudioProcessor& processorRef;
    
    juce::Slider CutoffSlider {"Cutoff Slider"};
    juce::Slider ResonanceSlider {"Resonance Slider"};
    juce::Slider FilterTypeSlider {"FilterType Slider"};

    juce::SliderParameterAttachment CutoffAttachment;
    juce::SliderParameterAttachment ResonanceAttachment;
    juce::SliderParameterAttachment FilterTypeAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
} // namespace plugin_focus
