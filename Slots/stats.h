//stats.h
#ifndef STATS_H
#define STATS_H

#include <vector>
#include <string>
using namespace std;
// Struktura reprezentuj�ca poszczeg�lny typ wygranej
struct Stats {
    std::string name;           // Nazwa typu wygranej
    int multiplier;             // Mno�nik wygranej
    int hits;                   // Liczba trafie�
    double hitPercentage;       // Procentowy udzia� trafie� w ��cznej sumie wszystkich trafie�
    int totalWin;               // Ca�kowita warto�� wygranych
    double totalWinPercentage;  // Procentowy udzia� warto�ci wygranych w ��cznej sumie wszystkich wygranych
    double hitsPerWin;          // �rednia cz�stotliwo�� wyst�powania danego uk�adu w ca�kowitej liczbie wygranych gier
    double hitsPerGame;         // �rednia cz�stotliwo�� wyst�powania danego uk�adu w ca�kowitej liczbie wszystkich gier
};

// Funkcja generuj�ca statystyki dla podanych danych wej�ciowych
vector<Stats> generateStatistics(const vector<vector<int>>& winTable, int totalWins);

#endif // STATS_H
