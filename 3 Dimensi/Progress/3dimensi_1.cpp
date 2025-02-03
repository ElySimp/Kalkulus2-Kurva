#include "matplotlibcpp.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <stdexcept>

namespace plt = matplotlibcpp;

// Fungsi untuk memparsing ekspresi matematika sederhana
double evaluate_function(const std::string& func, double x, double y = 0.0) {
    // Gunakan `x` dan `y` dalam ekspresi
    try {
        if (func.find("sin") != std::string::npos) {
            return std::sin(x);
        } else if (func.find("cos") != std::string::npos) {
            return std::cos(x);
        } else if (func.find("x^2") != std::string::npos) {
            return std::pow(x, 2);
        } else if (func.find("y^3") != std::string::npos) {
            return std::pow(y, 3);
        } else if (func.find("y^2") != std::string::npos) {
            return std::pow(y, 2);
        } else {
            throw std::invalid_argument("Fungsi tidak dikenali");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error saat evaluasi fungsi: " << e.what() << std::endl;
        return 0.0;
    }
}

int main() {
    std::string input_function;
    std::cout << "Masukkan fungsi (contoh: sin(x), x^2, y^3 + y^2): ";
    std::getline(std::cin, input_function);

    const int resolution = 100; // Resolusi grafik
    std::vector<double> x(resolution);
    std::vector<double> y(resolution);
    std::vector<double> z(resolution);

    // Membuat nilai X dan Y
    for (int i = 0; i < resolution; ++i) {
        x[i] = -5.0 + 10.0 * i / (resolution - 1); // Rentang [-5, 5]
        y[i] = -5.0 + 10.0 * i / (resolution - 1);
    }

    // Evaluasi fungsi
    for (int i = 0; i < resolution; ++i) {
        z[i] = evaluate_function(input_function, x[i], y[i]);
    }

    // Plot grafik
    try {
        plt::plot(x, z);
        plt::xlabel("x");
        plt::ylabel("f(x)");
        plt::title("Graph of " + input_function);
        plt::grid(true);
        plt::show();
    } catch (const std::exception& e) {
        std::cerr << "Error saat plotting: " << e.what() << std::endl;
    }

    return 0;
}