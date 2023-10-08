//game.h
#pragma once
#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <string>
#include "Symbols.h"
#include "paytable.h"
#include "reels.h"
#include "lines.h"

class Game {
public:
	Game();
	Game(int gamesCount, int startCredit, const std::string& creditOutFile);
	void init(int gamesCount, int startCredit, const std::string& creditOutFile);
	void playRound();
	void play();
	int getCredits() const;
	int getResult() const;
	int getBet() const;
	float getRTP() const;
private:
	int credits_{ 0 };
	int result_{ 0 };
	int bet_{ 100 };
	float rtp_{ 0.0 };
	Paytable paytable_;
	Reels reels_;
	Lines lines_;
	int gamesCount_{ 0 };
	int startCredit_{ 0 };
	std::ofstream creditOutFile_;
};

#endif