//output.h
#pragma once
#ifndef OUTPUT_H
#define OUTPUT_H

#include <string>
#include <vector>

// Funkcja zapisuj�ca logi zmian stanu kredytu do pliku
void saveCreditsToFile(const std::vector<int>& credits, const std::string& filename);

// Funkcja wy�wietlaj�ca raport podsumowuj�cy symulacj� gry
void printSummaryReport(int gamesCount, int startCredit, int endCredit);

#endif /* OUTPUT_H */

