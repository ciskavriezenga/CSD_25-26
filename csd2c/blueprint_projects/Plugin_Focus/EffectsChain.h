#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

class EffectsChain {
public:
    EffectsChain() {}
    void prepareToPlay(float sampleRate, int numSamplesPerBlock){
        // Your Prepare Goes Here 

    }

    void getNextBlock(juce::AudioBuffer<float>& buffer){
        // Your DSP goes here 
        
        for(int channel = 0; channel < buffer.getNumChannels(); ++channel){
            auto* inputChannel = buffer.getReadPointer(channel);
            auto* outputChannel = buffer.getWritePointer(channel);
            for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
                outputChannel[sample] = inputChannel[sample];
            }
        }
        

    }

    void setParameter(float parameter){
        // Your Code goes here 
    }

private:

};
