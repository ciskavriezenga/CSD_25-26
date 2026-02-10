#ifndef DELAY_H
#define DELAY_H

#include "Effect.h"

class Delay : public Effect {
public:
  Delay(SerialManager* subject);
  void process(/*float* buffer, int numFrames*/);
  //override Observer update method
  void update(Subject* subject);

  //set the delay time in miliseconds
  void setDelayTimeMS(float delayTimeMS);

  //NOTE: example code - code below should not be public
  static int constexpr maxDelaySamples = 44100;
  static float constexpr maxDelayTimeMS = maxDelaySamples / SAMPLERATE * 1000.0;
  float delayBuffer[maxDelaySamples];
  int delayInSamples;
};

#endif
