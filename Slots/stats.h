//stats.h
#ifndef STATS_H
#define STATS_H

#include <vector>
#include <string>
using namespace std;
// Struktura reprezentuj¹ca poszczególny typ wygranej
struct Stats {
    std::string name;           // Nazwa typu wygranej
    int multiplier;             // Mno¿nik wygranej
    int hits;                   // Liczba trafieñ
    double hitPercentage;       // Procentowy udzia³ trafieñ w ³¹cznej sumie wszystkich trafieñ
    int totalWin;               // Ca³kowita wartoœæ wygranych
    double totalWinPercentage;  // Procentowy udzia³ wartoœci wygranych w ³¹cznej sumie wszystkich wygranych
    double hitsPerWin;          // Œrednia czêstotliwoœæ wystêpowania danego uk³adu w ca³kowitej liczbie wygranych gier
    double hitsPerGame;         // Œrednia czêstotliwoœæ wystêpowania danego uk³adu w ca³kowitej liczbie wszystkich gier
};

// Funkcja generuj¹ca statystyki dla podanych danych wejœciowych
vector<Stats> generateStatistics(const vector<vector<int>>& winTable, int totalWins);

#endif // STATS_H
