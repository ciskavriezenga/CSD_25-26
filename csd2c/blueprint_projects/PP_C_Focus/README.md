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
You should already have JUCE installed. Add your JUCE dir to this project dir.

### lo 
For MacOS run the following in your terminal: \
```brew install liblo```


For Linux run the following in your terminal: \
```sudo apt install liblo-dev```
```sudo pacman -S liblo```


For Windows:
1. Install vcpkg 
```git clone https://github.com/microsoft/vcpkg
cd vcpkg 
./bootstrap-vcpkg.bat
```
you may need to add the `vcpkg.exe` to your PATH. 
2. then install liblo 
```vcpkg install liblo```
3. then generate build files using 
```cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=C:\path\to\vscpk\scripts\buildsystems\vcpkg.cmake```
If this fails, delete your build folder and try again. 

### python-osc 
pip3 install python-osc

OR

use a virtual environment:
```bash
python3 -m venv ./venv
source ./venv/bin/activate
python3 -m pip install python-osc
```

## Good luck 
