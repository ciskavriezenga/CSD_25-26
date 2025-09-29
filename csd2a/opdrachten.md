# Opdrachten
# 5 - Voorbereiding volgende keer

___
## "Rectificatie"
Tijdens de sessie refereerde ik met literals aan de _variable types int, float, str, bool_, etc... en hoe in een functie een bijv. int parameter als kopie benaderd wordt. Ik twijfelde al even of ik de goede term gebruikte en zat inderdaad fout. Ik was even in de war met Javascript waar je het 'Primitive' types noemt. In python noem je dit de zogenaamde _immutable types_.
Waar je bijv. een list _(mutable type)_ kunt aanpassen, kun je een int variable niet aanpassen, bij het _assignen_ van een andere waarde wordt er een nieuw object geconstrueerd bijv.:
```python
a = 10
b = a # b references 10 as well
a = 20 # a new object is created to which a references
```
Zo ook bij een functie, wanneer je de parameter aanpast wordt er een nieuw object (dus een nieuwe int, float, str, bool etc.) aangemaakt. Je oorspronkelijke object dat je als variable mee gaf aan de functie blijft dus ongewijzigd
Kortom - zoals ik het uitlegde, maar net andere terminologie.
___

## Opdrachten week 5
Alles tot nu toe, inclusief dictionary
!!!!!!!!

Wil je verder werken? Kijk naar:

**[WRITE][optional] Eigen generatie strategie & UI**

Zie week 4 en UI voorbeelden (5a, 5b en 5c) in session 5




# 4 - Voorbereiding volgende keer
- **[READ] Dictionaries**
  - Lees over dictionaries op https://www.w3schools.com/python/python_dictionaries.asp
  - Indien script 4c en 4d nog niet besproken zijn tijdens sessie 4, lees dan in session.md de bijgaande uitleg en neem volgens die 'aanwijzingen' deze twee voorbeelden zelfstandig door.
  - Voorbeeld script 4e is bedoeld voor wie graag alles overziet en de behoefte voelt om iets meer van dictionaries te begrijpen vooraf hier mee te willen / kunnen werken.
  - Voorbeeld script 4f is bedoeld voor de al wat ervaren coders, een voorbeeld van hoe je met functies dictionaries kunt genereren.  


- **[WRITE] Eigen generatie strategie + playback & functies**

  _= DEELS EEN HERHALING VAN EERDERE OPTIONELE OPDRACHT_

  - Deel je generatie script op in delen en breng deze onder in functies. Besteed hierbij aandacht aan de naamgeving en wat de functie doet, is het een functie met een input en output? Of past het de input aan? Essentieel om dit aan de functie naam af te kunnen lezen! E.g.:
    - `createTimestamps(note_durations, bpm)` --> je verwacht een return
    - `offsetTimestamps(time_stamps, offset)` --> past de lijst met time_stamps aan en voegt een offset toe.

    NOTE: voorkeur gaat doorgaans uit naar een functie met een return, zodat je bij het gebruik van de functies in de code eenvoudig de input & output flow kunt lezen. Komt vaak de _readability_ ten goede.

    Tip: schrijf een 'hoofdfunctie' voor je generatie script met als input een settings dictionary die de benodigde settings doorgeeft en als output dictionary van drie note duratie lijsten (één lijst voor iedere laag). Bijvoorbeeld:
    ```python
      def gen_sequences(settings)
        """
        Generates a dictionary with three note duration lists for the three layers high, mid, low, based on the provided settings.

        parameter settings: the setting dictionary, this dictionary contains ...  

        return: a dictionary with three note duration lists
        """
        # E.g. call a seperate generation function per layer. You can also
        # call one function three times with different extra paramters if that
        # suits your genration strategy.
        sequences = {
          "high": gen_high(settings),
          "mid": gen_mid(settings),
          "low": gen_low(settings),
        }

        return sequences
    ```

    De `settings` dictionary kun je voor nu hard coden bij het aanroepen van de gen_sequences functie. Volgende week kijken we naar een generieke manier om met UI aan de gebruiker de settings op te vragen.

  - Transformeer de output van je generatie code (e.g. de output van de gen_sequences functie) in een aantal stappen naar events
    1. durations in time - a dictionary with one list of durations in time for each layer
    2. timestamps - a dictionary with one list of timestamps for each layer
    3. events - a dictionary with one list of events for each layer
    4. one concatenated list of events
    ```python
      all_events = events["high"] + events["mid"] + events["low"]
    ```
    5. sort `all_events` based on each event's timestamp
    ```python
      # NOTE: get_timestamp function needs to be defined, see 4d example
      sorted_events = all_events.sort(key=get_timestamp)
    ```

  - Voeg de handle_events functie toe uit het 4c voorbeeld & de afspeel functionaliteit uit timestamps_final.py toe aan je script. Pas de afspeel code aan zodat de events uit sorted_events afgespeeld kunnen worden met de handle_events functie.

