#include "melody.h"

Melody::Melody() {}

Melody::~Melody() {}

void Melody::prepare(int samplerate)
{
  quarterNoteFrameDur = 60.0f / bpm * samplerate;
  updateCurrentNoteFrameDur();
}
/*
 * NOTE - returning a copy of current note example,
 * instead, we could return a pointer to the current note.
 */
Note Melody::getCurrentNote()
{
  return melody[noteIndex];
}

bool Melody::tick()
{
  frameIndex++;

  if (frameIndex >= currentNoteFrameDuration)
  {
    // fetch a new note
    noteIndex++;
    // wrap note index back to the beginning if it exceeds the melody array
    if(noteIndex >= NUM_NOTES) {
      noteIndex = 0;
    }
    // cache the frame duration of the new current note
    updateCurrentNoteFrameDur();

    // reset the frameIndex
    frameIndex = 0;
    return true;
  }
  return false;
}

void Melody::updateCurrentNoteFrameDur()
{
  currentNoteFrameDuration =
    melody[noteIndex].getQuarterNoteDuration() * quarterNoteFrameDur;
}


