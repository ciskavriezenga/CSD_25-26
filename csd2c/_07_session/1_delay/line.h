//
// Created by Ciska Vriezenga on 26/05/2025.
//

#ifndef LINE_H
#define LINE_H
#include "signal.h"
#include <atomic>

class Line : public Signal {
public:
  Line();
  virtual ~Line();
  float getNextSample() override;

  // directly set the new value
  void jumpToValue(float value);
  // smoothly transition to the new value
  void moveToValue(float value, float lineDurationMs = 0.01f);

protected:
  void calculateValue();

  std::atomic<bool> m_active;
  std::atomic<float> m_startValue;
  std::atomic<float> m_phase;
  std::atomic<float> m_phaseIncrement;
  std::atomic<float> m_slope;

};

#endif //LINE_H
