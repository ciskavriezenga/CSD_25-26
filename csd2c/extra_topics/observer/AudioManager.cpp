#include "AudioManager.h"

AudioManager::AudioManager(SerialManager* subject) {
  //create effects and add these to effectChain
  effectChain[0] = new Delay(subject);
}


AudioManager::~AudioManager() {
  delete effectChain[0];
  effectChain[0] = nullptr;
}
