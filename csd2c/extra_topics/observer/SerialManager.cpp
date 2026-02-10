#include "SerialManager.h"

void SerialManager::demoValuesChanged() {
  std::cout <<  "\n\n_____ SerialManager - inside demoValueChanged method - "<<
                "please provide new values. \n" <<
                "-delayDryWet ";
  std::cin >> _effectValues.delayDryWet;
  std::cout << "\n-delayAmp ";
  std::cin >> _effectValues.delayAmp;
  std::cout << "\n-delayTimeMS ";
  std::cin >> _effectValues.delayTimeMS;
  std::cout << "\nValuesChanged -> calling notify method!";
  notify();
}

float SerialManager::getEffectValues(EffectValueTypes effectValueType) {
  std::cout <<  "\n\n_____ SerialManager - inside getValues method - " <<
                "passed parameter effectValueType is ";
  switch(effectValueType) {
    case EffectValueTypes::DelayDryWet:
      std::cout << "EffectValueTypes::DelayDryWet";
      return _effectValues.delayDryWet;
    case EffectValueTypes::DelayTimeMS:
      std::cout << "EffectValueTypes::DelayTimeMS";
      return _effectValues.delayTimeMS;
    case EffectValueTypes::DelayAmp:
      std::cout << "EffectValueTypes::DelayAmp";
      return _effectValues.delayAmp;
    default: break;
  };
}
