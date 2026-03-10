#pragma once
#include "effect.h"
#include "line.h"
#include <atomic>

typedef unsigned int uint;

class ChangeableDelay : public Effect
{
public:
  ChangeableDelay(float feedback = 0.25, float numDelayFrames = 44100,
    uint maxDelaySize = 88202, float dryWet = 1.0);
  ~ChangeableDelay();

  // override base class method
  // applies delay effect to the input frame and stores it to the output frame
  void applyEffect(const float &input, float &output) override;

  void prepare(float sampleRate) override;
  // sets the number of samples to delay,
  // with interpolateChange true the delay head is smoothly moved towards the new
  // delay time
  void setDelayTime(float delayTime, bool interpolateChange = true);
  float getDelayTime();
  void setNumDelayFrames(float numDelayFrames, bool interpolateChange = true);
  // sets the feedback value, should be in range [0, 1]
  void setFeedback(float feedback);
private:
  inline void wrapH(uint& head) {
    if (head >= m_bufferSize) head -= m_bufferSize;
  }

  float m_feedback = 0.0f;

  // circular buffer variables
  // pointer to the buffer
  float* m_buffer;
  // num frames to delay as Line object to enforce smearing changes and preventing ticks
  Line m_numDelayFrames;

  // buffer size
  uint m_bufferSize;

  // write head
  uint m_writeH;

  float m_sampleRate;
};
