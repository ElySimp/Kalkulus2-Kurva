#include "matplotlibcpp.h"
#include <vector>
#include <iostream>
#include <cmath>

namespace plt = matplotlibcpp;

// Fungsi untuk menghitung nilai z berdasarkan x dan y: z = sin(x) * cos(y)
double compute_z(double x, double y) {
    return std::sin(x) * std::cos(y);
}

int main() {
    // Membuat chart 3D
    PyObject* ax = plt::chart(111);
    plt::Clear3DChart(ax);

    // Menyiapkan grid data untuk plot 3D
    int n = 60;                   // jumlah titik per sumbu
    double t0 = -4.0, t1 = 4.0;     // rentang nilai x dan y
    double dT = (t1 - t0) / (n - 1);

    // Vektor 2D untuk menyimpan koordinat grid dan nilai z
    std::vector<std::vector<double>> X, Y, Z;
    std::vector<double> tx, ty, tz;

    // Membuat grid dan menghitung z = sin(x) * cos(y) untuk setiap titik (x, y)
    for (int i = 0; i < n; ++i) {
        tx.clear();
        ty.clear();
        tz.clear();
        double rx = t0 + i * dT;
        for (int j = 0; j < n; ++j) {
            double ry = t0 + j * dT;
            tx.push_back(rx);
            ty.push_back(ry);
            tz.push_back(compute_z(rx, ry));
        }
        X.push_back(tx);
        Y.push_back(ty);
        Z.push_back(tz);
    }

    // Mem-plot permukaan 3D dengan warna biru dan tingkat transparansi 0.9
    plt::surface3D(ax, X, Y, Z, "blue", 0.9);
    plt::xlabel("Sumbu X");
    plt::ylabel("Sumbu Y");

    // Menampilkan plot
    plt::show();

    return 0;
}