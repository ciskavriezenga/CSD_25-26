//
// Created by Ciska Vriezenga on 26/05/2025.
//

#include "signal.h"

Signal::Signal() : m_value(0.0f), m_sampleRate(48000) {

}

Signal::~Signal() {

}

void Signal::prepare(float sampleRate) {
  m_sampleRate = sampleRate;
}

float Signal::getValue()
{
  return m_value;
}

