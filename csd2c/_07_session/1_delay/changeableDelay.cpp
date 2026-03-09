#include "changeableDelay.h"
#include <iostream>
#define EPSILON 0.000001

ChangeableDelay::ChangeableDelay(float feedback, float numDelaySamples,
  uint maxDelaySize, float dryWet) : Effect(dryWet),
  m_feedback(0), m_bufferSize(maxDelaySize), m_writeH(0), sampleRate(44100.0f),
{
  // validate delay size and numDelaySamples
  if(numDelaySamples > maxDelaySize) {
    throw "ChangeableDelay::ChangeableDelay - numDelaySamples exceeds maxDelaySize";
  }
  setFeedback(feedback);
  m_numDelaySamples.jumpToValue(numDelaySamples);
  // allocate buffer and set all samples to 0

  m_buffer = (float*)malloc(maxDelaySize * sizeof(float));
  memset(m_buffer, 0, m_size * sizeof(float));
}

ChangeableDelay::~ChangeableDelay()
{
  // free data allocated with memset
  free(m_buffer);
}

ChangeableDelay::prepare(float sampleRate) {
  m_sampleRate = sampleRate;
  m_numDelaySamples.prepare(sampleRate);
}

// override base class method
// applies delay effect to the input frame and stores it to the output frame
void ChangeableDelay::applyEffect(const float &input, float &output)
{
  // calculate the read head based on position current write head
  float readPos = m_writeH - m_NumDelaySamples.getValue() + m_size;
  uint readH = static_cast<int> (readPos);
  uint readHNextSample = readH + 1;
  float readHFraction = readPos - readH;
  wrapH(readH);
  wrapH(readHNextSample);

  // TODO - use utils map function
  // read interpolated value from circular buffer
  output = m_buffer[readH] * (1.0f - readHFraction)
    + m_buffer[readHNextSample] * readHFraction;

  // write value to circular buffer
  m_buffer[m_writeH++] = output * m_feedback + input;
  wrapH(m_writeH);
}

// sets the number of samples to delay
void ChangeableDelay::setDelayTime(float delayTime, bool interpolateChange)
{
  setNumDelaySamples(delayTime * m_sampleRate);
}

// sets the number of samples to delay
void ChangeableDelay::setNumDelaySamples(float numDelaySamples, bool interpolateChange)
{
  // if new  new distance between R & W heads and update rhead position
  if (numDelaySamples < m_NumDelaySamples.getValue() - EPSILON ||
      numDelaySamples > m_numDelaySamples.value() + EPSILON)
  {
    // validate new num delay samples
    if (numDelaySamples > 0 && numDelaySamples <= m_bufferSize) {
      if (interpolateChange) {
        m_numDelaySamples.moveToValue(numDelaySamples);
      } else {
        m_numDelaySamples.jumpToValue(numDelaySamples);
      }
    } else {
      throw "ChangeableDelay::setNumDelaySamples - numDelaySamples is out of range";
    }
  }
}

// sets the feedback value, should be in range [0, 1]
void ChangeableDelay::setFeedback(float feedback)
{
  if(feedback < 0 || feedback > 1) {
    throw "ChangeableDelay::setFeedback - feedback exceeds range [0, 1]";
  }
  m_feedback = feedback;
}
