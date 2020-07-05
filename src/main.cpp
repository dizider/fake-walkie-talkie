#include <Arduino.h>
#include "AudioController.h"
#include "RF24Checker.h"

AudioController *audioController;
RF24Checker *rf24Checker;

void setup() {
    Serial.begin(9600);
    Serial.println("Fake walkie-talkie");
    rf24Checker = RF24Checker::init(RF_CS, RF_CE);
    audioController = AudioController::init();

    if (audioController != nullptr) {
        Serial.println("* SD CARD OK");
        audioController->openFile(FILE_NAME);
    } else
        Serial.println("! SD CARD FAILED");


    if (rf24Checker->test())
        Serial.println("* RF24 OK");
    else
        Serial.println("! RF24 FAILED");
}

void loop() {
    if (rf24Checker->check()) {
        audioController->play();
    }
}