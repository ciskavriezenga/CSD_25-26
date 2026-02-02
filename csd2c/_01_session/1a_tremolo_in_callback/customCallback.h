//
// Created by Ciska Vriezenga on 26/01/2026.
//

#ifndef CUSTOMCALLBACK_H
#define CUSTOMCALLBACK_H

#include "audiocomponent.h"
#include "oscillators/sine.h"
#include "settings.h"
#include <iostream>
#include <random>


class CustomCallback : public AudioCallback {
public:
    explicit CustomCallback (double Fs,
                                int startMs = 0,
                                int endMs = 0,
                                const std::string& fileName = "0") : AudioCallback(Fs,  startMs, endMs, fileName){}
    ~CustomCallback() override{}

    void prepare (int sampleRate) override;

    void process (AudioBuffer buffer) override;

private:
    std::random_device randomDevice;
    std::mt19937 generator{randomDevice()};
    std::uniform_real_distribution<> distribution{-1.0, 1.0};
    Sine sine;
};


#endif //CUSTOMCALLBACK_H
