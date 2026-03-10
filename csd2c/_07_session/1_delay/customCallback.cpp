//
// Created by Ciska Vriezenga on 26/01/2026.
//

#include "customCallback.h"

void CustomCallback::prepare(int sampleRate)
{
    delay.prepare(sampleRate);
}

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
    float outputSample1 = 0.0f;
    float outputSample2 = 0.0f;

    for (int sampleIndex = 0u; sampleIndex < numFrames; ++sampleIndex) {
        // NOTE: forced one channel output for now
        for (int channel = 0u; channel < 1; ++channel) {
            delay.applyEffect(inputChannels[0][sampleIndex], outputChannels[channel][sampleIndex]);
        }
    }
}

void CustomCallback::adaptDelayTime(float deltaDelayTime)
{
    float currentDelayTime = delay.getDelayTime();
    std::cout << currentDelayTime << std::endl;
    delay.setDelayTime(currentDelayTime + deltaDelayTime);
}