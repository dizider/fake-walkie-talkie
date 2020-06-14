//
// Created by Matěj Jehlička on 6/14/20.
//

#include "LedController.h"

void LedController::show(int red, int green, int blue) {
    this->actColor = Color(red, green, blue);
}

void LedController::show(Color color) {
    this->actColor = color;
}

LedController * LedController::init() {
    return new LedController();
}

LedController * LedController::init(Color color) {
    return new LedController(color);
}
