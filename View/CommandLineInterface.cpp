//
// Created by Nevader on 26.12.2022.
//

#include "CommandLineInterface.h"


void CommandLineInterface::generateAscii(Flag flag) const {
    switch (flag) {
        case ENCRYPT:
            cout << ".------..------..------..------..------..------..------.\n"
                    "|E.--. ||N.--. ||C.--. ||R.--. ||Y.--. ||P.--. ||T.--. |\n"
                    "| (\\/) || :(): || :/\\: || :(): || (\\/) || :/\\: || :/\\: |\n"
                    "| :\\/: || ()() || :\\/: || ()() || :\\/: || (__) || (__) |\n"
                    "| '--'E|| '--'N|| '--'C|| '--'R|| '--'Y|| '--'P|| '--'T|\n"
                    "`------'`------'`------'`------'`------'`------'`------'\n";
            break;

        case DECRYPT:
            cout << ".------..------..------..------..------..------..------.\n"
                    "|D.--. ||E.--. ||C.--. ||R.--. ||Y.--. ||P.--. ||T.--. |\n"
                    "| :/\\: || (\\/) || :/\\: || :(): || (\\/) || :/\\: || :/\\: |\n"
                    "| (__) || :\\/: || :\\/: || ()() || :\\/: || (__) || (__) |\n"
                    "| '--'D|| '--'E|| '--'C|| '--'R|| '--'Y|| '--'P|| '--'T|\n"
                    "`------'`------'`------'`------'`------'`------'`------'\n";
            break;

        case HELP:
            cout << ".------..------..------..------.\n"
                    "|H.--. ||E.--. ||L.--. ||P.--. |\n"
                    "| :/\\: || (\\/) || :/\\: || :/\\: |\n"
                    "| (__) || :\\/: || (__) || (__) |\n"
                    "| '--'H|| '--'E|| '--'L|| '--'P|\n"
                    "`------'`------'`------'`------'\n";
            break;

        case INFO:
            cout << ".------..------..------..------.\n"
                    "|I.--. ||N.--. ||F.--. ||O.--. |\n"
                    "| (\\/) || :(): || :(): || :/\\: |\n"
                    "| :\\/: || ()() || ()() || :\\/: |\n"
                    "| '--'I|| '--'N|| '--'F|| '--'O|\n"
                    "`------'`------'`------'`------'\n";
            break;

        case CHECK:
            cout << ".------..------..------..------..------.\n"
                    "|C.--. ||H.--. ||E.--. ||C.--. ||K.--. |\n"
                    "| :/\\: || :/\\: || (\\/) || :/\\: || :/\\: |\n"
                    "| :\\/: || (__) || :\\/: || :\\/: || :\\/: |\n"
                    "| '--'C|| '--'H|| '--'E|| '--'C|| '--'K|\n"
                    "`------'`------'`------'`------'`------'\n";
            break;

        case UNKNOWN:
            cout << ".------..------..------..------..------.\n"
                    "|E.--. ||R.--. ||R.--. ||O.--. ||R.--. |\n"
                    "| (\\/) || :(): || :(): || :/\\: || :(): |\n"
                    "| :\\/: || ()() || ()() || :\\/: || ()() |\n"
                    "| '--'E|| '--'R|| '--'R|| '--'O|| '--'R|\n"
                    "`------'`------'`------'`------'`------'\n";
            break;
    }
}

void CommandLineInterface::printFlagError(Error error, Flag flag, const string &reason) const {

    switch (flag) {
        case HELP:
            generateAscii(UNKNOWN);
            cout << "ERROR: " << errorEnumToString(error) << " Flag '-h' takes zero arguments.\n";
            cout << "Try using -h or --help for more information.\n";
            break;

        case INFO:
            generateAscii(UNKNOWN);
            cout << "ERROR: " << errorEnumToString(error) << " Flag '-i' takes one argument.\n";
            cout << "Try using -h or --help for more information.\n";
            break;

        case ENCRYPT:
            generateAscii(UNKNOWN);
            cout << "ERROR: " << errorEnumToString(error) << " Flag '-e' takes two arguments.\n";
            cout << "Try using -h or --help for more information.\n";
            break;

        case DECRYPT:
            generateAscii(UNKNOWN);
            cout << "ERROR: " << errorEnumToString(error) << " Flag '-d' takes one argument.\n";
            cout << "Try using -h or --help for more information.\n";
            break;

        case CHECK:
            generateAscii(UNKNOWN);
            cout << "ERROR: " << errorEnumToString(error) << " Flag '-c' takes two arguments.\n";
            cout << "Try using -h or --help for more information.\n";
            break;

        case UNKNOWN:
            generateAscii(UNKNOWN);
            cout << "ERROR: " << errorEnumToString(error) << " Cannot recognise " << reason << " flag.\n";
            cout << "Try using -h or --help for more information.\n";
            break;
    }
}

