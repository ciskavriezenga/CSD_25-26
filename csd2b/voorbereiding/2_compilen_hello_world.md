# Stappenplan compilen

---

### MAC & Linux
#### Compilen algemene info
- om de build files te generen run het volgende vanuit de _TOPLEVEL_ van je project (csd2 mapje waar je CMakeList.txt zit):
  ```bash
  cmake -S . -B build
  ```
  `-S` locatie voor de SOURCE
  `-B` locatie waar je de build files wilt hebben

- om daadwerkelijk te bouwen, `cd` naar welk project je wilt bouwen en run:
  ```bash
  make
  ```
  _(Gebruik `-jX` om build over meerdere cores uit te voeren. X = de hoeveelheid cores)_

#### Compilen van het hello world voorbeeld in deze map
Ga in de terminal naar de map helloWorld in deze map.
- Run cmake:
  ```bash
  cmake -S . -B build
  ```

- Ga naar de build directory
  ```bash
  cd build
  ```
- Run make
  ```bash
  make
  ```
- Run de executable
  ```bash
  ./hello
  ```







---

### Windows
#### Compilen algemene info
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
#### Compilen van het hello world voorbeeld in deze map
Ga in de terminal naar de map helloWorld in deze map.
- Run cmake:
  ```bash
  cmake -S . -B build
  ```

- Ga naar de build directory
  ```bash
  cd build
  ```
- Run make
  ```bash
  cmake --build .
  ```
- Run de executable
  ```bash
  ./hello.exe
  ```
