//
// Created by Ciska Vriezenga on 26/01/2026.
//

#include "customCallback.h"

void CustomCallback::prepare(int sampleRate)
{

}

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
    float outputSample1 = 0.0f;
    float outputSample2 = 0.0f;

    for (int sampleIndex = 0u; sampleIndex < numFrames; ++sampleIndex) {
        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            // TODO - add Changeable Delay class (and Signal and Line)
            outputChannels[channel][sampleIndex] = inputChannels[0][sampleIndex] * envelopeOutput;
        }
    }




}