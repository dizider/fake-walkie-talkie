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

void AudioController::openFile(const char *file) {
    fileName = file;
}

bool AudioController::isPlaying() {
    return tmrpcm.isPlaying();
}
