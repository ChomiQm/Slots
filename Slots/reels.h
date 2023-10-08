// reels.h
#ifndef REELS_H
#define REELS_H

#include <vector>
#include <random>
#include <array>
#include "Symbols.h"

class Reels {
private:
    std::array<std::array<Symbol, 5>, 3> reels; // reprezentacja walców
    std::mt19937 rng; // generator liczb losowych
public:
    Reels(); // konstruktor
    int getNumReels() const { return 3; }
    void spin(); // metoda do losowania symboli na walcach
    const std::array<std::array<Symbol, 5>, 3>& getReels() const; // metoda zwracaj¹ca reprezentacjê walców
    Symbol getSymbol(int reelIndex, int symbolIndex) const;
    Symbol operator()(int reelIndex, int symbolIndex) const;
};

#endif // REELS_H
