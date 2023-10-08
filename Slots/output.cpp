#include "output.h"

#include <iostream>
#include <fstream>

// Funkcja zapisuj�ca logi zmian stanu kredytu do pliku
void saveCreditsToFile(const std::vector<int>& credits, const std::string& filename) {
    std::ofstream outfile(filename);
    if (outfile) {
        for (int credit : credits) {
            outfile << credit << std::endl;
        }
        std::cout << "Credits saved to file: " << filename << std::endl;
    }
    else {
        std::cerr << "Error saving credits to file: " << filename << std::endl;
    }
}

// Funkcja wy�wietlaj�ca raport podsumowuj�cy symulacj� gry
void printSummaryReport(int gamesCount, int startCredit, int endCredit) {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "          GAME SIMULATION REPORT        " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Games played: " << gamesCount << std::endl;
    std::cout << "Starting credit: " << startCredit << std::endl;
    std::cout << "Ending credit: " << endCredit << std::endl;
    std::cout << "Net profit: " << endCredit - startCredit << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}
