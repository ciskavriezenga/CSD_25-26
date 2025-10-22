# Stappenplan C++ installeren g++ compiler

---

### MAC
##### Installeer g++
- run in de terminal:

  ```bash
  xcode-select --install
  ```
- zou kunnen zijn dat je hierna even moet xcode openen omdat ze zijn en nog 500gb aan stuff moeten installeren

##### Installeer CMAKE 
- run in de terminal:<br>
  ```bash
  brew install cmake    
  ```
    
##### Compilen
- om de build files te generen run het volgende vanuit de _TOPLEVEL_ van je project (csd2 mapje waar je CMakeList.txt zit) 
  ```bash
  cmake -S . -B build
  ```
  `-S` locatie voor de SOURCE 
  `-B` locatie waar je de build files wilt hebben

- om daadwerkelijk te bouwen, `cd` naar welk project je wilt bouwen en run: 
  ```bash
  make
  ```
  (gebruik `-jX` om build te over meerdere cores uit te voeren. X = de hoeveelheid cores)
---

### WINDOWS
##### Installeer MSVC
- Installeer de C++ Compile via de Visual Studio Installer 
  [[https://visualstudio.microsoft.com/downloads/]]
  (download de Community versie)


##### Installeer CMAKE
- Ook via de website
    [[https://cmake.org/download/ ]]
LET OP!<br>
    - download de installer, niet de source
    - lees de installer goed, zodat CMAKE in de PATH wordt gezet
  

##### Compilen
- om de build files te generen run het volgende vanuit de _TOPLEVEL_ van je project (csd2 mapje waar je CMakeList.txt zit) 
  ```bash
  cmake -S . -B build
  ```
  `-S` locatie voor de SOURCE 
  `-B` locatie waar je de build files wilt hebben

- om daadwerkelijk te bouwen, `cd` naar welk project je wilt bouwen en run:
  ```bash
  cmake --build . 
  ```

---



### LINUX
Op Linux is g++ doorgaans al geïnstalleerd. Dit kun je checken door het volgende in de terminal te runnen.  

```whereis g++```


##### Installeer IDE

_Werk je op LINUX? Ws werkte je dan al met VIM?_

wil je ook met vscodium werken? Dan kun je hier even kijken welke manier van installeren relevant is voor jou:
https://vscodium.com/


---

##### Installeer IDE
- Er zijn verschillende opties qua IDE, verschillende smaken.
  - Pulsar in combinatie met cmake runnen in de terminal
  - clion, dan kun je vanuit de IDE builden en runnen, adhv cmake
    1. github studenten account regelen
    2. clion installeren

  - Vscodium
    ```brew install --cask vscodium```
    - installeer de c/c++ runner in vscodium

- NVIM TIP:
  - clangd is je vriend (LSP)
  - om clangd goed te laten werken met cmake heeft ie een `compile_commands.json` nodig. Dit maak je door het volgende te runnen:
  ```bash
  cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=1
  ```
