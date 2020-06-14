//
// Created by Matěj Jehlička on 6/14/20.
//

#ifndef FAKE_WALKIE_TALKIE_AUDIOCONTROLLER_H
#define FAKE_WALKIE_TALKIE_AUDIOCONTROLLER_H

class AudioController {
public:
    static AudioController * init(int SD_CS);

    bool openFile(char *file);

    bool isStopped();

    void play();

    bool playFile(char *file);

    char *getFileName() const;

private:
    char *fileName;
};


#endif //FAKE_WALKIE_TALKIE_AUDIOCONTROLLER_H