string CommandLineInterface::errorEnumToString(Error error) const {

    switch (error) {

        case INVALID_FLAG:
            return "Invalid flag.";

        case TOO_MANY_ARGUMENTS:
            return "Too many arguments.";

        case TOO_FEW_ARGUMENTS:
            return "Too few arguments.";
        case MESSAGE_TO_LONG:
            break;
    }

    return "";
}


void CommandLineInterface::printArgumentError(char *file_path, Error error, const string &reason) const {

    switch (error) {

        case FILE_PATH:
            generateAscii(UNKNOWN);
            cout << "ERROR: Cannot open file: " << file_path << "\n";
            cout << "Check if the provided file path is correct or use -h for more information.\n";
            break;
        case FILE_EXTENSION:
            generateAscii(UNKNOWN);
            cout << "ERROR: File format: " << reason << " is not supported!\n";
            cout << "* Use -h for more information.\n";
            break;

        case MESSAGE_TO_LONG:
            generateAscii(UNKNOWN);
            cout << "ERROR: The given message is too long to be encoded in: \n" << file_path << "\n\n";
            break;
        case NO_ENCODED_MESSAGE:
            generateAscii(UNKNOWN);
            cout << "ERROR: Where is no encoded message in: " << file_path << "\n";
            break;
        case FILE_FORMAT:
            generateAscii(UNKNOWN);
            cout << "ERROR: Wrong file format. " << reason;
    }
}


void CommandLineInterface::printHelp(const string &file_name) const {

    generateAscii(HELP);
    cout << "Usage:\n ";
    cout << " * " << file_name << " [options] <path-to-image-source>\n ";
    cout << " * " << file_name << " [options] <path-to-image-source> \"message-to-encrypt\"\n\n";

    cout << "Available file formats: " << endl;
    cout << " * 24bit per pixel bitmap with .bmp extension." << endl;
    cout << " * ASCII encoded Portable PixMap with .ppm extension." << endl << endl;

    cout << "Flag options:" << endl;
    cout << "(-i or --info) <path-to-image-source>" << endl;
    cout << " * Prints information about image. (timestamp, format, image size, last modified date)\n" << endl;
    cout << "(-c or --check) <path-to-image-source> \"message-to-encrypt\"" << endl;
    cout << " * Checks if message can be encrypted in the given image or if there is message to be decrypted.\n" << endl;
    cout << "(-e or --encrypt) <path-to-image-source> \"message-to-encrypt\"" << endl;
    cout << " * Encrypts given message to the image.\n" << endl;
    cout << "(-d or --decrypt) <path-to-image-source>" << endl;
    cout << " * Decrypts message from given image and prints it to the console.\n" << endl;
    cout << "(-h or --help)" << endl;
    cout << " * Prints information about this program.\n" << endl;

}

void CommandLineInterface::printEncrypt() const {
    generateAscii(ENCRYPT);
    cout << "* Successfully encrypted message in given file.\n" << endl;

}

void CommandLineInterface::printDecrypt(const string &message) const {
    generateAscii(DECRYPT);
    cout << "* Successfully decrypted message from given file." << endl;
    cout << "* Press ENTER to read message...";
    char temp = 'x';
    while (temp != '\n')
        cin.get(temp);
    cout << endl;
    cout << "* Encrypted message: \n";
    cout << message;
    cout << endl;
    cout << endl;
}


void CommandLineInterface::printInfo(int width, int height, time_t timeStamp, int size, char *file_path,
                                     Extension extension) const {
    generateAscii(INFO);
    cout << "File path: " << file_path << endl;
    switch (extension) {

        case NOT_SUPPORTED:
            cout << "File format: " << "Not supported!" << endl;
            break;
        case PPM:
            cout << "File format: " << ".ppm - ASCII encoded." << endl;
            break;
        case BMP:
            cout << "File format: " << ".bmp - 24 bit per pixel." << endl;
            break;
    }
    cout << "Image resolution: " << width << " x " << height << endl;
    cout << "Image size: " << size / 8 << " bytes" << endl;
    cout << "Last modification time: " << ctime(&timeStamp) << endl;
}

void CommandLineInterface::printCheck(BYTE_4 messageFlag, BYTE_4 maxMessageSize, BYTE_4 messageToEncryptLength) const {
    generateAscii(CHECK);
    if (messageFlag == -1) {
        cout << "* There is no hidden message to decrypt in the given file." << endl;
    } else {
        cout << "* The file at the given path contains a message that can be decrypted." << endl;
    }
    cout << "* The maximum number of characters that can be encoded: " << maxMessageSize << endl;
    cout << "* Number of characters in the given message: " << messageToEncryptLength << endl << endl;

}
