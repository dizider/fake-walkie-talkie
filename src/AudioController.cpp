//
// Created by Matěj Jehlička on 6/14/20.
//

#include "AudioController.h"

AudioController *AudioController::init() {
    Serial.println("AUDIO CONTROLLER");
    Serial.println("----------------");

    auto *audioController = new AudioController();
    audioController->tmrpcm.speakerPin = SPEAKER_PIN;

    if (!SD.begin(SD_CS)) {
        Serial.println("SD fail");
        return nullptr;
    }

    audioController->tmrpcm.setVolume(VOLUME);
    return audioController;
}

void AudioController::play() {
    tmrpcm.play(fileName);
}

bool AudioController::playFile(char *file) {
    fileName = file;
    tmrpcm.play(file);
    return true;
}

char *AudioController::getFileName() const {
    return fileName;
}

void AudioController::openFile(char *file) {
    fileName = file;
}
