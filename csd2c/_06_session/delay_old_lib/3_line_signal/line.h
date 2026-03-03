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
  float tick() override;

  void changeToValue(float value, float lineDurationMs = 0.01f, bool setDirectly = false);
protected:
  void calculateSample();

  // indicates if we are changing to a new value
  std::atomic<bool> m_active;
  // the start value from which we move to the new value
  std::atomic<float> m_startValue;
  // phase is used to 
  std::atomic<float> m_phase;
  std::atomic<float> m_phaseIncrement;
  std::atomic<float> m_slope;

};



#endif //LINE_H
