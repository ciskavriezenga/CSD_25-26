//
// Created by Ciska Vriezenga on 26/05/2025.
//

#include "signal.h"

Signal::Signal() : m_sample(0.0f), m_samplerate(48000) {

}

Signal::~Signal() {

}

void Signal::prepare(float samplerate) {
  m_samplerate = samplerate;
}

float Signal::getSample()
{
  return m_sample;
}

