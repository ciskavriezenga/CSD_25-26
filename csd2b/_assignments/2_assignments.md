# Session 2 - assignments


## 1. Leerdoelen en design
```c++
if(peerReviewScore <= 5) {
    redo = true;
}
```

**_Zie 1_leerdoelen_design.md_**

= Final deliverable, _DEADLINE: Practicum 3_

**!!!! Zie 2_audio_flow_and_pseudo_code.md"** met voorbeelden van zowel audio flow
diagrammen als pseudo code. Let op: deze include afbeeldingen, dus even in
markdown preview bekijken.

<br></br>

- **Constructor delegation**
  - Lees over **constructor delegation** https://www.tutorialspoint.com/cplusplus/cpp_delegating_constructors.htm
  - Voer het voorbeeld _1_oscillator_final_ uit en bekijk de flow, welke constructor wordt het eerst aangeroepen?
- **Initializer list**
  - Lees over **initializer list** (initialization / initializer list worden beide gebruikt) https://www.tutorialspoint.com/cplusplus/cpp_constructor_initialization_list.htm
  - Waarom zou je een initializer list gebruiken in plaats van de body van de constructor?
  - Kun je een reden bedenken om ipv een initializer list voor zowel freq en amp een losse setter functie in de
  constructor body aan te roepen?
## 2. Classes, inheritance & oefenen met C++

2.1 **[READ][DIGEST] Destructor, delegating constructor en initializer list**

- **Destructors**
  - Lees over **destructors** https://www.tutorialspoint.com/cplusplus/cpp_destructors.htm
  - Wanneer zou een destructor in MT context nodig zijn?

2.2 **[INSTALL]** Installeer Juce,  volg de md met instructies in _sessie2/6_JuceTest

2.3 **[WRITE] Inheritance - Oscillator, Sine, Saw and Square**
_DISCLAIMER: Voor het inheritance deel in deze opdracht moet je echt 1_assigments.md 2.2 Simple Inheritance hebben
uitgevoerd en / of **al wat vertrouwd zijn met het implementeren van inheritance** in c++, dwz. hier ook zelf mee hebben
geoefend afgelopen week. _

_Bekijk als het wat is weggezakt ook nog een keer de slides/Sessie1_inheritance.pdf_
- Kopieer het voorbeeld 5_soundingSine naar je eigen repository
- Voeg square.h en square.cpp files toe en implementeer een Saw class. Je kunt hiervoor de Sine.h en Sine.cpp code
kopiëren en aanpassen.
- Breng de duplicate code in kaart en stel bijv. in draw.io een beknopt class diagram op met base class Oscillator en
derived classes Sine en Square.
  - Tip: kun je de tick() method opsplitsen in een 'phase update functie' en een 'sample bereken functie'?
- Werk dit class diagram uit in code (je kunt verder in je kopie van het sounding sine voorbeeld, maar voor je eigen
overzicht is het misschien makkelijker om daar een kopie van te maken).
  - Tip [OPTIONAL]: je kunt vanuit de base class een functie aanroepen van de subclass, maar daarvoor moet je
  een functie _overriden_ en heb je het keyword `virtual` nodig. Wil je vooruit werken? Zie
  https://www.tutorialspoint.com/cplusplus/cpp_function_overriding.htm   

2.4 **[WRITE][OPTIONAL] Quick en dirty organ synth in de audiocallback**
Bouw je code van 2.3 verder uit. Probeer bijv. een organ synth te maken door in de Audiocallback 3 blokgolven af te
spelen, met 1 grondtoon, 1 kwint hierboven en een slightly detuned kwint.
Wil je een melodie afspelen? Kijk dan naar het voorbeeld assignments/2_melody.

2.5 **[DESIGN][OPTIONAL] Class diagram eindopdracht**
Probeer alvast een deel van je eindopdracht uit te werken in een class diagram. De deadline hiervoor ligt op sessie 4,
maar tijdens sessie 3 kunnen we alvast kijken naar eerste schetsen om van te leren.  
