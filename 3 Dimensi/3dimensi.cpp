#include <iostream>
#include <cmath>
#include <vector>
#include "matplotlibcpp.h" // Include matplotlibcpp

namespace plt = matplotlibcpp;

// Function definition for z = f(x, y)
double calculateZ(double x, double y) {
    return x * x + y * y; // Example function z = x^2 + y^2
}

int main() {
    // Define the range for z (1 to 10)
    const int z_min = 1;
    const int z_max = 10;
    const double step = 0.5; // Step size for x and y

    std::vector<double> x_vals;
    std::vector<double> y_vals;
    std::vector<double> z_vals;

    std::cout << "z \t x \t y" << std::endl;

    // Loop over z values
    for (int z = z_min; z <= z_max; ++z) {
        for (double x = -10; x <= 10; x += step) {
            for (double y = -10; y <= 10; y += step) {
                double calculated_z = calculateZ(x, y);
                if (std::abs(calculated_z - z) < 0.5) { // Check if z is close to the calculated value
                    std::cout << z << "\t" << x << "\t" << y << std::endl;
                    x_vals.push_back(x);
                    y_vals.push_back(y);
                    z_vals.push_back(z);
                }
            }
        }
    }

    // Setting up the 3D plot
    plt::figure(); // Create a new figure
    plt::named_plot3("3D Curve", x_vals, y_vals, z_vals, {{"marker", "o"}}); // Plot points with markers
    plt::xlabel("X-axis");
    plt::ylabel("Y-axis");
    plt::title("3D Graph of z = x^2 + y^2");
    plt::legend(); // Show legend
    plt::show();   // Display the plot

    return 0;
}
