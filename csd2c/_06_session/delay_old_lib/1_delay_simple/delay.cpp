#include "delay.h"
#include <iostream>
#define MAX_CHANGE_STEP 3

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
  setNumDelaySamples(numDelaySamples);
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
  if (m_changeDelayTime) {
    int deltaSamples = m_targetNumDelaySamples - m_numDelaySamples;
    if (deltaSamples > 0 && deltaSamples > MAX_CHANGE_STEP) {
      deltaSamples = MAX_CHANGE_STEP;
    } else if (deltaSamples < 0 && deltaSamples < -MAX_CHANGE_STEP) {
      deltaSamples = -MAX_CHANGE_STEP;
    } else {
      // reached the target samples after end method
      m_changeDelayTime = false;
    }
    m_numDelaySamples += deltaSamples;
  }
  // calculate the read head based on position current write head
  uint readH = m_writeH - m_numDelaySamples + m_size;
  wrapH(readH);
  // read value from circular buffer and increment readH
  output = m_buffer[readH];
  // write value to circular buffer
  m_buffer[m_writeH++] = output * m_feedback + input;
  wrapH(m_writeH);
}

// sets the number of samples to delay
void Delay::setNumDelaySamples(uint numDelaySamples)
{
  // store new distance between R & W heads and update rhead position
  if (numDelaySamples != m_numDelaySamples)
  {
    // validate new num delay samples
    if (numDelaySamples > 0 && numDelaySamples <= m_size) {
      m_changeDelayTime = true;
      std::cout << "numDelaySamples: " << numDelaySamples << std::endl;
      m_targetNumDelaySamples = numDelaySamples;
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
