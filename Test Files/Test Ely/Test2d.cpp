#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <functional>
#include <stack>
#include <cctype>

using namespace std;

// Fungsi untuk menghitung operator
double applyOperator(char op, double a, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: throw runtime_error("Operator tidak dikenal");
    }
}

// Fungsi untuk mengevaluasi ekspresi
double evaluateExpression(const string& expression, double x) {
    stack<double> values;
    stack<char> operators;

    auto precedence = [](char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    };

    auto performOperation = [&]() {
        if (values.size() < 2 || operators.empty())
            throw runtime_error("Ekspresi tidak valid");
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperator(op, a, b));
    };

    istringstream iss(expression);
    string token;
    while (iss >> token) {
        if (isdigit(token[0]) || token[0] == '.') {
            values.push(stod(token));
        } else if (token == "x") {
            values.push(x);
        } else if (token == "(") {
            operators.push('(');
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != '(') {
                performOperation();
            }
            if (operators.empty() || operators.top() != '(')
                throw runtime_error("Kurung tidak cocok");
            operators.pop();
        } else if (token.size() == 1 && string("+-*/^").find(token[0]) != string::npos) {
            char op = token[0];
            while (!operators.empty() && precedence(operators.top()) >= precedence(op)) {
                performOperation();
            }
            operators.push(op);
        } else {
            throw runtime_error("Token tidak valid: " + token);
        }
    }

    while (!operators.empty()) {
        performOperation();
    }

    if (values.size() != 1)
        throw runtime_error("Ekspresi tidak valid");

    return values.top();
}

// Fungsi untuk plotting grafik
void plotFunction(const string& function) {
    const int width = 81;  // Lebar tabel lebih besar (0 sampai 80)
    const int height = 41; // Tinggi tabel lebih besar (0 sampai 40)
    const double xMin = -20.0, xMax = 20.0;
    const double yMin = -10.0, yMax = 10.0;

    double dx = (xMax - xMin) / (width - 1);
    double dy = (yMax - yMin) / (height - 1);

    // Mencetak grid Kartesius
    for (int i = height - 1; i >= 0; --i) {
        for (int j = 0; j < width; ++j) {
            double x = xMin + j * dx;
            double y = yMin + i * dy;
            double yFunc = evaluateExpression(function, x);

            // Jika titik fungsi dekat dengan grid, tandai '*'
            if (abs(y - yFunc) < dy / 2) {
                cout << "*";
            } else if (abs(y) < dy / 2) { // Sumbu x
                cout << "-";
            } else if (abs(x) < dx / 2) { // Sumbu y
                cout << "|";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    string userFunction;
    cout << "Masukkan fungsi matematika (contoh: x^2 + 1, x + 1, x^2 - x): ";
    getline(cin, userFunction);

    cout << "\nTabel Kartesius (resolusi tinggi):\n";
    try {
        plotFunction(userFunction);
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}