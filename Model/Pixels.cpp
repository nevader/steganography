//
// Created by Nevader on 14.12.2022.
//

#include "Pixels.h"

RBG::RBG() {
    red = 0;
    green = 0;
    blue = 0;
}

RBG::RBG(BYTE r, BYTE g, BYTE b) {
    red = r;
    green = g;
    blue = b;
}

RBG Pixels::getRbg(int x, int y) {
    return pixelsVector[y * width + x];
}

void Pixels::setRbg(RBG &rbg, int x, int y) {
    pixelsVector[y * width + x].blue = rbg.blue;
    pixelsVector[y * width + x].green = rbg.green;
    pixelsVector[y * width + x].red = rbg.red;
}

BYTE Pixels::getColor(COLOR color, int x, int y) {

    switch (color) {
        case RED:
            return pixelsVector[y * width + x].red;
        case BLUE:
            return pixelsVector[y * width + x].blue;
        case GREEN:
            return pixelsVector[y * width + x].green;
    }
    return 0;
}

void Pixels::setColor(COLOR color, BYTE value, int x, int y) {

    switch (color) {
        case RED:
            pixelsVector[y * width + x].red = value;
            break;
        case BLUE:
            pixelsVector[y * width + x].blue = value;
            break;
        case GREEN:
            pixelsVector[y * width + x].green = value;
            break;
    }
}

void Pixels::setPixelArraySize(int width, int height) {
    pixelsVector.resize(width * height);
}

void Pixels::setWidth(int mWidth) {
    width = mWidth;
}







