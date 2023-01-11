//
// Created by Nevader on 26.12.2022.
//

#ifndef STEGANOGRAPHY_BASECONTROLLER_H
#define STEGANOGRAPHY_BASECONTROLLER_H


#include "ArgumentController.h"
#include "FlagController.h"
#include "../View/CommandLineInterface.h"

class BaseController {

private:
    int argumentCount;
    char **argumentArray;
    string fileName;

    ArgumentController arguments;
    FlagController flags;

public:
    BaseController(int argc, char *argv[], FlagController &flags, ArgumentController &arguments);
/**
@brief Runs the program based on passed command line arguments.
This method checks for any flag errors using the isThereFlagError method of the FlagController class.
If there are no errors, it iterates through the command line arguments and calls the appropriate method in
the ArgumentController class based on the flag.
*/
    void run();
};


#endif //STEGANOGRAPHY_BASECONTROLLER_H
