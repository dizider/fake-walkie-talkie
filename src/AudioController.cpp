//
// Created by Matěj Jehlička on 6/14/20.
//

#include "AudioController.h"
#include "SimpleSDAudio.h"

AudioController * AudioController::init(int SD_CS) {
    auto *audioController = new AudioController();

    SdPlay.setSDCSPin(SD_CS);

    if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER)) {
        Serial.println("SD card init failed....");
    }

    return audioController;
}

bool AudioController::openFile(char *file) {
    if (!SdPlay.setFile(file)) {
        Serial.println("Read file failed....");
        return false;
    }
    this->fileName = file;
    return true;
}

bool AudioController::isStopped() {
    return SdPlay.isStopped();
}

void AudioController::play() {
    if (SdPlay.isStopped())
        SdPlay.play();
}

bool AudioController::playFile(char *file) {
    if (!openFile(file))
        return false;
    this->fileName = file;
    play();
    return true;
}

char *AudioController::getFileName() const {
    return fileName;
}
