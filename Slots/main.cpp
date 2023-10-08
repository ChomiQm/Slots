#include <iostream>
#include <string>
#include <vector>
#include "game.h"
#include "input.h"
#include "output.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Pobierz argumenty z linii polece�
    Input input(argc, argv);

    // Utw�rz obiekt reprezentuj�cy gr�
    Game game;

    // Inicjuj stan gry na podstawie warto�ci wprowadzonych z wiersza polece�
    game.init(input.getGamesCount(), input.getStartCredit(), input.getCreditOutFile());

    // Przeprowad� pojedyncz� rund� gry
    game.play();

    // Zapisz logi zmian stanu kredytu do pliku
    saveCreditsToFile(std::vector<int>{game.getCredits()}, input.getCreditOutFile());

    // Wy�wietl raport podsumowuj�cy symulacj� gry
    printSummaryReport(input.getGamesCount(), input.getStartCredit(), game.getCredits());

    return 0;
}
