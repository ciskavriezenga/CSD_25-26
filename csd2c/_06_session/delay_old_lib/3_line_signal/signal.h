//
// Created by Ciska Vriezenga on 26/05/2025.
//

#ifndef SIGNAL_H
#define SIGNAL_H


class Signal {
public:
  Signal();
  virtual ~Signal();

  // not pure virtual, since not all subclasses require the samplerate
  virtual void prepare(float samplerate) {};

  virtual float tick() = 0;
  float getSample();

protected:
  float m_sample;

  //private:
};

#endif //SIGNAL_H
