# Stappenplan C++ installeren g++ compiler

---

### MAC
##### Installeer g++
- run in de terminal:

  ```bash
  xcode-select --install
  ```

##### Installeer IDE
- Er zijn verschillende opties qua IDE, verschillende smaken.
  - Pulsar in combinatie met cmake runnen in de terminal
  - clion, dan kun je vanuit de IDE builden en runnen, adhv cmake
    1. github studenten account regelen
    2. clion installeren

  - Vscodium
    ```brew install --cask vscodium```
    - installeer de c/c++ runner in vscodium


---

### WINDOWS
##### Installeer g++
- Er zijn verschillende manieren om g++ op windows te installeren. Maar ...
  we werken met JUCE _(we zijn overgegaan op JUCE en cmake ipv jack audio en makefiles, zodat er op Windows gewerkt kan worden)_ en om daar mee te werken kwamen we erachter dat de de compiler installeren vanuit visual studio installer wel werkt en compiler via minq niet werkt. Mocht je handig zijn en een andere manier weten om JUCE op windows met compiler werkend te krijgen; we horen het graag!
  -



- Windows start menu --> open windows power shell (zoek op 'power'), run daarin:

  ```winget install MSYS2.MSYS2```

  (https://www.msys2.org/)


- open msys2 terminal en run:

  ```pacman -S mingw-w64-ucrt-x86_64-gcc```


- open file explorer en navigeer naar c directory en selecteer map msys64, naar map ucrt64, map bin, zitten g++.exe en gcc.exe erin? (of g++ en gcc)
  - --> correcte locatie, kopier het pad.  


- zoek in windows menu naar environment variables en open (click ev. op environment variables)
  - dubbelclick onder user variables 'Path', click in het nieuwe venster op new en paste je gekopieerde path


-  open windows power shellen run
  ```gcc --version```
  <br>*wordt die gevonden?*


- Installeer vscodium en run in windows power shell:

  ```winget install VSCodium.VSCodium```

  *(Of vraag een github studenten account aan en installeer clion
(dit hebben we nog niet getest mét de g++ install)).*


---



### LINUX
Op Linux is g++ doorgaans al geïnstalleerd. Dit kun je checken door het volgende in de terminal te runnen.  

```whereis g++```


##### Installeer IDE

_Werk je op LINUX? Ws werkte je dan al met VIM?_

wil je ook met vscodium werken? Dan kun je hier even kijken welke manier van installeren relevant is voor jou:
https://vscodium.com/


---
