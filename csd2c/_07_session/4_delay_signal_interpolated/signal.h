//
// Created by Ciska Vriezenga on 26/05/2025.
//

#ifndef SIGNAL_H
#define SIGNAL_H


class Signal {
public:
  Signal();
  virtual ~Signal();

  void prepare(float samplerate);

  virtual float getNextSample() = 0;
  float getSample();

protected:
  float m_sample;
  float m_samplerate;
  //private:


};

#endif //SIGNAL_H
