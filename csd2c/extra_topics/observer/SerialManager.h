#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <iostream>
#include "Subject.h"


enum class EffectValueTypes { DelayDryWet, DelayAmp, DelayTimeMS};

struct EffectValues{
  float delayDryWet = 0.0f;
  float delayTimeMS = 0;
  float delayAmp = 0.0f;
};

class SerialManager : public Subject{
public:
  void demoValuesChanged();

  /*
   * NOTE - method below can also be placed in a seperate interface
   * Effect can include this interface class instead of SerialManager.h,
   */
  float getEffectValues(EffectValueTypes effectValueType);

private:
  EffectValues _effectValues;
};

#endif
