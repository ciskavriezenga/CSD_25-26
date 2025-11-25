#ifndef CALLBACK_H
#define CALLBACK_H

#include "audiocomponent.h"
#include "sine.h"
#include "square.h"

class CustomCallback : public AudioCallback {
public:
  CustomCallback (float samplerate);
  void prepare (int rate) override;
  void process (AudioBuffer buffer) override;

private:
  Square oscillator;
  Square oscillatorFifth;
  Square oscillatorFifthDetuned;
};

#endif  //CALLBACK_H
