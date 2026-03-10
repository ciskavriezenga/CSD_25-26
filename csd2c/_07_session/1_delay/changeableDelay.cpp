#include "changeableDelay.h"
#include <iostream>
#define EPSILON 0.000001

ChangeableDelay::ChangeableDelay(float feedback, float numDelayFrames,
  uint maxDelaySize, float dryWet) : Effect(dryWet),
  m_feedback(feedback), m_bufferSize(maxDelaySize), m_writeH(0), m_sampleRate(44100.0f)
{
  // validate delay size and numDelayFrames
  if(numDelayFrames > maxDelaySize) {
    throw "ChangeableDelay::ChangeableDelay - numDelayFrames exceeds maxDelaySize";
  }
  setFeedback(feedback);
  m_numDelayFrames.jumpToValue(numDelayFrames);
  // allocate buffer and set all samples to 0

  m_buffer = (float*)malloc(maxDelaySize * sizeof(float));
  memset(m_buffer, 0, m_bufferSize * sizeof(float));
}

ChangeableDelay::~ChangeableDelay()
{
  // free data allocated with memset
  free(m_buffer);
}

void ChangeableDelay::prepare(float sampleRate) {
  m_sampleRate = sampleRate;
  m_numDelayFrames.prepare(sampleRate);
}

// override base class method
// applies delay effect to the input frame and stores it to the output frame
void ChangeableDelay::applyEffect(const float &input, float &output)
{
  float cacheInput = input;

  // calculate the read head based on position current write head
  float readPos = m_writeH - m_numDelayFrames.getNextValue() + m_bufferSize;
  uint readH = static_cast<int> (readPos);
  uint readHNextSample = readH + 1;
  float readHFraction = readPos - readH;
  wrapH(readH);
  wrapH(readHNextSample);

  // TODO - use utils map function
  // read interpolated value from circular buffer
  output = m_buffer[readH] * (1.0f - readHFraction) + m_buffer[readHNextSample] * readHFraction;

  // write value to circular buffer
  m_buffer[m_writeH++] = output * m_feedback + cacheInput;
  wrapH(m_writeH);
}

// sets the number of samples to delay
void ChangeableDelay::setDelayTime(float delayTime, bool interpolateChange)
{
  std::cout << "ChangeableDelay.setDelayTime, new delayTime: " << delayTime << std::endl;
  setNumDelayFrames(delayTime * m_sampleRate);
}

float ChangeableDelay::getDelayTime()
{
  return m_numDelayFrames.getValue() / m_sampleRate;
}

// sets the number of frames to delay
void ChangeableDelay::setNumDelayFrames(float numDelayFrames, bool interpolateChange)
{
  // if new  new distance between R & W heads and update rhead position
  if (numDelayFrames < m_numDelayFrames.getValue() - EPSILON ||
      numDelayFrames > m_numDelayFrames.getValue() + EPSILON)
  {

    // validate new num delay samples
    if (numDelayFrames > 0 && numDelayFrames <= m_bufferSize) {
      std::cout << "ChangeableDelay::m_numDelayFrames - setting new delay frames: "<< numDelayFrames << std::endl;
      std::cout << "ChangeableDelay::m_numDelayFrames - interpolateChange: "<< interpolateChange << std::endl;
      if (interpolateChange) {
        m_numDelayFrames.moveToValue(numDelayFrames, 1.0f);
        std::cout << "ChangeableDelay::m_numDelayFrames - calling moveToValue" << std::endl;
      } else {
        m_numDelayFrames.jumpToValue(numDelayFrames);
      }
    } else {
      throw "ChangeableDelay::m_numDelayFrames - numDelayFrames is out of range";
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
