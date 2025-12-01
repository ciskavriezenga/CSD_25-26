//
// Created by Ciska Vriezenga on 01/12/2025.
//

#ifndef NOTE_H
#define NOTE_H
//TODO - include math instead of juce for usage of pow function
#include "juce_audio_basics/juce_audio_basics.h"
#include "juce_audio_devices/juce_audio_devices.h"


class Note {
public:
  // Detune is not supported, if required, add 'cents'
  Note(int midiNoteNumber, float quarterNoteDuration = 1.0f);

  int getMidiNoteNumber();
  float getQuarterNoteDuration();
  float getPitch();

  static float mtof(int midiNoteNumber);


private:
  int midiNoteNumber;
  float quarterNoteDuration;
};



#endif //NOTE_H
