//input.h
#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <string>

class Input {
public:
    Input(int argc, char** argv);
    int getGamesCount() const;
    int getStartCredit() const;
    std::string getCreditOutFile() const;

private:
    int gamesCount;
    int startCredit;
    std::string creditOutFile;
};

#endif /* INPUT_H */
