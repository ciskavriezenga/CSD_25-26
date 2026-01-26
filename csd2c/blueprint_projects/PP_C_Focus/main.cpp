#include "audiocomponent.h"
#include <iostream>
#include <random>

struct CustomCallback : AudioCallback {
    explicit CustomCallback (double Fs, 
                                int startMs = 0,
                                int endMs = 0,
                                const std::string& fileName = "0") : AudioCallback(Fs,  startMs, endMs, fileName){}
    ~CustomCallback() override{}

    void prepare (int sampleRate) override {}
    
    void process (AudioBuffer buffer) override { 
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                //outputChannels[channel][sample] = static_cast<float> (distribution(generator)) * 0.2f;

                outputChannels[channel][sample] = inputChannels[channel][sample];
            }
        }
    }

private:
    std::random_device randomDevice;
    std::mt19937 generator{randomDevice()};
    std::uniform_real_distribution<> distribution{-1.0, 1.0};

};




int main() {
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    CustomCallback audioSource (44100);
    JUCEModule juceModule (audioSource);
    juceModule.init(2,2);


    std::cout << "Press q + Enter to quit..." << std::endl;
    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }


    return 0;
}
