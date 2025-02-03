#include <cmath>
#include <vector>
#include <iostream>
#include <Python.h>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

std::vector<double> linspace(double start, double end, size_t num) {
    std::vector<double> result(num);
    double step = (end - start) / (num - 1);
    for (size_t i = 0; i < num; ++i) {
        result[i] = start + i * step;
    }
    return result;
}

void plot_sin_cos() {
    // Generate data
    auto x = linspace(-5, 5, 50);
    auto y = linspace(-5, 5, 50);
    std::vector<std::vector<double>> X(x.size(), std::vector<double>(y.size()));
    std::vector<std::vector<double>> Y(x.size(), std::vector<double>(y.size()));
    std::vector<std::vector<double>> Z(x.size(), std::vector<double>(y.size()));

    for (size_t i = 0; i < x.size(); ++i) {
        for (size_t j = 0; j < y.size(); ++j) {
            X[i][j] = x[i];
            Y[i][j] = y[j];
            Z[i][j] = sin(x[i]) * cos(y[j]);
        }
    }

    try {
        plt::plot_surface(X, Y, Z);
        plt::title("sin(x) * cos(y)");
        plt::show();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void plot_paraboloid() {
    auto x = linspace(-5, 5, 50);
    auto y = linspace(-5, 5, 50);
    std::vector<std::vector<double>> X(x.size(), std::vector<double>(y.size()));
    std::vector<std::vector<double>> Y(x.size(), std::vector<double>(y.size()));
    std::vector<std::vector<double>> Z(x.size(), std::vector<double>(y.size()));

    for (size_t i = 0; i < x.size(); ++i) {
        for (size_t j = 0; j < y.size(); ++j) {
            X[i][j] = x[i];
            Y[i][j] = y[j];
            Z[i][j] = pow(x[i], 2) + pow(y[j], 2);
        }
    }

    try {
        plt::plot_surface(X, Y, Z);
        plt::title("x^2 + y^2");
        plt::show();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    // Inisialisasi Python interpreter
    Py_Initialize();

    int choice;
    while(true) {
        std::cout << "Menu Grafik 3D:\n";
        std::cout << "1. sin(x) * cos(y)\n";
        std::cout << "2. x^2 + y^2\n";
        std::cout << "Pilih menu (1/2): ";
        std::cin >> choice;
        
        if(choice == 1) {
            plot_sin_cos();
            break;
        } else if(choice == 2) {
            plot_paraboloid();
            break;
        } else {
            std::cout << "Pilihan tidak valid!\n\n";
        }
    }
    
    return 0;
}