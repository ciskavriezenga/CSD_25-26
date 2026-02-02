//
// Created by Dean on 02/12/2023.
//
#pragma once

#include <writeToFile.h>
#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_audio_devices/juce_audio_devices.h>
#include <iostream>
#include <limits>
#include <cstdlib>


struct AudioBuffer {
  const float** inputChannels;
  float** outputChannels;
  int numInputChannels, numOutputChannels, numFrames;

private:
};

class AudioCallback : public juce::AudioSource {
public:
  explicit AudioCallback (float sampleRate,
                          int startMs = 0,
                          int endMs = 1000, 
                          const std::string& fileName = ".")
    : Fs (sampleRate) {
    startFrame = msToSamples ((int) Fs, startMs);
    endFrame = msToSamples ((int) Fs, endMs);
    writePath = fileName;
  }

  void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override {
    juce::ignoreUnused (samplesPerBlockExpected);
    Fs = static_cast<float> (sampleRate);
    prepare (static_cast<int> (Fs));
  }
  void releaseResources() override {}
  void getNextAudioBlock (
    const juce::AudioSourceChannelInfo& bufferToFill) override {
    processBlock (bufferToFill);
  }

  void initialiseFileWriter (int numChannels) {
#if WRITE_TO_FILE_MODE == 0
    juce::ignoreUnused (numChannels);
    return;
#elif WRITE_TO_FILE_MODE == 1 || WRITE_TO_FILE_MODE == 2
    for (auto i = 0u; i < numChannels; ++i) {
      std::string fileName = writePath + "/output_channel_" + std::to_string (i) + ".csv";
      fileWriter.emplace_back (std::make_unique<WriteToFile> (fileName, true));
    }
#elif WRITE_TO_FILE_MODE == 3 || WRITE_TO_FILE_MODE == 4
    for (auto i = 0u; i < numChannels; ++i) {
      std::string inputFileName = writePath + "/input_channel_" + std::to_string (i) + ".csv";
      fileWriter.emplace_back (std::make_unique<WriteToFile> (inputFileName, true));
      std::string outputFileName = writePath + "/output_channel_" + std::to_string (i) + ".csv";
      fileWriter.emplace_back (std::make_unique<WriteToFile> (outputFileName, true));
    }
#endif
  }

  virtual void process (AudioBuffer buffer) = 0;
  virtual void prepare (int sampleRate) = 0;

private:
  float Fs;

  //TODO naamgeving
  int startFrame { 0 };
  int endFrame { 0 };
  int currentFrame { 0 };

  std::string writePath = "0";
  std::vector<std::unique_ptr<WriteToFile>> fileWriter;


  int msToSamples (int sampleRate, int milliseconds) {
    return (sampleRate * milliseconds) / 1000;
  }

  enum class WriteMode { INPUT, OUTPUT };
  void writeBlock (AudioBuffer buffer, WriteMode mode) {
    auto [inputChannels,
          outputChannels,
          numInputChannels,
          numOutputChannels,
          numFrames] = buffer;

    int numChannelsToWrite = (mode == WriteMode::INPUT) ? numInputChannels : numOutputChannels;
    const float* const* channelsToWrite = (mode == WriteMode::INPUT) ? inputChannels : outputChannels;

    int fileWriterOffset = 0;
#if WRITE_TO_FILE_MODE == 3 || WRITE_TO_FILE_MODE == 4
    fileWriterOffset = (mode == WriteMode::INPUT) ? 0 : numInputChannels;
#endif
    for (int channel = 0; channel < numChannelsToWrite; channel++) {
      for (int i = 0; i < numFrames; i++) {
        int globalFrameIndex = currentFrame + i;

        if (globalFrameIndex >= startFrame && globalFrameIndex < endFrame) {
          fileWriter[channel + fileWriterOffset]->write (std::to_string (channelsToWrite[channel][i])
                                                        + "\n");
        }
      }
    }
    currentFrame += numFrames;
  }

  void clearOutput(AudioBuffer buffer) {
    auto [inputChannels,
          outputChannels,
          numInputChannels,
          numOutputChannels,
          numFrames] = buffer;

    for (int channel = 0; channel < numOutputChannels; channel++) {
      for (int sample = 0; sample < numFrames; sample++) {
        outputChannels[channel][sample] = 0.0f;
      }
    }
  }

  void processBlock (const juce::AudioSourceChannelInfo& bufferToFill) {
    const auto buffer =
      AudioBuffer { .inputChannels = const_cast<const float**> (
                      bufferToFill.buffer->getArrayOfReadPointers()),
                    .outputChannels = const_cast<float**> (
                      bufferToFill.buffer->getArrayOfWritePointers()),
                    .numInputChannels = bufferToFill.buffer->getNumChannels(),
                    .numOutputChannels = bufferToFill.buffer->getNumChannels(),
                    .numFrames = bufferToFill.buffer->getNumSamples() };

#if WRITE_TO_FILE_MODE == 3 || WRITE_TO_FILE_MODE == 4
    writeBlock (buffer, WriteMode::INPUT);
#endif

    process (buffer);

#if WRITE_TO_FILE_MODE == 1 || WRITE_TO_FILE_MODE == 3 
    writeBlock (buffer, WriteMode::OUTPUT); 
    clearOutput(buffer);
#endif

#if WRITE_TO_FILE_MODE == 2 || WRITE_TO_FILE_MODE == 4
    writeBlock (buffer, WriteMode::OUTPUT);
#endif

  }
};

