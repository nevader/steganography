//
// Created by Krzysiek on 19.12.2022.
//

#include "Image.h"

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

Pixels &Image::getPixels() {
    return pixels;
}
