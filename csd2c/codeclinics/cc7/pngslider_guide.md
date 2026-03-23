# PNG Slider — BinaryData

`pngslider.h` provides `PNGSliderLookAndFeel`: a rotary slider skin that takes a single PNG image from `BinaryData` and rotates it to match the knob position.

---

## 1. Build the JUCE BinaryBuilder

The BinaryBuilder tool ships with JUCE source. Build it from the Top level of your cmake project.

```bash 
    cmake . -B build -DJUCE_BUILD_EXTRAS=ON
    cmake --build build --target BinaryBuilder
```
---

## 2. Generate BinaryData from your PNG

Run BinaryBuilder with three arguments: **input dir**, **output dir**, **class name**:

```bash
./BinaryBuilder <folder with images> <folder where you want your binary data> <a class name for your binary data> 
```

This produces two files in `./BinaryData/`:
- `BinaryData.h`
- `BinaryData.cpp`

The PNG is accessible as `BinaryData::knob_png` and `BinaryData::knob_pngSize`.

---

## 3. Add to CMakeLists.txt

Add the generated source files to your target and make sure the header is on the include path:

```cmake
target_sources(OpenLadder
    PRIVATE
        PluginEditor.cpp
        PluginProcessor.cpp
        BinaryData.cpp
)
```

---

## 4. Use in PluginEditor

### PluginEditor.h

```cpp
#include "BinaryData.h"
#include "pngslider.h"

//  under private
PNGSliderLookAndFeel pngSlider { BinaryData::knob_png, BinaryData::knob_pngSize };
```

### PluginEditor.cpp — constructor

```cpp
CutoffSlider.setLookAndFeel (&pngSlider);
```

### PluginEditor.cpp — destructor

```cpp
CutoffSlider.setLookAndFeel (nullptr);
```

---

## Notes

- The PNG should depict the knob at its **start** position. The LookAndFeel rotates it based on slider value.
- Use a square image for best results. Images that aren't square will be stretched to fit the slider bounds.
- If the image fails to load, `drawRotarySlider` will draw nothing. 
