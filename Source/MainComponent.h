#pragma once

#include <JuceHeader.h>

#include "AssesmblePane.h"
#include "AudioPlayer.h"
#include "juce_audio_formats/juce_audio_formats.h"
#include "juce_audio_utils/juce_audio_utils.h"
#include "juce_core/juce_core.h"
#include "juce_gui_basics/juce_gui_basics.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public juce::AudioAppComponent {
       public:
        //==============================================================================
        MainComponent();
        ~MainComponent() override;

        //==============================================================================
        void paint(juce::Graphics &) override;
        void resized() override;

        void getNextAudioBlock(const juce::AudioSourceChannelInfo &bufferToFill) override;
        void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
        void releaseResources() override;

        // void buttonClicked(juce::Button *button) override;
        // void sliderValueChanged(juce::Slider *) override;

       private:
        juce::AudioFormatManager formatManager;
        juce::AudioThumbnailCache thumbnailCache{100};
        // AssemblePane assemblePane2{&player2, formatManager, thumbnailCache};

        juce::FileChooser chooser{"Select a file to proccess..." };
        //                           juce::File::getSpecialLocation(juce::File::userHomeDirectory),
        //                           "*.wav;*.mp3;*.aiff;*.flac;*.ogg;*.m4a;*.mp4;*.wma;*.ac3;*.aifc;*.caf;*.alac;*.ape;*."
        //                           "mpc;*.ogg;*.opus;*.tta;*.wv;*.dsf;*.dff"};


        AudioPlayer player1{formatManager};        // set player1 object of DJAudio class
        // AudioPlayer player2{formatManager};        // set player2 object of DJAudio class

        AssemblePane assemblePane1{&player1, formatManager, thumbnailCache};
        juce::MixerAudioSource mixerSource;

        // juce::TextButton playButton{"Hello honey"};
        // juce::TextButton stopButton{"Bye"};
        // juce::Slider volumeSlider{juce::Slider::SliderStyle::LinearHorizontal,
        //                           juce::Slider::TextEntryBoxPosition::TextBoxLeft};

        juce::Random rand;
        double phase;
        double dphase;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
