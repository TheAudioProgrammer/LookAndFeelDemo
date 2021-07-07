#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel (&myCustomLNF);
    
    auto rotaryParameters = mySlider.getRotaryParameters();
    //rotaryParameters.startAngleRadians = juce::MathConstants<float>::pi / 2.0f;
    //rotaryParameters.startAngleRadians = 0.0f;
//    rotaryParameters.startAngleRadians = juce::MathConstants<float>::pi * 1.2f;
//    rotaryParameters.endAngleRadians = juce::MathConstants<float>::pi * 2.8f;
    rotaryParameters.startAngleRadians = juce::MathConstants<float>::pi * 1.5f;
    rotaryParameters.endAngleRadians = juce::MathConstants<float>::pi * 3.0f;
    rotaryParameters.stopAtEnd = true;
    
    mySlider.setRotaryParameters (rotaryParameters);
    mySlider.setColour (juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::orange);

    mySlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    mySlider.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    mySlider.setRange (0.0f, 100.0f, 0.1f);
    mySlider.setValue (0.0f);
    addAndMakeVisible (mySlider);
    
    setSize (400, 400);
}

MainComponent::~MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel (nullptr);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::grey);
}

void MainComponent::resized()
{
    mySlider.setBounds (getWidth() / 2 - 100, getHeight() / 2 - 100, 200, 200);
}
