//stats.cpp
#include "stats.h"
#include "Symbols.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;


vector<Stats> generateStatistics(const vector<vector<int>>& winTable, int totalWins) {
    vector<Stats> stats;
    double totalWinValue = 0.0;
    Symbols symbols; // Utworzenie obiektu klasy Symbols

    for (int i = 0; i < winTable.size(); i++) {
        int hits = winTable[i][0];
        int multiplier = winTable[i][1];
        Symbol symbol = static_cast<Symbol>(i); // Konwersja wartoœci int na Symbol
        string name = symbols.to_string(symbol) + " " + to_string(hits) + "x" + to_string(multiplier);
        int totalWin = hits * multiplier;
        double hitPercentage = (double)hits / (double)totalWins * 100.0;
        double totalWinPercentage = (double)totalWin / totalWinValue * 100.0;
        double hitsPerWin = (double)totalWins / (double)hits;
        double hitsPerGame = (double)totalWins / (double)winTable.size();

        stats.push_back(Stats{ name, multiplier, hits, hitPercentage, totalWin, totalWinPercentage, hitsPerWin, hitsPerGame });


        totalWinValue += totalWin;
    }

    return stats;
}

// Funkcja wypisuj¹ca statystyki na standardowe wyjœcie
void printStatistics(const vector<Stats>& stats) {
    cout << left << setw(15) << "Symbol" << setw(25) << "Nazwa" << setw(15) << "Mn¿." << setw(15) << "Licz. Traf." << setw(15) << "Licz. Traf. %" << setw(15) << "Ca³. War." << setw(15) << "Ca³. War. %" << setw(15) << "1/(w)" << setw(15) << "1/(g)" << endl;
    cout << setfill('-') << setw(120) << "" << setfill(' ') << endl;

    for (const Stats& winType : stats) {
        cout << left << setw(15) << winType.name << setw(25)  << setw(15) << winType.multiplier << setw(15) << winType.hits << setw(15) << fixed << setprecision(2) << winType.hitPercentage << setw(15) << winType.totalWin << setw(15) << winType.totalWinPercentage << setw(15) << fixed << setprecision(2) << winType.hitsPerWin << setw(15) << fixed << setprecision(2) << winType.hitsPerGame << endl;
    }
}
