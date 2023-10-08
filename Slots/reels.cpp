//reels.cpp
#include "reels.h"
#include "Symbols.h"

Reels::Reels() {
    // Inicjalizacja walców
    std::array<std::array<Symbol, 5>, 3> temp = { {
        {Symbol::SCATTER, Symbol::WATERMELON, Symbol::PLUM, Symbol::ORANGE, Symbol::WATERMELON},
        {Symbol::CHERRY, Symbol::LEMON, Symbol::WATERMELON, Symbol::PLUM, Symbol::ORANGE},
        {Symbol::BELL, Symbol::CHERRY, Symbol::CHERRY, Symbol::SEVEN, Symbol::BELL}
    } };
    reels.fill({}); // wype³nij defaultowo uzywajac arraya
    for (int i = 0; i < 3; ++i) {
        std::copy(temp[i].begin(), temp[i].end(), reels[i].begin());
    }

    // Inicjalizacja generatora liczb losowych
    std::random_device rd;
    rng.seed(rd());
}

void Reels::spin() {
    // Losowanie symboli na ka¿dym walcu
    for (auto& reel : reels) {
        std::uniform_int_distribution<int> dist(0, 7);
        reel[0] = static_cast<Symbol>(dist(rng));
        for (int i = 1; i < 5; ++i) {
            std::uniform_int_distribution<int> dist2(0, 7);
            Symbol symbol = static_cast<Symbol>(dist2(rng));
            // Sprawdzenie, czy nie ma dwóch takich samych symboli obok siebie
            while (symbol == reel[i - 1]) {
                symbol = static_cast<Symbol>(dist2(rng));
            }
            reel[i] = symbol;
        }
    }
}

const std::array<std::array<Symbol, 5>, 3>& Reels::getReels() const {
    return reels;
}

Symbol Reels::getSymbol(int reelIndex, int symbolIndex) const {
    // Sprawdzenie poprawnoœci argumentów
    if (reelIndex < 0 || reelIndex > 2 || symbolIndex < 0 || symbolIndex > 7) {
        throw std::out_of_range("Invalid reel or symbol index}");
    }
    return reels[reelIndex][symbolIndex];
}


Symbol Reels::operator()(int reelIndex, int symbolIndex) const {
    return getSymbol(reelIndex, symbolIndex);
}
