//
// Created by Matěj Jehlička on 05.07.20.
//

#ifndef FAKE_WALKIE_TALKIE_RF24CHECKER_H
#define FAKE_WALKIE_TALKIE_RF24CHECKER_H

//#include "printf.h"
#include "SPI.h"
#include "RF24.h"

class RF24Checker {
public:
    /**
     * Initialize new instance of checker.
     *
     * @return new instance of checker
     * */
    static RF24Checker *init(int CS, int CE);

    /**
     * Check if RF24 is connected correctly. Return TRUE if device
     * MAC is not 0x00 otherwise return FALSE.
     *
     * @return true - device is connected correctly
     * @return false - device is connected incorrectly
     * */
    bool check();

private:
    /**
     * Default constructor initialize CS and CE pin.
     * */
    RF24Checker(int CS, int CE) : CS(CS), CE(CE), radio(CS, CE) {
        radio.begin();
    }

public:
    long getAddress();

private:
    long address;
    const int CS;
    const int CE;
    RF24 radio;
};


#endif //FAKE_WALKIE_TALKIE_RF24CHECKER_H
