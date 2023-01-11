//
// Created by Nevader on 17.12.2022.
//

#ifndef STEGANOGRAPHY_MESSAGE_H
#define STEGANOGRAPHY_MESSAGE_H


#include <string>
#include "BmpHeader.h"
#include "Image.h"

class Message {

public:

/**
 * @brief Encodes a message in an image by modifying two least significant bits of the pixel values.
 *
 * @param message The message to be encoded in the image.
 * @param image The image in which to encode the message.
 */
    void writeMessage(const char *message, Image &image);

/**
 * @brief Extracts a message from an image by reading two least significant bits of the pixel values.
 *
 * @param image The image from which to extract the message.
 *
 * @return The message embedded in the image, as a string.
 */
    string readMessage(Image &image);

    /**
 * @brief This function reads the first 64 bits from least significant bits of the red, blue,
 * and green channels of each pixel in the image. The first 32 bits are
 * reserved for the "size" flag, which indicates the presence of an encoded message in the image. If the flag is not
 * present, the function returns -1. Otherwise, it extracts the size of the message from the following 32 bits and
 * returns it as an unsigned long.
   *
 * @param image The image from which to extract the size of the message.
 *
 * @return The size of the message, in bits. If the "size" flag is not present, the function returns -1.
 */
    BYTE_4 getFlag(Image &image);

/**
 * @brief Calculates the maximum message length that can be stored in an image.
 *
 * @param image The image for which to calculate the maximum message length.
 *
 * @return The maximum message length, in bytes.
 */
    BYTE_4 getMaxLength(Image &image);

/**
 * @brief Determines whether a message can be stored in an image.
 *
 * @param message The message to store.
 * @param image The image in which to store the message.
 *
 * @return `true` if the message can be stored in the image, `false` otherwise.
 */
    bool canWriteMessage(const char *message, Image &image);

/**
 * @brief Extracts a single bit from a byte.
 *
 * @param byte The byte from which to extract the bit.
 * @param position The position of the bit to extract, where 0 is the least significant bit and 7 is the most significant
 * bit.
 *
 * @return The value of the extracted bit, as a boolean.
 */
    bool getBit(unsigned char byte, int position);

/**
 * @brief Modifies a single bit in a byte.
 *
 * @param input The input byte.
 * @param position The position of the bit to modify, where 0 is the least significant bit and 7 is the most significant
 * bit.
 * @param newBit The new value of the bit.
 *
 * @return The modified byte.
 */
    BYTE modifyBit(int input, int position, bool newBit);

};


#endif //STEGANOGRAPHY_MESSAGE_H
