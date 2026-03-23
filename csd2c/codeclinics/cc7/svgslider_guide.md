# SVG Slider — Local File

`svgslider.h` provides `SVGSliderLookAndFeel`: a rotary slider skin that loads an SVG from a file path at runtime and rotates it to match the knob position. 
**NOTE:** The juce SVG interpreter is not perfect.. but it *has* improved. 

## Setup

Include the header.

```cpp
#include "svgslider.h"
```

## PluginEditor.h

Add a look-and-feel member and point it at your SVG file:

```cpp
SVGSliderLookAndFeel svgSlider { juce::File { "/path/to/knob.svg" } };
```

A more portable approach — resolve relative to the executable:


## PluginEditor.cpp

**Constructor** — attach to any rotary slider:

```cpp
CutoffSlider.setLookAndFeel (&svgSlider;
```

**Destructor** — always clear it:

```cpp
CutoffSlider.setLookAndFeel (nullptr);
```

## Notes

- The SVG should depict the knob at its **start** position (pointer at 12 o'clock or your preferred default). The class rotates it based on slider value.
- SVG is resolution-independent, so it scales cleanly to any slider size.
- If the file is missing, `drawRotarySlider` will draw nothing.
