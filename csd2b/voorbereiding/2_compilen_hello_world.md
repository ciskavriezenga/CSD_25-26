# Stappenplan compilen

---

### MAC & Linux
#### Compilen algemene info
- om de build files te generen run het volgende vanuit de directory van het project waar de CMakeLists.txt zit:
  ```bash
  cmake -S . -B build
  ```
  `-S` locatie voor de SOURCE
  `-B` locatie waar je de build files wilt hebben

- om daadwerkelijk te bouwen, `cd` naar de build directory:
  ```bash
  make
  ```
  _(Gebruik `-jX` om build over meerdere cores uit te voeren. X = de hoeveelheid cores)_

  - je executable is te vinden in:
    ```
    build/
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
  make
  ```
- Run de executable
  ```bash
  ./hello
  ```

#### 2b - meerdere projecten ...
Tijdens 2b werk je aan meerdere projecten. Dat kan prima met cmake, we hebben dan op het toplevel  niveau van je csd hoofd directory een CMakeLists.txt. Door meerdere CMakeLists.txt in subfolders te gebruiken kunnen er meerdere projecten
gebuild worden. Dit bespreken we tijdens het eerste practicum 2b.

---

### Windows
#### Compilen algemene info
- om de build files te generen run het volgende vanuit de directory van het project waar de CMakeLists.txt zit
  ```bash
  cmake -S . -B build
  ```
  `-S` locatie voor de SOURCE
  `-B` locatie waar je de build files wilt hebben

- om daadwerkelijk te bouwen, `cd` naar de build directory:
  ```bash
  cmake --build .
  ```
- je executable is te vinden in:
  ```
  build/
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

#### 2b - meerdere projecten ...
Tijdens 2b werk je aan meerdere projecten. Dat kan prima met cmake, we hebben dan op het toplevel  niveau van je csd hoofd directory een CMakeLists.txt. Door meerdere CMakeLists.txt in subfolders te gebruiken kunnen er meerdere projecten
gebuild worden. Dit bespreken we tijdens het eerste practicum 2b.
