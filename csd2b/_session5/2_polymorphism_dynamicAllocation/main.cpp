#include "saw.h"
#include "sine.h"

/*
 * Simple example of the need for virtual methods
 * We allocate a sine and square object dynamically
 */
#define SELECTED_EXAMPLE 3

int main()
{
#if SELECTED_EXAMPLE == 1 // build example 1

  /*
   * Create the sine and saw objects dynamically with the keyword 'new'
   * This returns a pointer to the sine object, which we can store in
   * a 'class pointer', e.g. a Sine pointer or a Saw pointer
   * a pointer type is indicated with a *, which is simply a convention.
   */
  Sine* sine = new Sine();
  Saw* saw = new Saw();

  /*
   * because the base class calculate method is overridden in both subclasses,
   * the calculate method of the subclass is called, instead of the calculate
   * method of the baseclass.
   */
  sine->calculate();
  saw->calculate();

  /*
   * Now let's store the pointers to the sine and saw objects in an Oscillator
   * pointer!
   */
  Oscillator* sineOscillator = sine;
  Oscillator* sawOscillator = saw;

  /*
   * OOF....! - when we call the calculate method of the sine object with an
   * oscillator pointer ... it will go 'terribly wrong'
   * the calculate function of the baseclass is called, not the subclass method.
   * FIXME add the virtual keyword to the calculate method
   */
  sineOscillator->calculate();
  sawOscillator->calculate();

  // delete dynamically allocated objects
  delete sine;
  sine = nullptr;
  delete saw;
  saw = nullptr;


#elif SELECTED_EXAMPLE == 2 //build example 2
  Oscillator* osc = new Sine();
  osc->calculate();
   /*
   * OOF#2....! - We are allowed to store a pointer to a Sine object in a pointer of the type Oscilllator.
   * however ... when we delete the object with the delete keyword, the destructor of the subclass is not called
   * FIXME add the virtual keyword to the destructor method in the base class
   */

   delete osc;
   osc = nullptr;
#elif SELECTED_EXAMPLE == 3 // build example 3
    /* Text snippet and code below is based on examples from https://cppscripts.com/cpp-null-vs-nullptr
     *      "Introduced in C++11, `nullptr` is a keyword that represents a null pointer,
     *      providing a more clear and type-safe alternative compared to 0 or `NULL`."
     */

    int* ptr1 = NULL;  // NULL representation
    int* ptr2 = nullptr;  // nullptr representation
    int* ptr3 = 0;  // classic method of creating a null ptr

    std::cout << "ptr1 is " << (ptr1 == nullptr ? "null" : "not null") << std::endl;
    std::cout << "ptr2 is " << (ptr2 == nullptr ? "null" : "not null") << std::endl;
    std::cout << "ptr3 is " << (ptr3 == nullptr ? "null" : "not null") << std::endl;

    std::cout << "NULL macro contains: " << NULL << std::endl;





#endif
}
