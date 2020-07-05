//
// Created by Matěj Jehlička on 05.07.20.
//

#include "RF24Checker.h"

RF24Checker *RF24Checker::init(int CS, int CE) {
    auto *rf24Checker = new RF24Checker(CS, CE);
    return rf24Checker;
}

bool RF24Checker::check() const {
    return wiringCorrect;
}

long RF24Checker::getAddress() {
    return this->radio.getTXAddr();
}

bool RF24Checker::test() {
    auto *buffer = new uint8_t[5];
    radio.openWritingPipe(testAddr[1]);
    radio.openReadingPipe(1, testAddr[2]);

    radio.getTXAddr(buffer);
    for (int i = 4; i >= 0; i--) {
        if (buffer[i] != testAddr[1][i]) {
            return false;
        }
    }

    radio.getRX0Addr(buffer);
    for (int i = 4; i >= 0; i--) {
        if (buffer[i] != testAddr[2][i]) {
            return false;
        }
    }
    wiringCorrect = true;
    return true;
}
