
# Code Clinic 2.

## CC2 - Interpolatie
* functionaliteit
  https://en.wikipedia.org/wiki/Interpolation
  https://en.wikipedia.org/wiki/Linear_interpolation
  _en zie afbeelding_
* wanneer nodig in M&T context?

## CC2 - Opdracht
Maak een static Interpolation class met de volgende functies, gebruik hierbij floats als datatype:
* `nnMap(value, low, high)`
  _returns the nearest-neighbour value of the passed value within the given range_
    * value: a normalized value within range [0, 1]
    * low: the lower bound of the range
    * high: the upper bound of the range

* `linMap(value, low, high)`
  _returns the linearly interpolated value of the passed value within the given range_
    * value: a normalized value within range [0, 1]
    * low: the lower bound of the range
    * high: the upper bound of the range

* `mapInRange(value, fromLow, fromHigh, toLow, toHigh)`
  _returns the mapped value from one range to another_
    * fromLow: the lower bound of the value’s current range.
    * fromHigh: the upper bound of the value’s current range.
    * toLow: the lower bound of the value’s target range.
    * toHigh: the upper bound of the value’s target range.


##### *Voor diehards*
* Maak een WavetableOscillator class die erft van Oscillator (blok2b) en 
een circular buffer bevat(losse class of functionaliteit) gevuld met 
samples voor de te genereren golfvorm. Je kunt hiervoor de static class 
WavetableGenerator gebruiken en aanvullen, zie map *wavetable*. 
Bij het genereren van waardes met je WavetableOscillator kun je de linMap 
interpolatie functie uit je static Interpolation class toepassen om waardes 
uit de wavetable te lezen.

* Werk met templates ipv float datatypes, zodat je ongeacht je data type 
(float, double, ...) de functies kunt gebruiken. 
https://en.cppreference.com/w/cpp/language/templates


