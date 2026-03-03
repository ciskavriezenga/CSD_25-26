//
// Created by Ciska Vriezenga on 26/05/2025.
//

#include "line.h"

#include <iostream>
#include <ostream>
#define EPSILON 0.001f
Line::Line() : m_active(false), m_phase (0.0f),
m_phaseIncrement(0.0f), m_slope(0) {}

Line::~Line() {}

void Line::changeToValue(float targetValue, float lineDurationMs, bool setDirectly) {
  // TODO - add validation for targetValue

  // TODO - check what happens for lineDurationMS == 0


  // TODO - split up in two private methods ??
  if (setDirectly) {
    m_sample = targetValue;
  } else {
    std::cout << "current value: " << m_sample << std::endl;
    std::cout << "target value: " << targetValue << std::endl;
    std::cout << "line duration: " << lineDurationMs << std::endl;
    // cache current sample as start value
    m_startValue = m_sample;

    // reset phase
    m_phase = 0.0f;
    m_phaseIncrement = 1.0f / (m_samplerate * lineDurationMs);
    m_slope = targetValue - m_sample;

    // start change delay time
    m_active = true;
  }
}

float Line::tick() {
  // If line is 'running' / interpolating
  if (m_active) {
    //increment phase
    m_phase += m_phaseIncrement;

    //check if phase exceeds end
    if (m_phase > 1.0f - EPSILON) {
      // we are done
      m_active = false;
    }
    // calculate the new sample
    calculateSample ();
  }
  // TODO - implement
  return m_sample;
}

void Line::calculateSample() {
  m_sample = m_startValue + m_phase * m_slope;
}