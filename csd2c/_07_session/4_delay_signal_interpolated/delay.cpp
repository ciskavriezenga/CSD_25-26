#include "delay.h"
#include <iostream>

// using static values for the maximum delta size and  macros for the
// sake of simplicity in this example
#define MAX_CHANGE_STEP 3
#define CHANGE_DURATION 11025

Delay::Delay(float feedback, uint numDelaySamples,
  uint maxDelaySize, float dryWet) : Effect(dryWet),
  m_feedback(0), m_numDelaySamples(0),
  m_targetNumDelaySamples (0), m_changeDelayTime (false),
  m_size(maxDelaySize), m_writeH(0)
{
  // validate delay size and numDelaySamples
  if(numDelaySamples > maxDelaySize) {
    throw "Delay::Delay - numDelaySamples exceeds maxDelaySize";
  }
  setFeedback(feedback);
  setNumDelaySamples(numDelaySamples, false);
  // allocate buffer and set all samples to 0

  m_buffer = (float*)malloc(maxDelaySize * sizeof(float));
  memset(m_buffer, 0, m_size * sizeof(float));
}

Delay::~Delay()
{
  // free data allocated with memset
  free(m_buffer);
}


// override base class method
// applies delay effect to the input frame and stores it to the output frame
void Delay::applyEffect(const float &input, float &output)
{
  if (m_changeDelayTime ) {
    m_numDelaySamples += m_changeDeltaSamples;

    float deltaTarget = m_targetNumDelaySamples - m_numDelaySamples;

    if (abs(deltaTarget) < m_changeDeltaSamples) {
      m_numDelaySamples = m_targetNumDelaySamples;
      m_changeDelayTime = false;
    }
  }
  // calculate the read head based on position current write head
  float readPos = m_writeH - m_numDelaySamples + m_size;
  uint readH = static_cast<int> (readPos);
  uint readHNextSample = readH + 1;
  float readHFraction = readPos - readH;
  wrapH(readH);
  wrapH(readHNextSample);

  // read interpolated value from circular buffer
  output = m_buffer[readH] * (1.0f - readHFraction)
    + m_buffer[readHNextSample] * readHFraction;

  // write value to circular buffer
  m_buffer[m_writeH++] = output * m_feedback + input;
  wrapH(m_writeH);
}

// sets the number of samples to delay
void Delay::setNumDelaySamples(uint numDelaySamples, bool interpolateChange)
{
  // store new distance between R & W heads and update rhead position
  if (numDelaySamples != m_numDelaySamples)
  {
    // validate new num delay samples
    if (numDelaySamples > 0 && numDelaySamples <= m_size) {
      if (interpolateChange) {
        m_changeDelayTime = true;
        m_targetNumDelaySamples = numDelaySamples;
        m_changeDeltaSamples = (m_targetNumDelaySamples - m_numDelaySamples)
          / CHANGE_DURATION;

        std::cout << "______________________________" << std::endl;
        std::cout << "New num delay samples: " << numDelaySamples << std::endl;
        std::cout << "Current m_numDelaySamples: " << m_numDelaySamples << std::endl;
        std::cout << "m_changeDeltaSamples: " << m_changeDeltaSamples << std::endl;

        if (abs(m_changeDeltaSamples) > MAX_CHANGE_STEP) {
          m_changeDeltaSamples =
            (m_changeDeltaSamples < 0) ? -MAX_CHANGE_STEP : MAX_CHANGE_STEP;
        }
      } else {
        m_numDelaySamples = numDelaySamples;
      }
    } else {
      throw "Delay::setNumDelaySamples - numDelaySamples is out of range";
    }
  }
}

// sets the feedback value, should be in range [0, 1]
void Delay::setFeedback(float feedback)
{
  if(feedback < 0 || feedback > 1) {
    throw "Delay::setFeedback - feedback exceeds range [0, 1]";
  }
  m_feedback = feedback;
}
