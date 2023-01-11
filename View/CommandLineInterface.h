#ifndef STEGANOGRAPHY_COMMANDLINEINTERFACE_H
#define STEGANOGRAPHY_COMMANDLINEINTERFACE_H

#include <iostream>
#include "../ENUMS/Flag.h"
#include "../Enums/Error.h"
#include "../Enums/Extension.h"
#include "../Model/BmpHeader.h"
#include <ctime>

using namespace std;

class CommandLineInterface {

public:
    void generateAscii(Flag flag) const;

    void printFlagError(Error error, Flag flag, const string &reason) const;

    void printArgumentError(char *file_path, Error error, const string &reason) const;

    string errorEnumToString(Error error) const;

    void printHelp(const string &file_name) const;

    void printEncrypt() const;

    void printDecrypt(const string &message) const;

    void printInfo(int width, int height, time_t timeStamp, int size, char *file_path, Extension extension) const;

    void printCheck(BYTE_4 messageFlag, BYTE_4 maxMessageSize, BYTE_4 messageToEncryptLength) const;

};


#endif //STEGANOGRAPHY_COMMANDLINEINTERFACE_H
