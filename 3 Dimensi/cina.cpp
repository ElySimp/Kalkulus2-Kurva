#include <iostream>
#include <cmath>
#include "matplotlibcpp.h"  // include the matplotlibcpp header file

namespace plt = matplotlibcpp;

int main() {
    // Generate some data
    const int n = 100;
    std::vector<double> x(n), y(n);

    for (int i = 0; i < n; ++i) {
        x[i] = i * 0.1;  // x values
        y[i] = std::sin(x[i]);  // y values (sine function)
    }

    // Plot the data
    plt::plot(x, y);
    plt::title("Sine Wave");
    plt::xlabel("x");
    plt::ylabel("sin(x)");

    // Show the plot
    plt::show();

    return 0;
}