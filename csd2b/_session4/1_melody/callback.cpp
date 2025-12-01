#include "callback.h"

Callback::Callback(float samplerate) : AudioCallback(samplerate), samplerate(samplerate) {}

void Callback::prepare (int samplerate)  {
  this->samplerate = samplerate;
  melody.prepare(samplerate);
  square.prepare(samplerate);

  // set start frequency
  Note currentNote = melody.getCurrentNote();
  square.setFrequency(currentNote.getPitch());
}

void Callback::process(AudioBuffer buffer)  {
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0; channel < numOutputChannels; ++channel) {
    for (int sample = 0; sample < numFrames; ++sample) {
      outputChannels[channel][sample] = square.getSample() * amplitude;
      square.tick();

      // melody.tick returns true when a new note is reached
      if (melody.tick())
      {
        /* NOTE: retrieving a copy of note, would be better to use a pointer,
         * but usage of pointers is out of scope for now.
         */
        Note note = melody.getCurrentNote();
        square.setFrequency(note.getPitch());
      }
    }
  }
}
