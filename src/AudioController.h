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
    /**
     * Initialize new instance od AudioController class.
     *
     * @return new initialize instance of AudioController
     * */
    static AudioController *init();

    /**
     * Sets name of the file to be played.
     * */
    void openFile(const char *file);

    /**
     * Starts playback of prepared file (name saved in fileName)
     * */
    void play();

    /**
     * Check if playback is on.
     *
     * @return actual playback state
     * */
    bool isPlaying();

private:
    char *fileName;
    TMRpcm tmrpcm;
};


#endif //FAKE_WALKIE_TALKIE_AUDIOCONTROLLER_H
