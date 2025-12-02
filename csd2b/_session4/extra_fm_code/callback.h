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
  void setRatio(float ratio);

private:
  Sine carrier;
  Sine modulator;
  float carrierFrequency;
  float modulationIndex = 2.0f;
  float cmRatioInverse = 2.0f;
  float modulationDeviation = 0.0f;
  Melody melody;
  int frameCounts = 0;
  void updateFrequency();

};

#endif  //CALLBACK_H