- **[WRITE][OPTIONAL] Eigen generatie strategie & UI**
  - Maak een nieuw script in dezelfde folder als je generatie script folder van de vorige opdracht (die hierboven beschreven) genaamd UI.py.
  - Zet in dit script op een rij welke input er van de gebruiker nodig is voor je gehele programma (bpm, maatsoort, etc.). Denk hierbij ook aan het wel / niet wegschrijven van het gegenereerde ritme als midi file
  - Werk een paar gebruiker input vragen uit in losse functies, bijvoorbeeld een functie voor het opvragen van de bpm, voor de maatsoort etc.. Denk hierbij ook aan het valideren van de gegeven input, zodat een bpm niet tekst bevat of bijv een te hoge / lage of negatieve waarde.
  - Probeer een generieke functie op te stellen die voor verschillende vragen te gebruiken is, waarbij je bijvoorbeeld de vraag en range meegeeft.

# 3 - Voorbereiding volgende keer
_**Let op: dit bouwt voort op de opdrachten uit week 1 & 2**_
- **[DESIGN] Eindopdracht - ontwerp concept**
  - Indien je dit nog niet gedaan hebt, werk dan je generatie strategie volledig uit, met de onderstaande onderdelen:
    - Beschrijving van de gekozen strategie, inclusief voordelen en nadelen (+/- 1 a 2 alinea's)
    - Strategie uitgewerkt in stappen en/of flow diagram
    - 'Werkende' pseudo code van de strategie (d.w.z. het generatie deel, niet het afspeel deel)
  - Voeg deze documentatie toe aan je online repository.

<br/>

- **[WRITE] Implementatie generatie strategie in Python**
  - Werk je pseudo code uit in Python; implementeer in een python script je strategie en print aan het einde je gegenereerde ritme.

    _Nog te lastig? Geen probleem! Benut het practicum!_

  Tips:
    - Complexe strategie? -->  Wat is de minimum viable product (m.v.p.)?
    - Gebruikersinput nodig? Mock dit voor nu even door dit gewoon even te 'hardcoden' , d.w.z. ken voor nu een vaste waarde toe waar nodig alsof die door een gebruiker is ingevoerd. Test je script uiteindelijk wel uit met verschillende waardes, zodat je weet dat het voor verschillende mogelijke input werkt.

<br/>

- **[READ][WRITE] Functions in python**
  - **[READ]** Lees de volgende delen over functies op https://www.w3schools.com/python/python_functions.asp, lees:
    - Creating a Function
    - Calling a Function
    - Arguments
    - Number of Arguments
    - Return Values
    Optioneel:
    - Default Parameter Value
    - Passing a List as an Argument
  - **[WRITE]** Leer jezelf werken met functies; maak een nieuw python script en schrijf  bijvoorbeeld:
    - Een functie die het type van het argument print
    - Een functie die twee parameters verwacht, namelijk `note_durations` en `bpm` en die een lijst met timestamps _returned_ die geconstrueerd is door de in `note_durations` waarden op basis van het bpm om te rekenen naar de juiste timestamp.
    - Een functie die je een lijst mee geeft met namen van sample packs en die deze voorlegt aan de gebruiker, vervolgens de gebruiker een keuze laat maken en de index van de desbetreffende keuze uit de lijst _returned_.

<br/>

- **[READ][WRITE] Verwerking & verdiepingsopdracht sessie 3 - deel 1**

  Deze opdracht is voor extra verwerking van de tijdens de sessie besproken content. In de map session3/sample_player staan voorbeeldscripts. Deze scripts bevatten oefeningen en opdrachten.

  Ga met de voorbeeldscripts aan de slag: code lezen en begrijpen, denk per script na wat je als output verwacht, daarna pas het script uitproberen en vervolgens de opdrachten uitvoeren die in de comments in de code staan (EXERCISES).

  _NOTE: Voor ervaren coders: sommige onderdelen in deze opdrachten kun je prima even overslaan._

<br/>

- **[READ] Verwerking & verdiepingsopdracht sessie 3 - deel 2**

  Lees het timestamps_final.py voorbeeld grondig (neem hier echt de tijd voor) en:
  - Breek het script op in verschillende onderdelen. Als je deze onderdelen in losse functies zou verwerken, hoe zou je dan deze functies noemen? Bedenk passende functie namen
  - Maak een flow chart bij dit script.
  - Het script is geschikt voor een ritme met één sample. Wat zou er aangepast moeten worden als je meerdere samples wilt afspelen? Hoe zou je dat doen, schets dit in pseudo code.
  - Het script is momenteel niet geschikt voor gelijktijdig 'getriggerde' samples. Allereerst komt dit omdat het met maar één sample werkt. Maar ook als je meerdere samples gebruikt kun je niet twee samples tegelijkertijd afspelen. Hoe kan dit? Hoe kun je dit oplossen?

<br/>

- **[WRITE][OPTIONAL] Eigen generatie strategie + playback**

  - Voeg de afspeel functionaliteit uit timestamps_final.py toe aan het script waarin je je generatie strategie hebt verwerkt en speel je gegenereerde ritme af!

  - Deel je script op in delen en breng deze onder in functies. Besteed hierbij aandacht aan de naamgeving en wat de functie doet, is het een functie met een input en output? Of past het de input aan? Essentieel om dit aan de functie naam af te kunnen lezen! E.g.:
    - `createTimestamps(note_durations, bpm)` --> je verwacht een return
    - `offsetTimestamps(time_stamps, offset)` --> past de lijst met time_stamps aan en voegt een offset toe.


# 2 - Voorbereiding volgende keer

_**Let op: al het onderstaande hoort bij week 2, dit bouwt voort op de opdrachten uit week 1**_


- **[DESIGN]** Vervolg ritme generatie strategie
  - Scherp je ritme generatie strategie aan op basis van eventuele feedback / andere presentaties _(of switch naar een andere strategie en werk deze eerst uit, kan nu nog)_ en werk de pseudo code op gedetaileerder niveau verder uit.
  - Playtest je pseudocode; laat iemand anders de code uitvoeren. Dwz, je playtester speelt het systeem en voert regel voor regel je pseudo code uit _(practicum is hier een goed moment voor)_. Let op: de code moet 'voor zichzelf spreken', je mag niet helpen door extra aanwijzingen en toelichtingen te geven _(dus niet de playtest beïnvloeden met zinnen als "ja, nu moet je dus eigenlijk dit doen")_.
  - Fix de _(eventuele)_ bugs en test het opnieuw _(geen bugs? Toch nog een keer playtesten met iemand anders (!), altijd waardevol)_. #Herhaal --> totdat er geen bugs meer inzitten en je pseudo code werkt!
<br/><br/>

- Python
  - **[READ]** Als je nog niet de twee relatief eenvoudige ritmes in de csd2a/session2/relative_simple_examples map gelezen en uitgeplozen hebt: lees deze dan alsnog. Het liefst hardop (of in je hoofd hardop) waarbij je per stukje code de werking voorstelt. Wat bij dit laatste helpt is het uitvoeren van de code op papier.
  - **[READ]** Maak bij in ieder geval één van de twee relatief eenvoudige ritmes in de csd2a/session2/relative_simple_examples map een flow chart
  - **[READ]** **[OPTIONAL]** Lees _(deels) de voorbeelden in csd2a/session2/extended_examples map Het liefst hardop (of in je hoofd hardop) waarbij je per stukje code de werking voorstelt. Wat bij dit laatste helpt is het uitvoeren van de code op papier.

  - **[WRITE]** kopieer de code uit de csd2a/session1/hello_bliep.py naar je eigen repository en speel de sample meerdere keren af. Werk dit in ieder geval op de volgende twee manieren uit:
    - met een while loop (zie https://www.w3schools.com/python/python_while_loops.asp)
    - met een forloop en range (zie **The range() Function** op https://www.w3schools.com/python/python_for_loops.asp)  
    <br/><br/>
  - **[WRITE]** **Afspelen van een ritme** Maak een python script aan en stel hierin een lijst op (voor python lists zie https://www.w3schools.com/python/python_lists.asp), zet verschillende duraties in de lijst. Werk daarna als volgt stap voor stap je script verder uit:
    - 'doorloop' deze lijst met behulp van een forloop _(zie https://www.w3schools.com/python/python_for_loops.asp)_ en print met behulp van deze forloop de waarden uit deze lijst
    - importeer de time module en gebruik in de forloop de time.sleep() functie _(zie het hello_bliep.py script uit de eerste sessie - csd2a/session1/hello_bliep.py)_ samen met de duratie in de body van de forloop
     ```python
     for dur in durations:
       time.sleep(dur)
       # and print dur
     ```
    - Laad nu ook een sample in en speel deze in de body van de forloop af _(zie ook het hello_bliep.py script uit de eerste sessie - csd2a/session1/hello_bliep.py)_
    <br/><br/>
  - **[WRITE]** **[OPTIONAL]** Werk de volgende python scripts uit _(dit bouwt stap voor stap op, dus je kunt ook één script steeds verder uitwerken)_:
    - laad minimaal drie verschillende samples en speel deze na elkaar af
    - laad minimaal drie verschillende samples en speel deze samples af op basis van een volgorde aangegeven in een lijst (voor python lists zie https://www.w3schools.com/python/python_lists.asp)
    - laad minimaal drie verschillende samples, genereer een lijst met _random_ die de afspeel volgorde aangeeft (voor python lists zie https://www.w3schools.com/python/python_lists.asp, voor random zie https://www.w3schools.com/python/ref_random_randint.asp en https://www.w3schools.com/python/ref_random_choices.asp)





# 1 - Voorbereiding volgende keer

_**Let op: al het onderstaande hoort bij week 1**_
- Neem de grondig (!) eindopdracht door, zie Eindopdracht_CSD2a_Irregular_beat_generator.pdf in de csd2a map.
<br/><br/>
- Verdiep je in ritme generaties (boeken, online, sparren met elkaar). Kijk bijvoorbeeld naar:
  - Probability based
  - 1st order markov chain
  - Euclidean rhythms
  - Sets of 2s and 3s as building blocks
  - Sequence variations on given configuration sets
  - 1st order Markov chain *(a bit more complex)*
<br/><br/>
- Ontwerp individueel _(eventueel in duo, maar dan werk je daarna ws ook aan dezelfde strategie)_ een ritme generatie strategie en bereid **een presentatie van 3 minuten** voor, met daarin:
  - Uitleg van je strategie, deel hierbij onder andere de stappen van je strategie en een flow diagram *(eenvoudig is oké!)*
  - Voor- en nadelen op een rij (bijv. sommige strategieën zijn eenvoudig te programmeren (voordeel) maar leveren niet zulke gevarieerde ritmes op (nadeel) of vergen veel configuratie om tot interessante ritmes te komen (nadeel) )
  - De basis van je strategie uitgewerkt in pseudo code
<br/><br/>
- Neem de sessie1 handouts door, zie folder handouts/. Handig om HO 2 en 3 tijdens het practicum door te nemen ivm de optie om hulp te krijgen indien je vastloop.
  - Om te testen of pygame werkt kun je csd2a/session1/hello_bliep.py runnen
