// lines.h
#ifndef LINES_H
#define LINES_H

#include <vector>
#include "Symbols.h"
#include "reels.h"

class Line {
public:
	Line(const std::vector<int>& positions, int betMultiplier, int payoutMultiplier);
	std::vector<int> getPositions() const { return positions; }

	std::vector<Symbol> getSymbols(const Reels& reels) const;

	int getBetMultiplier() const { return betMultiplier; }

	int getPayoutMultiplier() const { return payoutMultiplier; }
private:
	std::vector<int> positions;
	int betMultiplier;
	int payoutMultiplier;
};

class Lines {
public:
	Lines(int numLines);
	void setLine(int index, const Line& line);

	std::vector<Line> getLines() const { return lines; }

	int getNumLines() const { return numLines; }

	std::vector<std::vector<Symbol>> getSymbols(const Reels& reels) const;
private:
	std::vector<Line> lines;
	int numLines;
};

#endif