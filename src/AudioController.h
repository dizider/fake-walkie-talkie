//
// Created by Matěj Jehlička on 6/14/20.
//

#ifndef FAKE_WALKIE_TALKIE_AUDIOCONTROLLER_H
#define FAKE_WALKIE_TALKIE_AUDIOCONTROLLER_H

#include "wiring.h"
#include "SPI.h"
#include "SD.h"
#include "TMRpcm.h"

class AudioController {
public:
    static AudioController *init();

    void openFile(char *file);

    void play();

private:
    char *fileName;
    TMRpcm tmrpcm;
};


#endif //FAKE_WALKIE_TALKIE_AUDIOCONTROLLER_H
