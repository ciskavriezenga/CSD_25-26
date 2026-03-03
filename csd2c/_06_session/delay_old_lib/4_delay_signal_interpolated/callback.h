#ifndef CALLBACK_H
#define CALLBACK_H

#include <audiocomponent.h>
#include "delay.h"
#include "sine.h"

class CustomCallback : public AudioCallback {
public:
  CustomCallback (float sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;
  void setNumDelaySamples(int numDelaySamples);

private:
  float samplerate = 44100;
  Delay delay;
  Sine sine{220};
};

#endif //CALLBACK_H
