#pragma once

#include <juce_gui_extra/juce_gui_extra.h>

class PNGSliderLookAndFeel : public juce::LookAndFeel_V4
{
public:
    PNGSliderLookAndFeel (const void* pngData, size_t pngDataSize) {
        knobImage = juce::ImageCache::getFromMemory (pngData, (int) pngDataSize);
    }

    void drawRotarySlider (juce::Graphics& g,
                           int x, int y, int width, int height,
                           float sliderPosProportional,
                           float rotaryStartAngle,
                           float rotaryEndAngle,
                           juce::Slider&) override {
        if (! knobImage.isValid())
            return;

        const auto bounds = juce::Rectangle<float> ((float) x, (float) y, (float) width, (float) height);
        const auto angle = juce::jmap (sliderPosProportional, 0.0f, 1.0f, rotaryStartAngle, rotaryEndAngle);
        const auto imageBounds = juce::Rectangle<float> (0.0f, 0.0f, (float) knobImage.getWidth(), (float) knobImage.getHeight());

        juce::AffineTransform t;
        t = t.translated (-imageBounds.getCentreX(), -imageBounds.getCentreY());
        t = t.rotated (angle);
        t = t.scaled (bounds.getWidth() / imageBounds.getWidth(),
                      bounds.getHeight() / imageBounds.getHeight());
        t = t.translated (bounds.getCentreX(), bounds.getCentreY());

        g.drawImageTransformed (knobImage, t, true);
    }

private:
    juce::Image knobImage;
};
