//
// Created by Nevader on 18.12.2022.
//

#ifndef STEGANOGRAPHY_FLAGCONTROLLER_H
#define STEGANOGRAPHY_FLAGCONTROLLER_H

#include <iostream>
#include "ArgumentController.h"
#include "../ENUMS/Flag.h"
#include "../Enums/Error.h"
#include "../View/CommandLineInterface.h"
#include <map>

using namespace std;


class FlagController {

private:
    const CommandLineInterface ui;
    const int argumentCount;
    char **argumentArray;

public:
    FlagController(CommandLineInterface &ui, int &argumentCount, char **argumentArray);

    Flag stringToFlag(const string &str);

/**
@brief Check for flag errors in the command line arguments.
This function iterates through all of the command line arguments, starting at index 1. It checks
for the presence of flags, and whether they have the correct number of arguments. If any errors
are found, it will print an error message and return true. Otherwise, it will return false.

@return True if flag errors were found, false otherwise.
*/
    bool isThereFlagError();

/**

@brief Counts the number of arguments following a flag.

@param currIndex The index of the current flag in the command line arguments.

@return The number of arguments following the current flag.
*/
    int argumentCounter(int currIndex);

};


#endif //STEGANOGRAPHY_FLAGCONTROLLER_H
