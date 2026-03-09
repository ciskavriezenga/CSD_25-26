#pragma once
#include "effect.h"
#include "line.h"
#include <atomic>

typedef unsigned int uint;

class ChangeableDelay : public Effect
{
public:
  ChangeableDelay(float feedback = 0.7, float numDelaySamples = 44100,
    uint maxDelaySize = 44101, float dryWet = 1.0);
  ~ChangeableDelay();

  // override base class method
  // applies delay effect to the input frame and stores it to the output frame
  void applyEffect(const float &input, float &output) override;

  void prepare(float sampleRate) override;
  // sets the number of samples to delay,
  // with interpolateChange true the delay head is smoothly moved towards the new
  // delay time
  void setDelayTime(float delayTime, bool interpolateChange = true);
  void setNumDelaySamples(float numDelaySamples, bool interpolateChange = true);
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
  // num samples to delay as Line object to enforce smearing changes and preventing ticks
  Line m_NumDelaySamples;

  // buffer size
  uint m_bufferSize;

  // write head
  uint m_writeH;

  float m_sampleRate;
};
