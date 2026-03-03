#pragma once
#include "effect.h"

#include <atomic>

typedef unsigned int uint;

class Delay : public Effect
{
public:
  Delay(float feedback = 0.7, uint numDelaySamples = 44100,
    uint maxDelaySize = 44101, float dryWet = 1.0);
  ~Delay();

  // override base class method
  // applies delay effect to the input frame and stores it to the output frame
  void applyEffect(const float &input, float &output) override;

  // sets the number of samples to delay,
  // with interpolateChange true the delay head is smoothly moved towards the new
  // delay time
  void setNumDelaySamples(uint numDelaySamples, bool interpolateChange = true);
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
  // num samples to delay in floats to also allow reading in between samples
  float m_numDelaySamples;

  // new num samples to delay
  std::atomic<float> m_targetNumDelaySamples;
  std::atomic<bool> m_changeDelayTime;
  std::atomic<float> m_changeDeltaSamples;

  // buffer size
  uint m_size;

  // write head
  uint m_writeH;
};
