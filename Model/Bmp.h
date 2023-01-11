//
// Created by Nevader on 04.12.2022.
//

#ifndef STEGANOGRAPHY_BMP_H
#define STEGANOGRAPHY_BMP_H

#include <vector>
#include "BmpHeader.h"
#include "Pixels.h"
#include "Image.h"

using namespace std;


class Bmp : public Image {
private:

    bmpFileHeader fileHeader{};
    bmpInfoHeader infoHeader{};
    int bitsPerPixel{};

public:

/**
 * @brief Loads an image from a BMP file and stores it in memory.
 *
 * @param filePath The path to the BMP file to be loaded.
 * @return True if the image was successfully loaded, false otherwise.
 */
    bool loadImage(const char *filePath) override;

 /**
 * @brief Writes the image stored in the Bmp object to a BMP file.
 *
 * @param filePath The name of the BMP file to write the image to.
 */
    void writeImage(const char *filePath) override;

    int getBitsPerPixel() const;

};


#endif //STEGANOGRAPHY_BMP_H
