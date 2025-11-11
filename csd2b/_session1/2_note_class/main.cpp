#include <iostream>

/*
 * class - implementation steps
 * 1. define the class
 * 2. define the constructor
 * 3. implement the constructor
 * 4. add fields / methods (and define the methods)
 */

class Note {
public:
  Note() {
    std::cout << "\nNote constructor.\n";
  }

  int getMidiValue() {
    return midiValue;
  }

  int midiValue = 120;
};

int main() {
  Note note1;
  std::cout << "\nRetrieving the note frequency, freq is: " << note1.midiValue;
  std::cout << "\nReached the end of the application.\n";
}
