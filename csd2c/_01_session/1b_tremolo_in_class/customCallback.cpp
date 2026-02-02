//
// Created by Ciska Vriezenga on 26/01/2026.
//

#include "customCallback.h"

void CustomCallback::prepare(int sampleRate)
{
    tremolo.prepare(sampleRate);
}

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
    float outputSample = 0.0f;
    for (int sample = 0u; sample < numFrames; ++sample) {
        // NOTE: only processing left channel for now
        // (otherwise, the sine in tremolo will be updated twice per sample)
        for (int channel = 0u; channel < 1; ++channel) {
            // apply tremolo to input
            tremolo.processFrame(inputChannels[channel][sample], outputSample);
            outputChannels[channel][sample] = outputSample;
        }
    }
}