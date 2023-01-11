//
// Created by Nevader on 25.12.2022.
//

#ifndef STEGANOGRAPHY_ARGUMENTCONTROLLER_H
#define STEGANOGRAPHY_ARGUMENTCONTROLLER_H

#include <cstring>
#include <iostream>
#include "../model/Ppm.h"
#include "../model/Message.h"
#include "../model/Bmp.h"
#include "../View/CommandLineInterface.h"
#include "../Enums/Extension.h"
#include <sys/stat.h>
#include <ctime>

using namespace std;


class ArgumentController {

private:
    CommandLineInterface ui;
    Ppm ppm;
    Bmp bmp;
    Message message;

public:

    explicit ArgumentController(CommandLineInterface &ui);

    void help(const string &fileName);

    void info(char *filePath);

    void encrypt(char *filePath, char *messageToEncrypt);

    void decrypt(char *filePath);

    void check(char *filePath, const char *messageToEncrypt);

    /**
* @brief Extracts the file extension from a file path.
* @param filePath The file path from which the extension should be extracted.
* @return The file extension as a string.
*/
    string getFileExtensionToString(const char *filePath);

    bool isFileExisting(char *filePath);

/**
@brief Check the file extension of the given file path
@param filePath The file path of the image to check
@return Extension The file extension as enumeration (PPM, BMP, NOT_SUPPORTED)
*/
    Extension fileCheck(char *filePath);

};


#endif //STEGANOGRAPHY_ARGUMENTCONTROLLER_H
