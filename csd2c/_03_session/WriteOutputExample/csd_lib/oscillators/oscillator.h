#pragma once
#include <math.h>
#include <iostream>

class Oscillator
{
public:
  Oscillator(float frequency, float samplerate);
  Oscillator(float frequency);
  virtual ~Oscillator();

  void prepare(float samplerate);

  // generates and returns the next sample
  float tick();

  // --- getters and setters ---
  // returns the current sample
  float getSample();
  void setFrequency(float frequency);
  float getFrequency();

protected:
  virtual void calcNextSample() = 0;
  float frequency;
  float phase;
// sample contains the current sample
  float sample;

private:
  float amplitude;
  float samplerate = 44100;
};
