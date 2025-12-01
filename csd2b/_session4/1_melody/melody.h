#pragma once

#include <iostream>
#include "note.h"

#define NUM_NOTES 6

class Melody
{
public:
  Melody();
  ~Melody();

  void prepare(int samplerate);
  // returns true if the melodyChanged
  // NOTE: this would be nicer with e.g. observer pattern, but out of scope.
  bool tick();

  // setters and getters
  Note getCurrentNote();




private:
  void updateCurrentNoteFrameDur();
  // Cmaj7 -  arpeggio, fixed for now, for the sake of the example
  Note melody[NUM_NOTES] = {
    Note(60, 1.0f), Note(64, 0.5f), Note(67, 0.25f),
    Note(71, 0.25f), Note(67, 0.25f), Note(64, 0.25f)
  };

  int currentNoteFrameDuration;

  // using a constant value 120 for now, can be made adaptable
  const float bpm = 120.0f;
  // the duration of a quarternote in frames given the bpm
  // using a float, rounding when transforming the note frame dur to integer
  float quarterNoteFrameDur;
  // the index of the current note - readIndex
  int noteIndex = 0;
  int frameIndex = 0;
};






