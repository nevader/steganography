//
// Created by Nevader on 14.12.2022.
//

#ifndef STEGANOGRAPHY_PIXELS_H
#define STEGANOGRAPHY_PIXELS_H

#include "BmpHeader.h"
#include <vector>

using namespace std;

enum COLOR {
    RED = 1,
    BLUE = 2,
    GREEN = 3
};

struct RBG {
    BYTE red;
    BYTE green;
    BYTE blue;

    RBG();

    RBG(BYTE r, BYTE g, BYTE b);
};

class Pixels {

private:
    vector<RBG> pixelsVector;
    int width;

public:
    /**
 * @brief Returns the RGB pixel values at a given position.
 *
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 *
 * @return The RGB pixel values at the specified position.
 */
    RBG getRbg(int x, int y);


/**
 * @brief Sets the RGB pixel values at a given position.
 *
 * @param rbg The new RGB pixel values, represented as an `RBG` struct.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 */
    void setRbg(RBG &rbg, int x, int y);

/**
 * @brief Returns the value of a given color channel for a pixel at a given position.
 *
 * @param color The color channel to retrieve. This can be one of the following values: <br>
 * - `RED`: the red channel <br>
 * - `BLUE`: the blue channel <br>
 * - `GREEN`: the green channel <br>
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 *
 * @return The value of the specified color channel for the pixel at the given position, as a byte (8-bit integer).
 */
    BYTE getColor(COLOR color, int x, int y);

/**
 * @brief Sets the value of a given color channel for a pixel at a given position.
 *
 * @param color The color channel to set. This can be one of the following values: <br>
 * - `RED`: the red channel <br>
 * - `BLUE`: the blue channel <br>
 * - `GREEN`: the green channel
 * @param value The new value for the color channel (0-255).
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 */
    void setColor(COLOR color, BYTE value, int x, int y);

/**
 * @brief Resizes the array of RGB pixel values to match a given image size.
 *
 * @param width The width of the image, in pixels.
 * @param height The height of the image, in pixels.
 */
    void setPixelArraySize(int width, int height);

    void setWidth(int width);
};


#endif //STEGANOGRAPHY_PIXELS_H
