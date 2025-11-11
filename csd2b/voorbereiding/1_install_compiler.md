# Stappenplan C++ installeren g++ compiler

---

### MAC
##### Installeer g++
Run in de terminal:

  ```bash
  xcode-select --install
  ```
_(Het zou kunnen zijn dat je hierna even moet xcode openen omdat er nog allemaal SDK's en developer frameworks geünstalleerd moeten worden.)_

##### Installeer CMAKE
- Run in de terminal:<br>

  ```bash
  brew install cmake    
  ```
  _(Nog niet brew geïnstalleerd? Zie https://brew.sh/)_

---

### WINDOWS
##### Installeer MSVC
- Installeer de C++ Compile via de Visual Studio Installer
  [[https://visualstudio.microsoft.com/downloads/]]
  (download de Community versie)


##### Installeer CMAKE
- Ook via de website
    [[https://cmake.org/download/ ]]<br>
LET OP!<br>
    - download de installer, niet de source
    - lees de installer goed, zodat CMAKE in de PATH wordt gezet

---



### LINUX
Op Linux is g++ doorgaans al geïnstalleerd. Dit kun je checken door het volgende in de terminal te runnen.  

```whereis g++```
