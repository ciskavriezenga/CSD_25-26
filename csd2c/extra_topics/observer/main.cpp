#include <iostream>
#include "AudioManager.h"
#include "SerialManager.h"
int main() {
  std::cout << "\nCreating a SerialManager object.\n";
  //create SerialManager
  SerialManager serialManager;

  std::cout << "\nCreating an AudioManager object.\n";
  //create AudioManager object, pass address serialManager =^ subject
  AudioManager audioManager(&serialManager);

  //retrieve Delay object and display the default delay values
  Delay* delay = static_cast <Delay*> (audioManager.effectChain[0]);
  std::cout <<  "\n\nThe delay default values are: " <<
                "\n-dryWet = " << delay->dryWet <<
                "\n-amp = " << delay->amp <<
                "\n-delayInSamples = " << delay->delayInSamples;

  std::cout << "\n\nCalling audioManager demoValuesChanged method.\n";
  //call the demoValuesChangedaudioManager method
  serialManager.demoValuesChanged();

  //display the changed delay values
  std::cout <<  "\n\nThe delay values changed: " <<
                "\n-dryWet = " << delay->dryWet <<
                "\n-amp = " << delay->amp <<
                "\n-delayInSamples = " << delay->delayInSamples;

  //end program
  std::cout << std::endl;
  return 0;
}
