//
// Created by Ciska Vriezenga on 26/01/2026.
//

#include "customCallback.h"

void CustomCallback::prepare(int sampleRate){}

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
    float outputSample = 0.0f;

    for (int sampleIndex = 0u; sampleIndex < numFrames; ++sampleIndex) {
        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            // apply waveshaper to input
            waveShaper.processFrame(inputChannels[channel][sampleIndex], outputSample);
            outputChannels[channel][sampleIndex] = outputSample;
        }
    }
}