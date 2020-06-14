#include <Arduino.h>
#include "wiring.h"
#include "AudioController.h"
#include "LedController.h"

AudioController *audioController;
LedController *ledController;

void setup() {
    audioController = AudioController::init(SD_CS);
    audioController->openFile(FILE_NAME);

    ledController = LedController::init();
}

void loop(void) {

    audioController->play();

//    while(!audioController.isStopped()){
//        //playing
//    }

}