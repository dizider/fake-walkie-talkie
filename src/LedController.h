//
// Created by Matěj Jehlička on 6/14/20.
//

#ifndef FAKE_WALKIE_TALKIE_LEDCONTROLLER_H
#define FAKE_WALKIE_TALKIE_LEDCONTROLLER_H

#include <Arduino.h>

struct Color {
    Color(int red, int green, int blue) : red(red), green(green), blue(blue) {}

    void print() const {
        Serial.print(red);
        Serial.print(" - ");
        Serial.print(green);
        Serial.print(" - ");
        Serial.print(blue);
    }

    int red;
    int green;
    int blue;
};

class LedController {
public:

    static LedController * init();
    static LedController * init(Color color);

    /**
     * Show RGB color on led.
     *
     * @param red - red color 0 - 255
     * @param green - green color 0 - 255
     * @param blue - blue color 0 - 255
     * */
    void show(int red, int green, int blue);

    void show(Color color);

private:

    LedController(Color color): actColor(color){}

    LedController(): actColor(0,0,0){}

    Color actColor;
};


#endif //FAKE_WALKIE_TALKIE_LEDCONTROLLER_H
