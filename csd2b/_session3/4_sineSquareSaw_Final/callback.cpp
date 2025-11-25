#include "callback.h"

CustomCallback::CustomCallback (float samplerate)
  : AudioCallback (samplerate), oscillator (220, samplerate) {
}

void CustomCallback::prepare (int samplerate) {
  oscillator.setSamplerate (samplerate);
  std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process (AudioBuffer buffer) {
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0u; channel < numOutputChannels; ++channel) {
    for (int frame = 0u; frame < numFrames; ++frame) {
      outputChannels[channel][frame] = 0.0f;
      outputChannels[channel][frame] = oscillator.getSample();
      oscillator.tick();
    }
  }
}
