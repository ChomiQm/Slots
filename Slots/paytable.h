//paytable.h
#pragma once

#include <unordered_map>
#include "Symbols.h"
#include <vector>

class Paytable {
public:
    struct Payline {
        Symbol symbol;
        unsigned int length;
        unsigned int payout;
    };

    struct Payout {
        unsigned int payout;
        bool is_scatter;
    };

    Paytable();

    Payout get_payout(std::vector<Symbol> symbol, unsigned int count) const;

    unsigned int get_scatter_payout(unsigned int count) const;

private:
    std::unordered_map<Symbol, std::vector<Payline>> paylines;
    std::unordered_map<unsigned int, unsigned int> scatter_payouts;
};
