//
// Created by Nevader on 14.12.2022.
//

#include <algorithm>
#include "Ppm.h"
#include "Pixels.h"


void Ppm::writeImage(const char *fileName) {

    ofstream file;
    file.open(fileName, ios::out);

    file << magicNumber << "\n";
    file << width << " ";
    file << height << "\n";
    file << maxColor;

    for (int y = 0; y < height; ++y) {
        file << "\n";
        for (int x = 0; x < width; ++x) {
            file << (int) pixels.getColor(RED, x, y) << " ";
            file << (int) pixels.getColor(BLUE, x, y) << " ";
            file << (int) pixels.getColor(GREEN, x, y) << " ";
        }
    }
    file.close();
}

bool Ppm::loadImage(const char *fileName) {

    ifstream file(fileName);
    vector<string> words;
    string line;
    string word;

    while (words.size() < 4) {
        getline(file, line);
        istringstream iss(line);
        while (iss >> word && words.size() < 4) {
            if (!word.find('#')) {
                break;
            } else {
                words.push_back(word);
            }
        }
    }


    magicNumber = words[0];
    width = stoi(words[1]);
    height = stoi(words[2]);
    maxColor = stoi(words[3]);

    if (!isAsciiEncoded()) {
        return false;
    }

    pixels.setWidth(width);
    pixels.setPixelArraySize(width, height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            BYTE colors[3];
            int counter = 0;
            string color;

            while (counter < 3) {
                file >> color;
                colors[counter] = stoi(color);
                counter++;
            }
            pixels.setColor(RED, colors[0], x, y);
            pixels.setColor(BLUE, colors[1], x, y);
            pixels.setColor(GREEN, colors[2], x, y);
        }
    }
    file.close();
    return true;
}

bool Ppm::isAsciiEncoded() {
    if (magicNumber == "P3" || magicNumber == "p3") {
        return true;
    } else {
        return false;
    }
}
