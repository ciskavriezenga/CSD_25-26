# Plugin Focus 
This project uses the JUCE framework to build a working One Knob plugin with an 
automatable parameter. Ready to be thrown into your DAW. 

## Prerequisites 
- JUCE
  You should already have JUCE installed. Add your JUCE dir to this project dir.

## Installing your Plugin 
Follow the same steps as you normally would to compile your program. When 
compilation is complete you will have 2 or 3 files, depending on your 
operating system. 

### macos 
A standalone, VST3 and an AudioUnit (component). \
Close the DAW. \
Then simply copy the .vst3 or the .component into their respective folder in your 
plugins location. The default is `/Library/Audio/Plug-Ins`. Restart your DAW and
it should be there. \
If the VST3 doesn't show up, try the AudioUnit instead. 

### Windows 
A standalone and a VST3. 
Close the DAW. \
Simply copy the .vst3 into the VST3 folder in your plugins location. The default 
is `C:\Program Files\Common Files\VST3`. Restart your DAW and it should be there. 

### Linux 
A standalone and a VST3. 
Close the DAW. \
Simply copy the .vst3 into the vst3 folder in your plugins location. The default 
is `/usr/lib/vst3` or `~/.vst3/`. Restart your DAW and it should be there.
