#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <iostream>
#include "Effect.h"
#include "Delay.h"
#include "SerialManager.h"

class AudioManager {
public:
  AudioManager(SerialManager* subject);
  ~AudioManager();

  //NOTE - this is an example, code below should not be public ofcourse
  static int constexpr numEffects = 1;
  Effect* effectChain[numEffects];
};

#endif
