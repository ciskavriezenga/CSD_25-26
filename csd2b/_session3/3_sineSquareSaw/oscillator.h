#ifndef _Oscillator_H_
#define _Oscillator_H_
#include <iostream>

class Oscillator {
public:
  Oscillator (float frequency = 0, float samplerate = 44100);
  ~Oscillator();

  // go to next sample
  void tick();

  //getters and setters
  //return the current sample
  float getSample();
  // allow to set samplerate after initialization
  void setSamplerate (float samplerate);
  void setFrequency (float frequency);
  float getFrequency();

protected:
  virtual void calculate() = 0;
  float amplitude;
  float phase;

  // sample contains the current sample
  float sample;

private:
  float frequency;
  float samplerate;
};

#endif
