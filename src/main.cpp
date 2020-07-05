#include <Arduino.h>
#include "AudioController.h"

AudioController *audioController;

void setup(){
    Serial.begin(9600);

    audioController = AudioController::init();
    audioController->openFile(FILE_NAME);
}

void loop(){
    audioController->play();
}