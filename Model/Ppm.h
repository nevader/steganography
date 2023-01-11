#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Pixels.h"
#include "Image.h"

using namespace std;

#ifndef STEGANOGRAPHY_PPM_H
#define STEGANOGRAPHY_PPM_H

class Ppm : public Image {

private:

    string magicNumber;
    int maxColor;

public:

 /**
 * @brief Write image data to a PPM file.
 * This function writes the image data stored in the object to a PPM file with the given file name.
 * If the file already exists, it will be overwritten.
 *
 * @param fileName The name of the file to write to.
 */
    void writeImage(const char *fileName) override;

 /**
 * @brief Loads an image in PPM format from a file and reads the
 * magic number, width, height, and maximum color value from the
 * first few lines. It then checks if the image is encoded in ASCII format, and returns `false` if it is not.
 *
 * @param fileName The name of the file from which to load the image.
 *
 * @return `true` if the image was successfully loaded, `false` otherwise.
 */
    bool loadImage(const char *fileName) override;

 /**
 * @brief Returns whether the PPM file is stored in ASCII format.
 * PPM files can be stored in either ASCII or binary format.
 *
 * @return True if the PPM file is stored in ASCII format, false if it is
 * stored in binary format.
 */
    bool isAsciiEncoded();

};


#endif //STEGANOGRAPHY_PPM_H
