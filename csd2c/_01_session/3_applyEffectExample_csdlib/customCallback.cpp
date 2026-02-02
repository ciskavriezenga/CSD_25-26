//
// Created by Ciska Vriezenga on 26/01/2026.
//

#include "customCallback.h"
#define EXAMPLE 2

void CustomCallback::prepare(int sampleRate)
{
    sine.prepare(sampleRate);
    sine.setFrequency(2.0f);
}


void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

    for (int sample = 0u; sample < numFrames; ++sample) {
        for (int channel = 0u; channel < numOutputChannels; ++channel) {

#if EXAMPLE == 0
            // generate noise example
            outputChannels[channel][sample] = static_cast<float> (distribution(generator)) * 0.2f;
#elif EXAMPLE == 1
            // generate sine
            outputChannels[channel][sample] = sine.getSample();
#else
            float outputSample = waveShaper.processFrame(inputChannels[channel][sample]);

            // input to output
            outputChannels[channel][sample] = outputSample;
#endif
        }
        sine.tick();
    }
}