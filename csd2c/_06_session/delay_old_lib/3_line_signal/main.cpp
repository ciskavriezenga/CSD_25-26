#include <iostream>
#include <cmath>
#include <audioToFile.h>
#include "line.h"

int main(int argc, char **argv) {

  WriteToFile writeToFile("line_signal.csv", true);
  Line line;
  std::cout << "Hello world" << std::endl;
  line.changeToValue (-0.5, 0.0f, true);

  int numSamples = 512;
  float sampleRate = 48000.0f;
  float changeDuration = numSamples / sampleRate;
  line.changeToValue (0.5, changeDuration);

  // write line for change duration plus additional samples to verify
  // static value after change duration
  for (int i = 1; i < numSamples * 2; i++) {
    float sample = line.getSample ();
    std::cout << "sample: " << std::to_string(sample) << std::endl;
    writeToFile.write(std::to_string(sample) + "\n");
    line.tick();
  }

  return 0;
} // main()
