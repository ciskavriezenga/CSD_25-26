#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>

class Square
{
public:
  //Constructor and destructor
  Square(double frequency = 220.0f, double samplerate = 44100.0f);
  ~Square();
  void prepare(int samplerate);
  //return the current sample
  double getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(double frequency);
  double getFrequency();

private:
  double frequency;
  double amplitude;
  double phase;
  // sample contains the current sample
  double sample;
  double samplerate;
};

#endif
