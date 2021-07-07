/*
  ==============================================================================

    StyleSheet.h
    Created: 2 Jul 2021 10:09:15am
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>


class CustomLNF : public juce::LookAndFeel_V4
{
public:
    void drawRotarySlider (juce::Graphics &, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, juce::Slider &slider);
};
