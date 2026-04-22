#pragma once

#include <juce_gui_extra/juce_gui_extra.h>

class SVGSliderLookAndFeel : public juce::LookAndFeel_V4
{
public:
    explicit SVGSliderLookAndFeel (const juce::File& yourSvgFile) {
        knobDrawable = juce::Drawable::createFromSVGFile(yourSvgFile);
    }

    void drawRotarySlider (juce::Graphics& g,
                           int x, int y, int width, int height,
                           float sliderPosProportional,
                           float rotaryStartAngle,
                           float rotaryEndAngle,
                           juce::Slider&) override {
        if (knobDrawable == nullptr)
            return;

        const auto bounds = juce::Rectangle<float> ((float) x, (float) y, (float) width, (float) height);
        const auto angle = juce::jmap (sliderPosProportional, 0.0f, 1.0f, rotaryStartAngle, rotaryEndAngle);

        juce::Graphics::ScopedSaveState saveState (g);
        g.addTransform (juce::AffineTransform::rotation (angle, bounds.getCentreX(), bounds.getCentreY()));
        knobDrawable->drawWithin (g, bounds, juce::RectanglePlacement::centred, 1.0f);
    }

private:
    std::unique_ptr<juce::Drawable> knobDrawable;
};