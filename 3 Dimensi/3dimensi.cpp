#include "matplotlibcpp.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
using namespace matplotlibcpp;

double compute_z(double x, double y) {
    return sin(x) * cos(y);
}

int main() {
    PyObject* ax = chart(111);
    Clear3DChart(ax);
    int n = 60;
    double t0 = -4.0, t1 = 4.0;
    double dT = (t1 - t0) / (n - 1);
    vector<vector<double>> X, Y, Z;
    vector<double> tx, ty, tz;
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
    surface3D(ax, X, Y, Z, "blue", 0.9);
    xlabel("Sumbu X");
    ylabel("Sumbu Y");
    show();
    return 0;
}