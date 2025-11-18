#include <iostream>

class Oscillator {
public:
  Oscillator();
  Oscillator(float frequency);
  ~Oscillator();
  float getFrequency();
  void setFrequency(float frequency);

protected:

private:
  float freq;
};


// delegating constructor
Oscillator::Oscillator() : Oscillator(220) // default frequency
{
  std::cout << "Inside Oscillator constructor ()\n";
}

Oscillator::Oscillator(float frequency) : freq(frequency)
{
  std::cout << "Inside Oscillator constructor (frequency)\n";
}

Oscillator::~Oscillator()
{
  std::cout << "Inside Oscillator destructor\n";
}

float Oscillator::getFrequency()
{
  return freq;
}

void Oscillator::setFrequency(float frequency)
{
  // TODO - VALIDATION!!!!
  freq = frequency;
}




int main ()
{
  std::cout << "\nin main\n";
  Oscillator osc;
  osc.setFrequency(1000);
  std::cout << "02_oscillator's frequency: " << osc.getFrequency() << "\n";

  return 0;
}
