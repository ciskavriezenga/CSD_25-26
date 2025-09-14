# Opdrachten


# 3 - Voorbereiding volgende keer
_**Let op: dit bouwt voort op de opdrachten uit week 1 & 2**_
- **[DESIGN]** Eindopdracht - generatie deel uitgewerkt en documentatie hiervan op git met daarin:
  - Beschrijving van de gekozen strategie, inclusief voordelen en nadelen
  - Strategie uitgewerkt in stappen en/of flow diagram
  - 'Werkende' pseudo code van de strategie (d.w.z. het generatie deel, niet het afspeel deel)
<br/><br/>
- **[WRITE]** Werk je pseudo code uit in Python; implementeer in een python script je strategie en print aan het einde je gegenereerde ritme. Tips:
  - Complexe strategie? -->  Wat is de minimum viable product (m.v.p.)?

  - Gebruikersinput nodig? Mock dit voor nu even door dit gewoon even te 'hardcoden' , d.w.z. ken voor nu een vaste waarde toe waar nodig alsof die door een gebruiker is ingevoerd. Test je script uiteindelijk wel uit met verschillende waardes, zodat je weet dat het voor verschillende mogelijke input werkt.


  <br/><br/>
  - **[READ][WRITE]** [OPTIONAL FOR EXPERIENCED CODERS] Deze opdracht is voor extra verwerking van de tijdens de sessie besproken content. In de map session3/sample_player staan voorbeeldscripts. Deze scripts bevatten oefeningen en opdrachten. Ga met de voorbeeldscripts aan de slag: code lezen en begrijpen, denk per script na wat je als output verwacht, daarna pas het script uitproberen en vervolgens de opdrachten uitvoeren die in de comments in de code staan (EXERCISES).


- **[READ]** Lees het timestamps_final.py voorbeeld grondig (neem hier echt de tijd voor) en:
  - Breek het script op in verschillende onderdelen. Als je deze onderdelen in losse functies zou verwerken, hoe zou je dan deze functies noemen? Noteer passende functie namen.
  - Maak een flow chart bij dit script.
  - Het script is geschikt voor een ritme met één sample. Wat zou er aangepast moeten worden als je meerdere samples wilt afspelen? Hoe zou je dat doen, schets dit in pseudo code.
  - Het script is momenteel niet geschikt voor gelijktijdig 'getriggerde' samples. Allereerst komt dit omdat het met maar één sample werkt. Maar ook als je meerdere samples gebruikt kun je niet twee samples tegelijkertijd afspelen. Hoe kan dit? Hoe kun je dit oplossen? Pas de code aan (of werk uit in pseudo code).





<br/><br/>
- **[WRITE][OPTIONAL]** Maak een kopie van het python script waarin je je generatie strategie hebt verwerkt. Voeg hier de afspeel functionaliteit uit timestamps_final.py aan toe en speel je gegenereerde ritme af!



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
