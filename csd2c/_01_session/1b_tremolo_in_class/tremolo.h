#pragma once

#include <iostream>
#include <sine.h>

class Tremolo
{
public:
  Tremolo(float modDepth = 1.0f);
  ~Tremolo();

  void prepare(float samplerate);
  void processFrame(const float& input, float& output);
  void setModDepth(const float modDepth);
private:
  float modDepth;
  Sine sine;
};
