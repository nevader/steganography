//
// Created by Nevader on 04.12.2022.
//

#include "Bmp.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <bitset>


bool Bmp::loadImage(const char *filePath) {

    ifstream file;
    file.open(filePath, ios::in | ios::binary);

    file.read((char *) &fileHeader, sizeof(bmpFileHeader));
    file.read((char *) &infoHeader, sizeof(bmpInfoHeader));


    width = infoHeader.width;
    height = infoHeader.height;

    if (infoHeader.bitsPerPixel != 24) {
        bitsPerPixel = infoHeader.bitsPerPixel;
        return false;
    }

    pixels.setWidth(width);
    pixels.setPixelArraySize(width, height);

    const int padding_amount = ((4 - (width * 3) % 4) % 4);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            BYTE colors[3];
            file.read((reinterpret_cast<char *>(colors)), 3);
            pixels.setColor(RED, colors[2], x, y);
            pixels.setColor(BLUE, colors[1], x, y);
            pixels.setColor(GREEN, colors[0], x, y);
        }
        file.ignore(padding_amount);
    }
    file.close();
    return true;
}


void Bmp::writeImage(const char *filePath) {

    ofstream file;

    file.open(filePath, ios::out | ios::binary);

    BYTE padding_array[3] = {0, 0, 0};
    const int padding_amount = ((4 - (width * 3) % 4) % 4);

    BYTE fh[sizeof(bmpFileHeader)];
    memcpy(fh, &fileHeader, sizeof(bmpFileHeader));

    BYTE fi[sizeof(bmpInfoHeader)];
    memcpy(fi, &infoHeader, sizeof(bmpInfoHeader));

    file.write(reinterpret_cast<char *>(fh), sizeof(bmpFileHeader));
    file.write(reinterpret_cast<char *>(fi), sizeof(bmpInfoHeader));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            auto r = static_cast<unsigned char>(pixels.getColor(RED, x, y));
            auto b = static_cast<unsigned char>(pixels.getColor(BLUE, x, y));
            auto g = static_cast<unsigned char>(pixels.getColor(GREEN, x, y));

            unsigned char colors[] = {g, b, r};
            file.write(reinterpret_cast<char *>(colors), 3);
        }

        file.write(reinterpret_cast<char *>(padding_array), padding_amount);
    }
    file.close();
}

int Bmp::getBitsPerPixel() const {
    return bitsPerPixel;
}




