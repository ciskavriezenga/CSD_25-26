#include "tremolo.h"

Tremolo::Tremolo(float modDepth)
{
  // use setter instead of initialiser list to ensure value falls in range
  setModDepth(modDepth);
}

Tremolo::~Tremolo()
{}

void Tremolo::prepare(float samplerate)
{
  sine.prepare(samplerate);
  sine.setFrequency(5.0f);
}

void Tremolo::processFrame(const float& input, float& output)
{
  // calculate frame's current modulation value, scaled with modDepth
  float modSignal = (sine.getSample() + 1.0f) * 0.5f;
  modSignal *= modDepth;
  // apply modulation
  output = input * (1.0f - modDepth) + input * modSignal;
  sine.tick();
}

void Tremolo::setModDepth(const float modDepth) {
  if(modDepth >= 0.0f && modDepth <= 1.0f) {
    this->modDepth = modDepth;
  } else {
    this->modDepth = 0.0f;
    // TODO - throw error
  }
}