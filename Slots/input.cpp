#include "input.h"
#include <iostream>
#include <string>

Input::Input(int argc, char** argv) {
    int i = 1;
    while (i < argc) {
        std::string arg = argv[i];
        if (arg == "-gamesCount") {
            if (i + 1 < argc) {
                gamesCount = std::stoi(argv[i + 1]);
                i += 2;
            }
            else {
                std::cerr << "Missing value for -gamesCount" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else if (arg == "-startCredit") {
            if (i + 1 < argc) {
                startCredit = std::stoi(argv[i + 1]);
                i += 2;
            }
            else {
                std::cerr << "Missing value for -startCredit" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else if (arg == "-creditOutFile") {
            if (i + 1 < argc) {
                creditOutFile = argv[i + 1];
                i += 2;
            }
            else {
                std::cerr << "Missing value for -creditOutFile" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else {
            std::cerr << "Unknown option: " << arg << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}

int Input::getGamesCount() const {
    return gamesCount;
}

int Input::getStartCredit() const {
    return startCredit;
}

std::string Input::getCreditOutFile() const {
    return creditOutFile;
}