#include "Delay.h"

Delay::Delay(SerialManager* subject) : Effect(subject) {};

void Delay::process(/*float* buffer, int numFrames*/) {
  std::cout << "\n_____ Delay - inside process method\n";
}

void Delay::setDelayTimeMS(float delayTimeMS) {
  /*NOTE - audio callback runs on a different thread, this is only example code.
   * In a real project be aware of possibles issues related to multiple threads,
   * when altering 'delayInSamples' value.
   */
   std::cout << "\n_____ Delay - inside setDelayTimesMS method - \n" <<
                "passed delay time in ms. = " <<
                delayTimeMS << std::endl;

  //check if delay time does not exceed max delay time
  if(delayTimeMS < maxDelayTimeMS) {
    //NOTE - lazy example: floor instead of rounded value - <int>
    delayInSamples = static_cast<int> (delayTimeMS / 1000.0 * SAMPLERATE);
    std::cout <<  "* new delay time in Samples = " <<
                  delayInSamples << std::endl;
  }

}

void Delay::update(Subject* subject) {
  std::cout << "\n_____ Delay - inside update method - \n";
  //retrieve and set drywet value
  dryWet = _subject->getEffectValues(EffectValueTypes::DelayDryWet);
  //retrieve and set amp value
  amp = _subject->getEffectValues(EffectValueTypes::DelayAmp);
  //retrieve and set delayTime value
  setDelayTimeMS(_subject->getEffectValues(EffectValueTypes::DelayTimeMS));
}