struct ScopedMessageThreadEnabler {
  ScopedMessageThreadEnabler() { juce::initialiseJuce_GUI(); }
  ~ScopedMessageThreadEnabler() { juce::shutdownJuce_GUI(); }
};


class JUCEModule {
public:
  explicit JUCEModule (AudioCallback& callback) : _callback (callback) {
    audioSourcePlayer.setSource (&_callback);
    audioDeviceManager.addAudioCallback (&audioSourcePlayer);
  }

  ~JUCEModule() { audioDeviceManager.removeAudioCallback (&audioSourcePlayer); }

  void init (int numInputChannels, int numOutputChannels) {
#if AUDIO_DEVICE_MODE == 0
    {
      auto error = audioDeviceManager.initialiseWithDefaultDevices (numInputChannels,
                                                                    numOutputChannels);
      if (error.isNotEmpty()) {
        std::cerr << "Error initialising default audio device: " << error << std::endl;
        std::exit(1);
      }
    }
#elif AUDIO_DEVICE_MODE == 1
    auto useDefaults = false;
    
    auto& deviceTypes = audioDeviceManager.getAvailableDeviceTypes();
    
    std::cout << "Available audio device types:" << std::endl;
    for (int i = 0; i < deviceTypes.size(); ++i) {
      std::cout << "  " << i << ": " << deviceTypes[i]->getTypeName() << std::endl;
    }
    
    std::cout << "Select device type (0-" << deviceTypes.size() - 1 << "): ";
    int typeIndex;
    if (!(std::cin >> typeIndex) || typeIndex < 0 || typeIndex >= deviceTypes.size()) {
      std::cout << "Invalid input >:- (), using default device." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      useDefaults = true;
    }
    
    if (!useDefaults) {
      audioDeviceManager.setCurrentAudioDeviceType (deviceTypes[typeIndex]->getTypeName(), true);
      
      auto* currentType = audioDeviceManager.getCurrentDeviceTypeObject();
      if (currentType != nullptr) {
        auto outputDevices = currentType->getDeviceNames (false);
        std::cout << "\nAvailable output devices:" << std::endl;
        for (int i = 0; i < outputDevices.size(); ++i) {
          std::cout << "  " << i << ": " << outputDevices[i] << std::endl;
        }
        
        std::cout << "Select output device (0-" << outputDevices.size() - 1 << "): ";
        int outputIndex;
        if (!(std::cin >> outputIndex) || outputIndex < 0 || outputIndex >= outputDevices.size()) {
          std::cout << "Invalid input >:- (), using default device." << std::endl;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          useDefaults = true;
        }
        
        if (!useDefaults) {
          auto inputDevices = currentType->getDeviceNames (true);
          std::cout << "\nAvailable input devices:" << std::endl;
          for (int i = 0; i < inputDevices.size(); ++i) {
            std::cout << "  " << i << ": " << inputDevices[i] << std::endl;
          }
          
          std::cout << "Select input device (0-" << inputDevices.size() - 1 << "): ";
          int inputIndex;
          if (!(std::cin >> inputIndex) || inputIndex < 0 || inputIndex >= inputDevices.size()) {
            std::cout << "Invalid input >:- (), using default device." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            useDefaults = true;
          }
          
          if (!useDefaults) {
            juce::AudioDeviceManager::AudioDeviceSetup setup;
            setup.outputDeviceName = outputDevices[outputIndex];
            setup.inputDeviceName = inputDevices[inputIndex];
            setup.sampleRate = 0;
            setup.bufferSize = 0;
            setup.inputChannels.setRange (0, numInputChannels, true);
            setup.outputChannels.setRange (0, numOutputChannels, true);
            setup.useDefaultInputChannels = false;
            setup.useDefaultOutputChannels = false;
            
            auto error = audioDeviceManager.setAudioDeviceSetup (setup, true);
            if (error.isNotEmpty()) {
              std::cerr << "Error setting up audio device: " << error << std::endl;
              std::exit(1);
            }
          }
        }
      } else {
        useDefaults = true;
      }
    }
    
    if (useDefaults) {
      auto error = audioDeviceManager.initialiseWithDefaultDevices (numInputChannels, numOutputChannels);
      if (error.isNotEmpty()) {
        std::cerr << "Error initialising default audio device: " << error << std::endl;
        std::exit(1);
      }
    }
#endif
    _callback.initialiseFileWriter (numOutputChannels);
  }

private:
  AudioCallback& _callback;
  juce::AudioDeviceManager audioDeviceManager;
  juce::AudioSourcePlayer audioSourcePlayer;
};
