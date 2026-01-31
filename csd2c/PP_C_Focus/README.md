# Plug & Play / Custom Focus 
This project uses Open Sound Control to communicate between programmes. This is 
used currently to in combination with a python script which acts as client (sender),
to change a parameter in the audio callback which acts as server (receiver). \

## Prerequisites
- JUCE 
- lo 
- python-osc 

## Install 
### JUCE 
You should already have this. 

### Lo 
For MacOS run the following in your terminal: \
```brew install liblo```
For Linux run the following in your terminal: \
```sudo apt install liblo-dev```
```sudo pacman -S liblo```
For Windows:
Install vcpkg 
```git clone https://github.com/microsoft/vcpkg
cd vcpkg 
./bootstrap-vcpkg.bat
```
you may need to add the `vcpkg.exe` to your PATH. 
then run 
```vcpkg install liblo```

