

# To compile


## Compilen met g++
```bash
g++ [file_name].cpp -o [executable_name] -std=c++20
```

| Terminal| Toelichting|
|----------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ```g++ hello.cpp```              | a.out is de applicatie                                                                                                                                                                                                                             |
| ```g++ hello.cpp -o hello_app``` | Met -o en daarna een naam geef je een `objective` mee                                                                                                                                                                                              |
| ```hexdump hello_app```          | 16 getallen → a b c d e f voor 11 12 13 14 15 16                                                                                                                                                                                                   |
| ```hexdump -C hello_app```       | hex + ASCII-weergave                                                                                                                                                                                                                               |
| ```man ascii```                  | ascii tabel weergeven --> kijk bij hexadecimal                                                                                                                                                                                                     |
| ```g++ -S hello.cpp```           | De assembly file hello.s wordt gegenereerd. Assembly is een low level programmeertaal en bevat instructies aan de processor. De assembly code is verschillend per processor architecture.                                                          |
| ```g++ -c hello.s```             | De object-file hello.o wordt gegenereerd. <br/>De compiler creëert object files voor elke source file, vooraf aan deze samen te linken in één executable. Een object file bevat de gecompileerde code, de machine code gecreëerd door de c++ compiler. |     
| ```g++ -c hello.cpp```           | De object file hello.o wordt in één stap gegeneerd, onder windows .obj, de gecompileerde versies van 1 c++ bestand                                                                                                                                 |
 | ```g++ hello.o```                | Maak van hello.o een executable --> a.out                                                                                                                                                                                                          |
| ```g++ hello.o -o hello```               | Maak van hello.o een executable genaamd hello                                                                                                                                                                                                      |

Zie ook https://dinkum.nl/software/cplusplus/doc/project_building/cpp_compiling_and_linking.html

## Compilen met cmake
1. Run in de terminal
```bash
cmake -S . -B build
cd build

# Mac / Linux
make
# Windows
cmake --build .
```
2. Run de executable
  ```bash
  # Mac / Linux
  ./hello

  # Windows  
  ./hello.exe
  ```

Wanneer je niet nieuwe bestanden toevoegt hoef je maar één keer cmake -S . -B  build te runnen. Bij wijzigingen in je code hoef je enkel in de build directory ```cmake --build .``` te runnen.  


| Terminal                  | Toelichting                                          |
|---------------------------|------------------------------------------------------|
| ```cmake -S . -B build``` | Build files genereren                                |
| ```-S```                  | Waar de source te vinden is                          |
| ```-B```                  | Waar je de build files wilt plaatsen                 |
| -jX                       | om meerdere cores te gebruiken --> X is aantal cores |
| ```cd build```            | Navigeer naar je build directory                     |
| ```cmake --build .```     | Run make in je directory                             |                            |
| ```cd ..```               | Navigeer weer een directory 'hoger'.                 |
