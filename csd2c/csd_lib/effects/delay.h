#pragma once
#include "effect.h"

typedef unsigned int uint;

class Delay : public Effect
{
public:
  Delay(float feedback = 0.5, uint numDelaySamples = 22050,
    uint maxDelaySize = 44100, float dryWet = 0.5);
  ~Delay();

  // override base class method
  // applies delay effect to the input frame and stores it to the output frame
  void applyEffect(const float &input, float &output) override;

  // sets the number of samples to delay
  void setNumDelaySamples(uint numDelaySamples);
  // sets the feedback value, should be in range [0, 1]
  void setFeedback(float feedback);
private:
  inline void wrapH(uint& head) {
    if (head >= m_size) head -= m_size;
  }

  float m_feedback = 0.0f;

  // circular buffer variables
  // pointer to the buffer
  float* m_buffer;
  // num samples to delay
  uint m_numDelaySamples;
  // buffer size
  uint m_size;
  // read and write heads, delay size
  uint m_readH;
  uint m_writeH;
};
