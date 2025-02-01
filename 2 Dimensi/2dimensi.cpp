#include <iostream>
#include <vector>
#include <cmath>
#include <matplotlibcpp.h>

using namespace std;
using namespace matplotlibcpp;

// Fungsi untuk 2x + 1
double fungsi_linear(double x) {
    return 2 * x + 1;
}

// Fungsi untuk x^2
double fungsi_kuadrat(double x) {
    return x * x;
}

// Fungsi untuk sin(x)
double fungsi_sinus(double x) {
    return sin(x);
}

// Fungsi untuk cos(x)
double fungsi_cosinus(double x) {
    return cos(x);
}

// Fungsi untuk menampilkan grafik dan hasil perhitungan
void tampilkan_grafik(double (*fungsi)(double), string nama_fungsi) {
    vector<double> nilai_x, nilai_y;
    double x_awal = -10.0;
    double x_akhir = 10.0;
    double langkah = 0.1;

    cout << "\nHasil Perhitungan:" << endl;
    cout << "X --- Y" << endl;
    for (double x = x_awal; x <= x_akhir; x += langkah) {
        double y = fungsi(x);
        nilai_x.push_back(x);
        nilai_y.push_back(y);
        cout << x << " --- " << y << endl;
    }

    // Menampilkan grafik
    cout << "\nMembuat grafik..." << endl;
    plot(nilai_x, nilai_y);
    xlabel("Sumbu X");
    ylabel("Sumbu Y");
    title("Grafik dari " + nama_fungsi);
    grid(true);
    show();
}

int main() {
    int pilihan;
    cout << "============================================" << endl;
    cout << "==========  KALKULATOR GRAFIK 2D  ==========" << endl;
    cout << "============================================" << endl;
    cout << "Pilih fungsi yang ingin diplot:" << endl;
    cout << "1. 2x + 1" << endl;
    cout << "2. x^2" << endl;
    cout << "3. sin(x)" << endl;
    cout << "4. cos(x)" << endl;
    cout << ">> ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            tampilkan_grafik(fungsi_linear, "2x + 1");
            break;
        case 2:
            tampilkan_grafik(fungsi_kuadrat, "x^2");
            break;
        case 3:
            tampilkan_grafik(fungsi_sinus, "sin(x)");
            break;
        case 4:
            tampilkan_grafik(fungsi_cosinus, "cos(x)");
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }

    cout << "\nTerima kasih telah menggunakan kalkulator grafik 2D!" << endl;
    return 0;
}