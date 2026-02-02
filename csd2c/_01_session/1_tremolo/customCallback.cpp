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
            // NOTE: For the sake of the example - contains duplicate code, and should be implemented in Tremolo class

            // map output sine to the required range: [-1, 1] --> [0,1]
            float modSignal = (sine.getSample() + 1.0f) * 0.5f;

            static float modDepth = 0.25f;
            modSignal *= modDepth;
            float modulatedSample = inputChannels[channel][sample] * modSignal;


            // input to output
            outputChannels[channel][sample] = inputChannels[channel][sample] * (1.0f - modDepth) + modulatedSample;
#endif
        }
        sine.tick();
    }
}