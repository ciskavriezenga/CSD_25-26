//
// Created by Ciska Vriezenga on 26/05/2025.
//

#include "line.h"

#include <iostream>
#include <ostream>

Line::Line() : m_active(false), m_phase (0.0f),
               m_phaseIncrement(0.0f), m_slope(0) {}

Line::~Line() {}


void Line::jumpToValue(float value) {
  m_active = false;
}

void Line::moveToValue(float targetValue, float lineDurationMs) {
  // TODO - add validation for targetValue

  // TODO - check what happens for lineDurationMS == 0

  // cache current sample as start value
  m_startValue = m_value;

  // reset phase
  m_phase = 0.0f;
  m_phaseIncrement = 1.0f / (m_sampleRate * lineDurationMs);
  m_slope = targetValue - m_value;
  // start
  m_active = true;
}

float Line::getNextValue() {
  // If line is 'running' / interpolating
  if (m_active) {
    //increment phase
    m_phase += m_phaseIncrement;

    //check if phase exceeds end
    if (m_phase > 1.0) {
      // we are done
      m_active = false;
    }
    // calculate the new value
    calculateValue ();
  }
  // TODO - implement
  return m_value;
}

void Line::calculateValue() {
  m_value = m_startValue + m_phase * m_slope;
}