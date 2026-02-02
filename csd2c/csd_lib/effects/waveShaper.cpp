#include "waveShaper.h"
#include <iostream>
#define useWavetable 0
WaveShaper::WaveShaper(float dryWet) : Effect(dryWet) {
#if useWavetable
  WavetableGenerator::generateSCurve(buffer, BUFFER_SIZE, 100.0f);
#endif
}

WaveShaper::~WaveShaper() {}


float WaveShaper::applyEffect(const float input)
{
  float sample = input;
  if(sample > 1.0f)  sample = 1.0f;
  if(sample < -1.0f)  sample = -1.0f;
#if useWavetable
  float indexFloat = WavetableGenerator::map(sample, -1.0f, 1.0f, 0.0f, (float) (BUFFER_SIZE - 1));
  int index = (int) indexFloat;
  // TODO - interpolate
  return buffer[index];
#else
  static float k = 100.0f;
  static float normalizeFactor = 1.0f / atan(k);
  return normalizeFactor * atan(k * input);
#endif

}

