//
// Created by Krzysiek on 05.12.2022.
//

#ifndef STEGANOGRAPHY_BMPHEADER_H
#define STEGANOGRAPHY_BMPHEADER_H


typedef unsigned char BYTE;
typedef unsigned short BYTE_2;
typedef unsigned int BYTE_4;


#pragma pack(push, 1)
/**
 * @brief Represents the file header of a BMP file.
 *
 * The file header contains information about the size and layout of the BMP file.
 */
struct bmpFileHeader {

    BYTE_2 fileType;
    BYTE_4 fileSize;
    BYTE_2 reserved1;
    BYTE_2 reserved2;
    BYTE_4 pixelsOffset;

};
#pragma pack(pop)


#pragma pack(push, 1)
/**
 * @brief Represents the info header of a BMP file.
 *
 * The info header contains information about the dimensions and color depth of the image data in the BMP file.
 */
struct bmpInfoHeader {

    BYTE_4 headerSize;
    BYTE_4 width;
    BYTE_4 height;
    BYTE_2 planes;
    BYTE_2 bitsPerPixel;
    BYTE_4 compression;
    BYTE_4 imageSize;
    BYTE_4 xPixelsPerMeter;
    BYTE_4 yPixelsPerMeter;
    BYTE_4 colorsUsed;
    BYTE_4 colorsImportant;

};
#pragma pack(pop)

#endif //STEGANOGRAPHY_BMPHEADER_H
