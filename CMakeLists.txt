cmake_minimum_required(VERSION 3.23)
project(steganography)

set(CMAKE_CXX_STANDARD 14)

add_executable(steganography main.cpp Model/Bmp.cpp Model/Bmp.h Model/Ppm.cpp Model/Ppm.h Model/Pixels.cpp Model/Pixels.h Model/Message.cpp Model/Message.h Controller/FlagController.cpp Controller/FlagController.h Model/Image.cpp Model/Image.h Controller/ArgumentController.cpp Controller/ArgumentController.h View/CommandLineInterface.cpp View/CommandLineInterface.h Enums/Flag.h Enums/Error.h Controller/BaseController.cpp Controller/BaseController.h)
