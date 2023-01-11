

#include "FlagController.h"


Flag FlagController::stringToFlag(const string &str) {

    if (str == "-h" || str == "--help") {
        return HELP;

    } else if (str == "-i" || str == "--info") {
        return INFO;

    } else if (str == "-e" || str == "--encrypt") {
        return ENCRYPT;

    } else if (str == "-d" || str == "--decrypt") {
        return DECRYPT;

    } else if (str == "-c" || str == "--check") {
        return CHECK;

    } else {
        return UNKNOWN;
    }
}

bool FlagController::isThereFlagError() {

    int argsCount;

    if (argumentCount == 1) {
        string exePath = argumentArray[0];
        size_t pos = exePath.find_last_of('\\');
        string exeName = exePath.substr(pos + 1);
        ui.printHelp(exeName);
        return true;
    }

    for (int i = 1; i < argumentCount; i++) {

        string currentFlag = argumentArray[i];

        if (currentFlag.front() == '-' || (i == 1 && currentFlag.front() != '-')) {

            argsCount = argumentCounter(i);

            switch (stringToFlag(currentFlag)) {
                case HELP:
                    if (argsCount != 0) {
                        ui.printFlagError(TOO_MANY_ARGUMENTS, HELP, argumentArray[i + argsCount]);
                        return true;
                    }
                    break;

                case INFO:
                    if (argsCount > 1) {
                        ui.printFlagError(TOO_MANY_ARGUMENTS, INFO, argumentArray[i + argsCount]);
                        return true;

                    } else if (argsCount < 1) {
                        ui.printFlagError(TOO_FEW_ARGUMENTS, INFO, argumentArray[i]);
                        return true;
                    }
                    break;

                case ENCRYPT:
                    if (argsCount > 2) {
                        ui.printFlagError(TOO_MANY_ARGUMENTS, ENCRYPT, argumentArray[i + argsCount]);
                        return true;

                    } else if (argsCount < 2) {
                        ui.printFlagError(TOO_FEW_ARGUMENTS, ENCRYPT, "");
                        return true;
                    }
                    break;

                case DECRYPT:
                    if (argsCount > 1) {
                        ui.printFlagError(TOO_MANY_ARGUMENTS, DECRYPT, argumentArray[i + argsCount]);
                        return true;

                    } else if (argsCount < 1) {
                        ui.printFlagError(TOO_FEW_ARGUMENTS, DECRYPT, argumentArray[i]);
                        return true;
                    }
                    break;

                case CHECK:
                    if (argsCount > 2) {
                        ui.printFlagError(TOO_MANY_ARGUMENTS, CHECK, argumentArray[i + argsCount]);
                        return true;

                    } else if (argsCount < 2) {
                        ui.printFlagError(TOO_FEW_ARGUMENTS, CHECK, "");
                        return true;
                    }
                    break;

                case UNKNOWN:
                    ui.printFlagError(INVALID_FLAG, UNKNOWN, currentFlag);
                    return true;
            }
        }
    }

    return false;
}

int FlagController::argumentCounter(int currIndex) {

    bool nextFlag = false;
    int counter = 0;
    while (!nextFlag && currIndex < argumentCount - 1) {
        string next = argumentArray[currIndex + 1];
        if (next.front() != '-') {
            counter++;
            currIndex++;
        } else {
            nextFlag = true;
        }
    }

    return counter;
}

FlagController::FlagController(CommandLineInterface &ui, int &argc, char **argv)
        : ui(ui), argumentCount(argc) {
    this->argumentArray = argv;

}



