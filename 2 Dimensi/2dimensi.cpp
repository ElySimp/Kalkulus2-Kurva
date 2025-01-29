#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <matplotlibcpp.h>

using namespace std;
using namespace matplotlibcpp;

// Fungsi untuk mengevaluasi ekspresi matematika
double evaluasi_ekspresi(const string& ekspresi, double x) {
    if (ekspresi == "x^2") {
        return x * x;
    } else if (ekspresi == "sin(x)") {
        return sin(x);
    } else if (ekspresi == "cos(x)") {
        return cos(x);
    } else if (ekspresi == "exp(x)") {
        return exp(x);
    } else if (ekspresi == "log(x)") {
        return log(x);
    } else {
        cerr << "Ekspresi tidak didukung!" << endl;
        return 0.0;
    }
}

int main() {
    string ekspresi;
    cout << "============================================" << endl;
    cout << "==========  KALKULATOR GRAFIK 2D  ==========" << endl;
    cout << "============================================" << endl;
    cout << "Masukkan ekspresi matematika yang ingin diplot:" << endl;
    cout << "Contoh: x^2, sin(x), cos(x), log(x)" << endl;
    cout << ">> ";
    getline(cin, ekspresi);

    vector<double> nilai_x, nilai_y;
    double x_awal = -10.0;
    double x_akhir = 10.0;
    double langkah = 0.1;

    // Menghitung pasangan (x, y)
    for (double x = x_awal; x <= x_akhir; x += langkah) {
        double y = evaluasi_ekspresi(ekspresi, x);
        nilai_x.push_back(x);
        nilai_y.push_back(y);
    }

    // Menampilkan hasil perhitungan
    cout << "\nHasil Perhitungan:" << endl;
    cout << "Y --- X" << endl;
    for (size_t i = 0; i < nilai_x.size(); ++i) {
        cout << nilai_y[i] << " --- " << nilai_x[i] << endl;
    }

    // Menampilkan grafik
    cout << "\nMembuat grafik..." << endl;
    plot(nilai_x, nilai_y);
    xlabel("Sumbu X");
    ylabel("Sumbu Y");
    title("Grafik dari " + ekspresi);
    grid(true);
    show();

    cout << "\nTerima kasih telah menggunakan kalkulator grafik 2D!" << endl;
    return 0;
}