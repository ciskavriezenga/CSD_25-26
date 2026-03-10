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
  void prepare(float sampleRate);

  virtual float getNextValue() = 0;
  float getValue();

protected:
  float m_value;
  float m_sampleRate;
  //private:


};

#endif //SIGNAL_H
