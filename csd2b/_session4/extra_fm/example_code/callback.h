#ifndef CALLBACK_H
#define CALLBACK_H

#include "audiocomponent.h"
#include "oscillator.h"
#include "sine.h"
#include "square.h"
#include "melody.h"
#include "note.h"

class CustomCallback : public AudioCallback {
public:
  CustomCallback (float samplerate);
  void prepare (int rate) override;
  void process (AudioBuffer buffer) override;

private:
  Sine carrier;
  Sine modulator;
  float carrierFrequency;
  float modulationIndex = 5.5f;
  Melody melody;
  int frameCounts = 0;
  void updateFrequency();

};

#endif  //CALLBACK_H
