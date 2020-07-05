//
// Created by Matěj Jehlička on 05.07.20.
//

#include "RF24Checker.h"

RF24Checker *RF24Checker::init(int CS, int CE) {
    RF24Checker *rf24Checker = new RF24Checker(CS, CE);
    return rf24Checker;
}

bool RF24Checker::check() {
    return false;
}

long RF24Checker::getAddress() {
    return this->radio.getTXAddr();
}
