#include "callback.h"

CustomCallback::CustomCallback (float samplerate)
  : AudioCallback (samplerate), carrier (0.0f, samplerate), modulator (0.0f, samplerate) {
}

void CustomCallback::prepare (int samplerate) {
  carrier.setSamplerate (samplerate);
  modulator.setSamplerate (samplerate);
  melody.prepare(samplerate);
  updateFrequency();
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

      float modSignal = modulator.getSample();
      float modulatedFreq = carrierFrequency * (modSignal * modulationIndex);
      modulatedFreq += carrierFrequency;
      carrier.setFrequency(modulatedFreq);


      outputChannels[channel][frame] = carrier.getSample();
      carrier.tick();
      modulator.tick();



      // melody.tick returns true when a new note is reached
      if (melody.tick())
      {
        updateFrequency();
      }
    }
  }
}


void CustomCallback::updateFrequency()
{
  /* NOTE: retrieving a copy of note, would be better to use a pointer,
        * but usage of pointers is out of scope for now.
        */
  Note note = melody.getCurrentNote();
  carrierFrequency = note.getPitch();
  float modulatorFreq = carrierFrequency / modulationIndex;
  modulator.setFrequency(modulatorFreq);
}
