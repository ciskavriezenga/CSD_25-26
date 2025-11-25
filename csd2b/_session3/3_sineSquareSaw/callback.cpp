#include "callback.h"

CustomCallback::CustomCallback (float samplerate)
  : AudioCallback (samplerate),
    oscillator(220, samplerate),
    oscillatorFifth(220 * (3/2), samplerate),
    oscillatorFifthDetuned(220 * (3.01/2), samplerate)
{

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
      float sample = oscillator.getSample() + oscillatorFifth.getSample() + oscillatorFifthDetuned.getSample();
      sample *= 0.3f;
      outputChannels[channel][frame] = sample;


      oscillator.tick();
      oscillatorFifth.tick();
      oscillatorFifthDetuned.tick();
    }
  }
}
