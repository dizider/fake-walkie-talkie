//
// Created by Matěj Jehlička on 6/14/20.
//

#include "AudioController.h"

AudioController *AudioController::init() {
    auto *audioController = new AudioController();
    audioController->tmrpcm.speakerPin = SPEAKER_PIN;

    if (!SD.begin(SD_CS))
        return nullptr;

    audioController->tmrpcm.setVolume(VOLUME);
    return audioController;
}

void AudioController::play() {
    tmrpcm.play(fileName);
}

void AudioController::openFile(char *file) {
    fileName = file;
}
