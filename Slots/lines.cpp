// lines.cpp
#include "lines.h"
#include "Symbols.h"
#include "reels.h"
#include <vector>

Line::Line(const std::vector<int>& positions, int betMultiplier, int payoutMultiplier) :
	positions(positions), betMultiplier(betMultiplier), payoutMultiplier(payoutMultiplier) {}

std::vector<Symbol> Line::getSymbols(const Reels& reels) const {
	std::vector<Symbol> symbols;
	for (int i = 0; i < reels.getNumReels(); i++) {
		symbols.push_back(reels.getSymbol(i, positions[i]));
	}
	return symbols;
}

Lines::Lines(int numLines) : numLines(numLines) {
	lines.reserve(numLines);
	for (int i = 0; i < numLines; i++) {
		// Tworzenie nowej linii o domyœlnych parametrach i dodawanie jej do wektora
		lines.push_back(Line(std::vector<int>(), 0, 0));
	}
	// Dodawanie linii wygrywaj¹cych do poprawy na enum
	lines[0] = Line({ 0, 0, 0 }, 2, 10);
	lines[1] = Line({ 1, 1, 1 }, 2, 20);
	lines[2] = Line({ 2, 2, 2 }, 2, 30);
	lines[3] = Line({ 3, 3, 3 }, 2, 40);
	lines[4] = Line({ 4, 4, 4 }, 2, 50);
	lines[5] = Line({ 5, 5, 5 }, 2, 60);
	lines[6] = Line({ 6, 6, 6 }, 2, 70);
	lines[7] = Line({ 0, 1, 6 }, 3, 75);
	lines[8] = Line({ 0, 0, 1, 1 }, 4, 100);
	lines[9] = Line({ 2, 2, 4, 4 }, 4, 125);
	lines[10] = Line({ 5, 5, 3, 3 }, 4, 150);
	lines[11] = Line({ 1, 1, 6 }, 5, 200);
	lines[12] = Line({ 4, 4, 6 }, 5, 250);
	lines[13] = Line({ 0, 1, 0, 1 }, 5, 500);
	lines[14] = Line({ 5, 5, 5 }, 2, 30);
	lines[15] = Line({ 3, 3, 6 }, 5, 750);
	lines[16] = Line({ 2, 4, 2, 4 }, 6, 1000);
	lines[17] = Line({ 0, 1, 1, 0, 1 }, 10, 2500);
	lines[18] = Line({ 6, 6, 6 }, 20, 5000);
	lines[19] = Line({ 7, 7, 7 }, 0, 0);

}