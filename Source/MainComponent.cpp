#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel (&myCustomLNF);
    myDial.setRange (0.0f, 100.0f, 0.1f);
    myDial.setValue (0.0f);
    addAndMakeVisible (myDial);
    
    parameterTitle.setFont (30.0f);
    parameterTitle.setJustificationType (juce::Justification::centred);
    addAndMakeVisible (parameterTitle);
    
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
    myDial.setBounds (getWidth() / 2 - 100, getHeight() / 2 - 100, 200, 200);
    parameterTitle.setBounds (myDial.getX(), myDial.getY() - 50, myDial.getWidth(), 40);
}
