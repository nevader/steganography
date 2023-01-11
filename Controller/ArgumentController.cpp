//
// Created by Nevader on 25.12.2022.
//


#include "ArgumentController.h"

void ArgumentController::help(const string &fileName) {
    ui.printHelp(fileName);
}

void ArgumentController::encrypt(char *filePath, char *messageToEncrypt) {

    Extension extension = fileCheck(filePath);

    switch (extension) {

        case PPM:
            ppm.loadImage(filePath);
            if (message.canWriteMessage(messageToEncrypt, ppm)) {
                message.writeMessage(messageToEncrypt, ppm);
                ppm.writeImage(filePath);
                ui.printEncrypt();
            } else {
                ui.printArgumentError(filePath, MESSAGE_TO_LONG, "");
            }
            break;

        case BMP:
            if (bmp.loadImage(filePath)) {
            if (message.canWriteMessage(messageToEncrypt, bmp)) {
                message.writeMessage(messageToEncrypt, bmp);
                bmp.writeImage(filePath);
                ui.printEncrypt();
            } else {
                ui.printArgumentError(filePath, MESSAGE_TO_LONG, "");
            }
            } else {
                ui.printArgumentError(filePath, FILE_FORMAT, to_string(bmp.getBitsPerPixel()));
            }
            break;

        case NOT_SUPPORTED:
            ui.printArgumentError(filePath, FILE_EXTENSION, getFileExtensionToString(filePath));
            break;
    }
}

void ArgumentController::decrypt(char *filePath) {

    Extension extension = fileCheck(filePath);

    switch (extension) {

        case PPM:
            ppm.loadImage(filePath);
            if (message.getFlag(ppm) == -1) {
                ui.printArgumentError(filePath, NO_ENCODED_MESSAGE, "");
                break;
            } else {
                ui.printDecrypt(message.readMessage(ppm));
                break;
            }

        case BMP:
            bmp.loadImage(filePath);
            if (message.getFlag(bmp) == -1) {
                ui.printArgumentError(filePath, NO_ENCODED_MESSAGE, "");
                break;
            } else {
                ui.printDecrypt(message.readMessage(bmp));
                break;
            }

        case NOT_SUPPORTED:
            ui.printArgumentError(filePath, FILE_EXTENSION, getFileExtensionToString(filePath));
            break;
    }

}

void ArgumentController::info(char *filePath) {

    if (!isFileExisting(filePath)) {
        ui.printArgumentError(filePath, FILE_PATH, "");
        return;
    }

    Extension extension = fileCheck(filePath);


    struct stat file_stats{};

    switch (extension) {

        case PPM:
            if (ppm.loadImage(filePath)) {

                stat(filePath, &file_stats);
                ui.printInfo(ppm.getWidth(), ppm.getHeight(),
                             file_stats.st_mtime, file_stats.st_size, filePath, PPM);
            } else {
                stat(filePath, &file_stats);
                ui.printInfo(ppm.getWidth(), ppm.getHeight(),
                             file_stats.st_mtime, file_stats.st_size, filePath, NOT_SUPPORTED);
            }
            break;

        case BMP:
            if (bmp.loadImage(filePath)) {

                stat(filePath, &file_stats);
                ui.printInfo(bmp.getWidth(), bmp.getHeight(),
                             file_stats.st_mtime, file_stats.st_size, filePath, BMP);
            } else {
                stat(filePath, &file_stats);
                ui.printInfo(bmp.getWidth(), bmp.getHeight(),
                             file_stats.st_mtime, file_stats.st_size, filePath, NOT_SUPPORTED);
            }

            break;

        case NOT_SUPPORTED:
            ui.printArgumentError(filePath, FILE_EXTENSION, getFileExtensionToString(filePath));
            break;

    }
}

void ArgumentController::check(char *filePath, const char *messageToEncrypt) {

    if (!isFileExisting(filePath)) {
        ui.printArgumentError(filePath, FILE_PATH, "");
        return;
    }

    Extension extension = fileCheck(filePath);
    BYTE_4 maxBits;
    BYTE_4 messageBits;
    string messageToString = messageToEncrypt;
    BYTE_4 messageToEncryptLength = messageToString.size();

    switch (extension) {

        case PPM:

            ppm.loadImage(filePath);
            messageBits = message.getFlag(ppm);
            maxBits = message.getMaxLength(ppm);

            ui.printCheck(messageBits, maxBits, messageToEncryptLength);
            break;

        case BMP:

            bmp.loadImage(filePath);
            messageBits = message.getFlag(bmp);
            maxBits = message.getMaxLength(bmp);

            ui.printCheck(messageBits, maxBits, messageToEncryptLength);
            break;

        case NOT_SUPPORTED:
            break;

    }
}

bool compare_ignore_case(char a, char b) {
    return tolower(a) == tolower(b);
}


Extension ArgumentController::fileCheck(char *filePath) {
    string ppmex = ".ppm";
    string bmpex = ".bmp";
    string extension = getFileExtensionToString(filePath);

    if (equal(extension.begin(), extension.end(), ppmex.begin(), compare_ignore_case)) {
        return PPM;
    } else if (equal(extension.begin(), extension.end(), bmpex.begin(), compare_ignore_case)) {
        return BMP;
    } else {
        return NOT_SUPPORTED;
    }
}


ArgumentController::ArgumentController(CommandLineInterface &ui) : ui(ui) {

}


string ArgumentController::getFileExtensionToString(const char *filePath) {
    string path = filePath;
    size_t pos = path.find_last_of('.');
    return path.substr(pos);
}

bool ArgumentController::isFileExisting(char *filePath) {

    ifstream file(filePath);
    return file.good();

}

