//game.cpp
#include "game.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>

Game::Game(int gamesCount, int startCredit, const std::string& creditOutFile) :
	credits_{ startCredit },
	result_{ 0 },
	bet_{ 100 },
	rtp_{ 0.0 },
	paytable_{},
	reels_{},
	lines_{ paytable_, reels_ }, // przekazanie reels_ jako drugiego argumentu
	gamesCount_{ gamesCount },
	startCredit_{ startCredit },
	creditOutFile_{ creditOutFile } {}

void Game::init(int gamesCount, int startCredit, const std::string& creditOutFile) {
	gamesCount_ = gamesCount;
	startCredit_ = credits_ = startCredit;
	creditOutFile_.open(creditOutFile.c_str());
	if (!creditOutFile_.is_open()) {
		std::cerr << "Cannot open output file: " << creditOutFile << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Game::playRound() {
	reels_.spin();
	const std::array<std::array<Symbol, 5>, 3>& reels = reels_.getReels();
	std::vector<Symbol> symbols;
	for (int i = 0; i < 3; i++) {
		int index = rand() % 5;
		symbols.push_back(reels[i][index]);
	}
	const std::vector<Line>& winningLines = lines_.getLines();
	int winAmount = 0;
	for (const Line& line : winningLines) {
		winAmount += paytable_.get_payout(symbols, line).payout;
	}
	result_ = winAmount - bet_;
	credits_ += result_;
	rtp_ = static_cast<float>(result_) / static_cast<float>(bet_);

}

void Game::play() {
	for (int i = 0; i < gamesCount_; i++) {
		playRound();
		if (i % 10 == 0) {
			creditOutFile_ << getCredits() << "\n";
		}
	}
}

int Game::getCredits() const {
	return credits_;
}

int Game::getResult() const {
	return result_;
}

int Game::getBet() const {
	return bet_;
}

float Game::getRTP() const {
	return rtp_;
}