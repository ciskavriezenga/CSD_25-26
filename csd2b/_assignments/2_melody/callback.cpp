#include "callback.h"

Callback::Callback(float samplerate) : AudioCallback(samplerate), samplerate(samplerate) {}

void Callback::prepare (int samplerate)  {
  this->samplerate = samplerate;
  updatePitch(melody, square);
}

void Callback::process(AudioBuffer buffer)  {
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0; channel < numOutputChannels; ++channel) {
    for (int frame = 0; frame < numFrames; ++frame) {
      outputChannels[channel][frame] = square.getSample() * amplitude;
      square.tick();

      /* After every sample, check if we need to advance to the next note
	     * This is a bit awkward in this scheme of buffers per channel
	     *  In a multichannel setting we should update pitches independently per channel!
	     */
      if (frameCount >= noteDelayFactor * samplerate) {
        frameCount = 0;
        updatePitch (melody, square);
      } else {
        frameCount++;
      }
    }
  }
}


// NOTE - this function should be part of the Synth or utility class
double Callback::mtof (float mPitch){
  return 440.0 * pow (2.0, (mPitch - 69.0f) / 12.0f);
}

void Callback::updatePitch (Melody& melody, Square& square) {
  float note = melody.getNote();
  double freq = mtof (note);
  std::cout << "next note: " << note << ", has frequency " << freq
            << std::endl;
  square.setFrequency (freq);
}