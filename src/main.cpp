#include <Arduino.h>
#include "AudioController.h"
#include "RF24Checker.h"

AudioController *audioController;
RF24Checker *rf24Checker;

int soundTackCounter = 1;

void setup() {
    Serial.begin(9600);
    Serial.println("Fake walkie-talkie");
    Serial.println("------------------");
    rf24Checker = RF24Checker::init(RF_CS, RF_CE);
    audioController = AudioController::init();

    if (audioController != nullptr) {
        Serial.println("* SD CARD OK");
    } else
        Serial.println("! SD CARD FAILED");


    if (rf24Checker->test())
        Serial.println("* RF24 OK");
    else
        Serial.println("! RF24 FAILED");

    rf24Checker->resetAddresses();
}

void loop() {

    digitalWrite(redLedPin, LOW);

    if (rf24Checker->check()) {
        String fileName = "";
        fileName.concat(soundTackCounter);
        fileName.concat(".wav");

        audioController->openFile(fileName.c_str());
        audioController->play();

        Serial.print(fileName);
        Serial.println(" is playing.");
    }

    while (audioController->isPlaying()) {
        digitalWrite(redLedPin, HIGH);
    }

    soundTackCounter++;
}