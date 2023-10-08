// paytable.cpp
#include "paytable.h"
#include "Symbols.h"
#include <vector>
Paytable::Paytable() {
	//konsturktor dodac
}

Paytable::Payout Paytable::get_payout(std::vector<Symbol> symbol, unsigned int count) const {
	//pobieranie payouta z 20 lini wygrywaj¹cych

}

unsigned int Paytable::get_scatter_payout(unsigned int count) const {
	const auto it = scatter_payouts.find(count);
	if (it == scatter_payouts.end()) {
		return 0;
	}
	return it->second;
}