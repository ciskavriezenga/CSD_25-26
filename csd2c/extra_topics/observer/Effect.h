#ifndef EFFECT_H
#define EFFECT_H

#include <iostream>
#include "Observer.h"
#include "SerialManager.h"

#define SAMPLERATE 44100.0f

class Effect : public Observer{
public:
  virtual ~Effect();
  virtual void process(/*float* buffer, int numFrames*/) = 0;
  //NOTE: example code - drywet and amp should not be public
  float dryWet = 0.0f;
  float amp = 1.0f;
protected:
  Effect(SerialManager* subject);
  SerialManager* _subject;
};

#endif
