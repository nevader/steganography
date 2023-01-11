//
// Created by Nevader on 26.12.2022.
//

#include "BaseController.h"

BaseController::BaseController(int argc, char *argv[], FlagController &flags, ArgumentController &arguments)
        : flags(flags), arguments(arguments) {
    argumentCount = argc;
    argumentArray = argv;

    string exePath = argv[0];
    size_t pos = exePath.find_last_of('\\');
    string exeName = exePath.substr(pos + 1);

    fileName = exeName;
}

void BaseController::run() {

    if (!flags.isThereFlagError()) {

        for (int i = 1; i < argumentCount; ++i) {

            switch (flags.stringToFlag(argumentArray[i])) {

                case HELP:
                    arguments.help(fileName);
                    break;

                case INFO:
                    arguments.info(argumentArray[i + 1]);
                    i += 1;
                    break;

                case ENCRYPT:
                    arguments.encrypt(argumentArray[i + 1], argumentArray[i + 2]);
                    i += 2;
                    break;

                case DECRYPT:
                    arguments.decrypt(argumentArray[i + 1]);
                    i++;
                    break;

                case CHECK:
                    arguments.check(argumentArray[i + 1], argumentArray[i + 2]);
                    i += 2;
                    break;

                case UNKNOWN:
                    break;
            }
        }
    }
}
