//
// Created by Ciska Vriezenga on 26/01/2026.
//

#include "customCallback.h"

void CustomCallback::prepare(int sampleRate)
{
    sine.prepare(sampleRate);
    sine.setFrequency(440.0);
}


void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

    for (int sample = 0u; sample < numFrames; ++sample) {
        for (int channel = 0u; channel < numOutputChannels; ++channel) {

            // generate noise example
            //outputChannels[channel][sample] = static_cast<float> (distribution(generator)) * 0.2f;

            outputChannels[channel][sample] = sine.getSample();//inputChannels[channel][sample];

        }
        sine.tick();
    }
}