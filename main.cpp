#include "controller/FlagController.h"
#include "Controller/BaseController.h"


int main(int argc, char *argv[]) {

    CommandLineInterface ui{};

    FlagController flags(ui, argc, argv);
    ArgumentController arguments(ui);

    BaseController baseController(argc, argv, flags, arguments);
    baseController.run();

    return 0;

}
