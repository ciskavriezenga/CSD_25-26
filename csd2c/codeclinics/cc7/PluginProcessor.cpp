#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "ParameterID.hpp"

namespace plugin_focus {
//==============================================================================
AudioPluginAudioProcessor::AudioPluginAudioProcessor()
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
                       State {*this, nullptr, "Parameters", createParameterLayout(parameters)}
{

    const auto numChannels = getBusesLayout().getNumChannels(true, 0); 
    filters.clear();
    filters.reserve(numChannels);
    for (int i = 0; i < numChannels; ++i)
        filters.emplace_back();

}

AudioPluginAudioProcessor::~AudioPluginAudioProcessor()
{
}

//==============================================================================
const juce::String AudioPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AudioPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AudioPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AudioPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AudioPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AudioPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AudioPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AudioPluginAudioProcessor::setCurrentProgram (int index)
{
    juce::ignoreUnused (index);
}

const juce::String AudioPluginAudioProcessor::getProgramName (int index)
{
    juce::ignoreUnused (index);
    return {};
}

void AudioPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
    juce::ignoreUnused (index, newName);
}

//==============================================================================
void AudioPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused (samplesPerBlock);

    for (auto & filter : filters) {
        filter.prepare(sampleRate);
    }
}

void AudioPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

bool AudioPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}

void AudioPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                              juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused (midiMessages);

    for (auto & filter : filters) {
        filter.setCriticalFrequency(*parameters.cutoff);
        filter.setResonance(*parameters.resonance);

        LadderCoefficients coeffs; 
        const auto filterType = static_cast<int>(*parameters.filterType);
        //TODO change to morph with infinite morphing
        switch (filterType) {
            case 0: {
                        coeffs = MoogLadder::makeLoPass24();
                        break;
                    }
            case 1: {
                        coeffs = MoogLadder::makeLoPass12();
                        break;
                    }
            case 2: {
                        coeffs = MoogLadder::makeBandPass12();
                        break;
                    }
            case 3: {
                        coeffs = MoogLadder::makeBandPass24();
                        break; 
                    }
            case 4: {
                        coeffs = MoogLadder::makeHiPass12();
                        break; 
                    }
            case 5: {
                        coeffs = MoogLadder::makeHiPass24();
                        break;
                    }
            default: {
                        coeffs = MoogLadder::makeLoPass24();
                        break;
                     }
        }

        filter.setCoefficients(coeffs);
    }


    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        auto* writePointer = buffer.getWritePointer (channel);
        auto* readPointer = buffer.getReadPointer (channel);
        
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
            writePointer[sample] = filters[channel].process(readPointer[sample]);
        }
    }
}

//==============================================================================
bool AudioPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* AudioPluginAudioProcessor::createEditor()
{
    return new AudioPluginAudioProcessorEditor (*this);
}

//==============================================================================
void AudioPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = State.copyState();
    std::unique_ptr<juce::XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);
}

void AudioPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName (State.state.getType()))
            State.replaceState (juce::ValueTree::fromXml (*xmlState));
}

juce::AudioProcessorValueTreeState::ParameterLayout AudioPluginAudioProcessor::createParameterLayout(
        AudioPluginAudioProcessor::Parameters& parameters){
    using namespace juce; 
    AudioProcessorValueTreeState::ParameterLayout layout;
    {
        auto parameter = std::make_unique<AudioParameterFloat>(id::CUTOFF, "Cutoff", juce::NormalisableRange<float>(50.0f, 15000.0f, 0.01f, 0.4f, false), 500.0f);
        parameters.cutoff = parameter.get();
        layout.add(std::move(parameter));
    }
    {
        auto parameter = std::make_unique<AudioParameterFloat>(id::RESO, "Resonance", 0.01f, 1.0f, 0.3f);
        parameters.resonance = parameter.get();
        layout.add(std::move(parameter));
    }
    {
        auto parameter = std::make_unique<AudioParameterFloat>(id::TYPE, "Filter Type", 0.0f, 5.0f, 1.0f);
        parameters.filterType = parameter.get();
        layout.add(std::move (parameter));
    }

    return layout;
}

} // namespace plugin_focus
//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new plugin_focus::AudioPluginAudioProcessor();
}
