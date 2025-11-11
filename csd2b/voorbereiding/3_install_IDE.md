
---

##### Installeer IDE
- Er zijn verschillende opties qua IDE, verschillende smaken.

##### Installeer IDE
  - _Werk je op LINUX? Ws werkte je dan al met VIM?_
  - Pulsar in combinatie met cmake runnen in de terminal
  - clion, dan kun je vanuit de IDE builden en runnen, adhv cmake
    1. github studenten account regelen
    2. clion installeren

  - Vscodium
    Wil je ook met vscodium werken? Dan kun je hier even kijken welke manier van installeren relevant is voor jou:
    https://vscodium.com/
    - Op Mac:
      ```brew install --cask vscodium```
      - installeer de c/c++ runner in vscodium

  - NVIM TIP:
    - clangd is je vriend (LSP)
    - om clangd goed te laten werken met cmake heeft ie een `compile_commands.json` nodig. Dit maak je door het volgende te runnen:
    ```bash
    cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=1
    ```
