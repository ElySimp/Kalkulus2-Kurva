#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double evaluateFunction(double x) {
    return x * x + 1.0;
}

void plotFunction(double startX, double endX, double step, int width, int height) {
    vector<vector<char>> grid(height, vector<char>(width, ' '));

    double minX = startX;
    double maxX = endX;
    double minY = evaluateFunction(startX);
    double maxY = evaluateFunction(startX);

    for (double x = startX; x <= endX; x += step) {
        double y = evaluateFunction(x);
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }

    for (double x = startX; x <= endX; x += step) {
        double y = evaluateFunction(x);
        int px = (int)((x - minX) / (maxX - minX) * (width - 1));
        int py = (int)((y - minY) / (maxY - minY) * (height - 1));
        grid[height - 1 - py][px] = '*';
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

int main() {
    double startX = -20;
    double endX = 20;
    double step = 0.1;
    int width = 50;
    int height = 50;

    plotFunction(startX, endX, step, width, height);

    return 0;
}