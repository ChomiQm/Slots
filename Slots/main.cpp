#include <iostream>
#include <string>
#include <vector>
#include "game.h"
#include "input.h"
#include "output.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Pobierz argumenty z linii poleceñ
    Input input(argc, argv);

    // Utwórz obiekt reprezentuj¹cy grê
    Game game;

    // Inicjuj stan gry na podstawie wartoœci wprowadzonych z wiersza poleceñ
    game.init(input.getGamesCount(), input.getStartCredit(), input.getCreditOutFile());

    // PrzeprowadŸ pojedyncz¹ rundê gry
    game.play();

    // Zapisz logi zmian stanu kredytu do pliku
    saveCreditsToFile(std::vector<int>{game.getCredits()}, input.getCreditOutFile());

    // Wyœwietl raport podsumowuj¹cy symulacjê gry
    printSummaryReport(input.getGamesCount(), input.getStartCredit(), game.getCredits());

    return 0;
}
