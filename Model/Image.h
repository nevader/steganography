//
// Created by Krzysiek on 19.12.2022.
//

#ifndef STEGANOGRAPHY_IMAGE_H
#define STEGANOGRAPHY_IMAGE_H


#include "Pixels.h"

class Image {
protected:

    int width{};
    int height{};
    Pixels pixels;

public:

    virtual bool loadImage(const char *filePath) = 0;

    virtual void writeImage(const char *filePath) = 0;

    int getWidth() const;

    int getHeight() const;

    Pixels &getPixels();
};


#endif //STEGANOGRAPHY_IMAGE_H
