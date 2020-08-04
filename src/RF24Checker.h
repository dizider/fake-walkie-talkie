//
// Created by Matěj Jehlička on 05.07.20.
//

#ifndef FAKE_WALKIE_TALKIE_RF24CHECKER_H
#define FAKE_WALKIE_TALKIE_RF24CHECKER_H

#include "SPI.h"
#include "RF24.h"

const byte testAddr[][5] = {{0x22, 0x22, 0x22, 0x22, 0x22},
                            {0x11, 0x11, 0x11, 0x11, 0x11},
                            {0x25, 0x58, 0x99, 0x97, 0x76}};

class RF24Checker {
public:
    /**
     * Initialize new instance of checker.
     *
     * @return new instance of checker
     * */
    static RF24Checker *init(int CS, int CE);

    /**
     * Check if RF24 is connected correctly. Return TRUE if device wiring
     * is correct.
     *
     * @return true - device is connected correctly
     * @return false - device is connected incorrectly
     * */
    bool check() const;

    /**
     *
     * */
    bool test();

    void resetAddresses();

private:
    /**
     * Default constructor initialize CS and CE pin.
     * */
    RF24Checker(int CS, int CE) : CS(CS), CE(CE), radio(CS, CE) {
        radio.begin();
    }

    bool wiringCorrect = false;
    const int CS;
    const int CE;
    RF24 radio;
};


#endif //FAKE_WALKIE_TALKIE_RF24CHECKER_H
