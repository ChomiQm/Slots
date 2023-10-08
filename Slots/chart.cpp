//chart.cpp
#include "chart.h"
#include <iostream>
Chart::Chart() {}

void Chart::addCredit(double credit) {
    credits.push_back(credit);
}

void Chart::generateChart() const {
    std::cout << "Generating chart..." << std::endl;
    // wygenerowaæ wykres
}