//chart.h
#ifndef CHART_H
#define CHART_H

#include <vector>

class Chart {
public:
    Chart();
    void addCredit(double credit);
    void generateChart() const;

private:
    std::vector<double> credits;
};

#endif // CHART_H
