#include "Subject.h"

Subject::Subject() {}

Subject::~Subject() {}

void Subject::attach(Observer* observer){
  _observers.emplace_front(observer);
}

void Subject::detach(Observer* observer){
  _observers.remove(observer);
}

void Subject::notify(){
  for(std::list<Observer*>::iterator it=_observers.begin(); it!=_observers.end(); ++it) {
    (*it)->update(this);
  }
}
