//
// Created by Matěj Jehlička on 6/14/20.
//

#ifndef FAKE_WALKIE_TALKIE_WIRING_H
#define FAKE_WALKIE_TALKIE_WIRING_H

#include <Arduino.h>

const int SD_CS = 4; //SD card's CS pin
const int SPEAKER_PIN = 9;
const int VOLUME = 6;

//Playback file name
const char FILE_NAME[] = "example.wav";

const int redLedPin = 1;
const int greenLedPin = 1;
const int blueLedPin = 1;

#endif //FAKE_WALKIE_TALKIE_WIRING_H
