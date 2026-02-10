//
// Created by Ciska Vriezenga on 26/01/2026.
//

#include "customCallback.h"

void CustomCallback::prepare(int sampleRate)
{
    delay[0].setNumDelaySamples(11025);

}

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
    float outputSample1 = 0.0f;
    float outputSample2 = 0.0f;

    for (int sampleIndex = 0u; sampleIndex < numFrames; ++sampleIndex) {
        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            // apply waveshaper to input
            waveShaper.processFrame(inputChannels[0][sampleIndex], outputSample1);
            delay[channel].processFrame(outputSample1, outputSample2);
            outputChannels[channel][sampleIndex] = outputSample2;
        }
    }




}