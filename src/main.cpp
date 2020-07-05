#include <Arduino.h>
#include "AudioController.h"
#include "RF24Checker.h"

AudioController *audioController;
RF24Checker *rf24Checker;

void setup(){
    Serial.begin(9600);
    Serial.println("Fake walkie-talkie");
    rf24Checker = RF24Checker::init(RF_CS, RF_CE);
    audioController = AudioController::init();
    audioController->openFile(FILE_NAME);
    Serial.println(rf24Checker->getAddress(), HEX);
}

void loop(){
    if(rf24Checker->check()){
        audioController->play();
    }
}