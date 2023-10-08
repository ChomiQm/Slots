//symbols.cpp
#include "Symbols.h"

Symbols::Symbols() {
    symbol_names = {
        { Symbol::SCATTER, "SCATTER" },
        { Symbol::BELL, "BELL" },
        { Symbol::CHERRY, "CHERRY" },
        { Symbol::LEMON, "LEMON" },
        { Symbol::ORANGE, "ORANGE" },
        { Symbol::PLUM, "PLUM" },
        { Symbol::SEVEN, "SEVEN" },
        { Symbol::WATERMELON, "WATERMELON" }
    };
}

std::string Symbols::to_string(Symbol symbol) const {
    return symbol_names.at(symbol);
}

Symbol Symbols::from_string(const std::string& str) const {
    static std::unordered_map<std::string, Symbol> symbol_map = {
        { "SCATTER", Symbol::SCATTER },
        { "BELL", Symbol::BELL },
        { "CHERRY", Symbol::CHERRY },
        { "LEMON", Symbol::LEMON },
        { "ORANGE", Symbol::ORANGE },
        { "PLUM", Symbol::PLUM },
        { "SEVEN", Symbol::SEVEN },
        { "WATERMELON", Symbol::WATERMELON }
    };
    return symbol_map.at(str);
}
