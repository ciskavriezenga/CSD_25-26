#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
namespace plugin_focus {
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p),
    CutoffAttachment {
        *processorRef.getState().getParameter(id::CUTOFF.getParamID()), CutoffSlider, nullptr
    },
    ResonanceAttachment {
        *processorRef.getState().getParameter(id::RESO.getParamID()), ResonanceSlider, nullptr
    },
    FilterTypeAttachment {
        *processorRef.getState().getParameter(id::TYPE.getParamID()), FilterTypeSlider, nullptr
    }

{
    addAndMakeVisible (CutoffSlider);
    addAndMakeVisible (ResonanceSlider);
    addAndMakeVisible (FilterTypeSlider);

    CutoffSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    ResonanceSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    FilterTypeSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);

    CutoffSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 120, 40);
    ResonanceSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 120, 40);
    FilterTypeSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 120, 40);

    setSize (400, 300);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::gainsboro);

    g.setColour (juce::Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("Sliders" , getLocalBounds(), juce::Justification::bottomRight, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds().reduced (20);
    auto leftArea = bounds.removeFromLeft (bounds.getWidth() / 2);
    auto rightArea = bounds;

    CutoffSlider.setBounds (leftArea.reduced (10));

    auto topRight = rightArea.removeFromTop (rightArea.getHeight() / 2);
    ResonanceSlider.setBounds (topRight.reduced (10));
    FilterTypeSlider.setBounds (rightArea.reduced (10));
}

} // namespace plugin_focus
