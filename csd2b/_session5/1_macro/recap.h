#ifndef RECAP_H
#define RECAP_H
#include <iostream>
// recap of static methods

class Recap {
public:
    Recap();
    ~Recap();
    static void printObjectCount();

    static int objectCount;
};


#endif //RECAP_H
