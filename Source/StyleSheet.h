/*
  ==============================================================================

    StyleSheet.h
    Created: 2 Jul 2021 10:09:15am
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include "../Resources/Resources.h"
#include <JuceHeader.h>

class CustomLNF : public juce::LookAndFeel_V4
{
public:
    CustomLNF();
    juce::Slider::SliderLayout getSliderLayout (juce::Slider& slider) override;
    juce::Label* createSliderTextBox (juce::Slider& slider) override;
    void drawRotarySlider (juce::Graphics &, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, juce::Slider &slider) override;
};

class CustomDial : public juce::Slider
{
public:
    CustomDial()
    {
        setLookAndFeel (&myLNF);
        auto rotaryParameters = getRotaryParameters();
        rotaryParameters.startAngleRadians = juce::MathConstants<float>::pi * 1.5f;
        rotaryParameters.endAngleRadians = juce::MathConstants<float>::pi * 3.0f;
        rotaryParameters.stopAtEnd = true;
        setRotaryParameters (rotaryParameters);
        setColour (juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::orange);
        setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    }
    
    ~CustomDial()
    {
        setLookAndFeel (nullptr);
    }
    
private:
    CustomLNF myLNF;
};
