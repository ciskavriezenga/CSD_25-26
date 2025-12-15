#include "recap.h"

int Recap::objectCount = 0;

Recap::Recap()
{
    std::cout << "Recap constructor\n";
    std::cout << "SCOPE is " << SCOPE << std::endl;
    objectCount++;
}

Recap::~Recap()
{
    std::cout << "Recap destructor\n";
    objectCount--;
}

void Recap::printObjectCount()
{
    std::cout << "Number of objects of this class: " << objectCount << std::endl;
}

