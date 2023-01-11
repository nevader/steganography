//
// Created by Nevader on 17.12.2022.
//

#include <cstring>
#include "Message.h"
#include "Image.h"
#include <bitset>
#include <iostream>

using namespace std;


void Message::writeMessage(const char *message, Image &image) {

    char flagString[] = {'s', 'i', 'z', 'e'};

    unsigned int messageLengthInBytes = strlen(message);
    unsigned int messageLengthInBits = (messageLengthInBytes * 8);

    bitset<sizeof(BYTE_4) * 8> messageLength{messageLengthInBits};

    messageLengthInBits += 64;

    bool messageToBitsArray[messageLengthInBits];

    int currentIndex = 0;


    for (int i = 0; i < 4; ++i) {
        for (int j = 7; j >= 0; --j) {
            messageToBitsArray[currentIndex] = getBit(flagString[i], j);
            currentIndex++;
        }
    }

    for (int i = 0; i < 32; ++i) {
        messageToBitsArray[currentIndex] = messageLength.test(32 - 1 - i);
        currentIndex++;
    }


    for (int i = 0; i < messageLengthInBytes; ++i) {
        for (int j = 7; j >= 0; --j) {
            messageToBitsArray[currentIndex] = getBit(message[i], j);
            currentIndex++;
        }
    }


    currentIndex = 0;

    for (int y = 0; y < image.getWidth() && currentIndex < messageLengthInBits; ++y) {
        for (int x = 0; x < image.getHeight() && currentIndex < messageLengthInBits; ++x) {

            RBG rbg = image.getPixels().getRbg(x, y);


            rbg.red = modifyBit(rbg.red, 1, messageToBitsArray[currentIndex]);
            currentIndex++;
            rbg.red = modifyBit(rbg.red, 0, messageToBitsArray[currentIndex]);
            currentIndex++;


            rbg.blue = modifyBit(rbg.blue, 1, messageToBitsArray[currentIndex]);
            currentIndex++;
            rbg.blue = modifyBit(rbg.blue, 0, messageToBitsArray[currentIndex]);
            currentIndex++;


            rbg.green = modifyBit(rbg.green, 1, messageToBitsArray[currentIndex]);
            currentIndex++;
            rbg.green = modifyBit(rbg.green, 0, messageToBitsArray[currentIndex]);
            currentIndex++;

            image.getPixels().setRbg(rbg, x, y);
        }
    }
}


string Message::readMessage(Image &image) {

    int bitOffset = 64;
    BYTE_4 getSize = getFlag(image) + bitOffset;
    bool size_text[getSize];

    int current_index = 0;

    for (int y = 0; y < image.getWidth() && current_index < getSize; ++y) {
        for (int x = 0; x < image.getHeight() && current_index < getSize; ++x) {

            RBG rbg = image.getPixels().getRbg(x, y);

            size_text[current_index] = getBit(rbg.red, 1);
            current_index++;
            size_text[current_index] = getBit(rbg.red, 0);
            current_index++;

            size_text[current_index] = getBit(rbg.blue, 1);
            current_index++;
            size_text[current_index] = getBit(rbg.blue, 0);
            current_index++;

            size_text[current_index] = getBit(rbg.green, 1);
            current_index++;
            size_text[current_index] = getBit(rbg.green, 0);
            current_index++;
        }
    }

    string text;
    string out;

    for (int i = 64; i < getSize; ++i) {
        text += to_string(size_text[i]);
    }

    do {
        string byte = text.substr(0, 8);  // Get eight "bits"

        out += (char) stoi(byte, nullptr, 2);  // Convert and output to file

        text = text.substr(8);  // The remaining bits
    } while (!text.empty());

    return out;


}

BYTE_4 Message::getFlag(Image &image) {

    bool size_text[64];
    int current_index = 0;

    for (int y = 0; y < image.getWidth() && current_index < 64; ++y) {
        for (int x = 0; x < image.getHeight() && current_index < 64; ++x) {

            RBG rbg = image.getPixels().getRbg(x, y);

            size_text[current_index] = getBit(rbg.red, 1);
            current_index++;
            size_text[current_index] = getBit(rbg.red, 0);
            current_index++;

            size_text[current_index] = getBit(rbg.blue, 1);
            current_index++;
            size_text[current_index] = getBit(rbg.blue, 0);
            current_index++;

            size_text[current_index] = getBit(rbg.green, 1);
            current_index++;
            size_text[current_index] = getBit(rbg.green, 0);
            current_index++;
        }
    }

    string text;
    string out;

    for (int i = 0; i < 32; ++i) {
        text += to_string(size_text[i]);
    }

    do {
        std::string byte = text.substr(0, 8);  // Get eight "bits"

        out += (char) stoi(byte, nullptr, 2);  // Convert and output to file

        text = text.substr(8);  // The remaining bits
    } while (!text.empty());

    if (out != "size") {
        return -1;
    }

    for (int i = 32; i < 64; ++i) {
        text += to_string(size_text[i]);
    }

    bitset<32> lol(text);

    return lol.to_ulong();
}

BYTE Message::modifyBit(int input, int position, bool newBit) {
    BYTE mask = 1 << position;
    return ((input & ~mask) | (newBit << position));
}

bool Message::getBit(unsigned char byte, int position) {
    return (byte >> position) & 1;
}

BYTE_4 Message::getMaxLength(Image &image) {
    return ((image.getWidth() * image.getHeight() * 3) - 64) / 8;
}

bool Message::canWriteMessage(const char *message, Image &image) {
    string mess = message;
    BYTE_4 messageLength = mess.length();

    return getMaxLength(image) >= messageLength;
}

