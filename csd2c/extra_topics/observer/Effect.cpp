#include "Effect.h"

Effect::Effect(SerialManager* subject) {
  _subject = subject;
  _subject->attach(this);
}


Effect::~Effect() {
  _subject->detach(this);
}
