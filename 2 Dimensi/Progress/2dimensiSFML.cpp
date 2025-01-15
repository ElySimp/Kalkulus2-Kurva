#include <SFML/Graphics.hpp>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
using namespace sf;

// Function to plot a graph
void plotGraph(RenderWindow &window, function<float(float)> func, 
               Color color, float scale, Vector2f origin) {
    VertexArray lines(LineStrip);

    for (float x = -origin.x / scale; x < (window.getSize().x - origin.x) / scale; x += 0.01f) {
        float y = func(x);
        float screenX = origin.x + x * scale;
        float screenY = origin.y - y * scale;

        if (screenY >= 0 && screenY < window.getSize().y) {
            lines.append(Vertex(Vector2f(screenX, screenY), color));
        }
    }

    window.draw(lines);
}

// Function to draw a grid on the window
void drawGrid(RenderWindow &window, float scale) {
    Color gridColor(200, 200, 200);  // Light gray grid

    // Draw vertical lines
    for (float x = 0; x < window.getSize().x; x += scale) {
        VertexArray gridLine(Lines, 2);
        gridLine[0].position = Vector2f(x, 0);
        gridLine[1].position = Vector2f(x, window.getSize().y);
        gridLine[0].color = gridColor;
        gridLine[1].color = gridColor;
        window.draw(gridLine);
    }

    // Draw horizontal lines
    for (float y = 0; y < window.getSize().y; y += scale) {
        VertexArray gridLine(Lines, 2);
        gridLine[0].position = Vector2f(0, y);
        gridLine[1].position = Vector2f(window.getSize().x, y);
        gridLine[0].color = gridColor;
        gridLine[1].color = gridColor;
        window.draw(gridLine);
    }
}

// Function to draw axis labels
void drawAxisLabels(RenderWindow &window, float scale, Vector2f origin) {
    Font font;
    if (!font.loadFromFile("Poppins-Regular.ttf")) {
        cout << "Error loading font" << endl;
        return;
    }

    Text text;
    text.setFont(font);
    text.setFillColor(Color::Black);

    // X-axis labels
    for (int x = -10; x <= 10; ++x) {
        ostringstream oss;
        oss << x;
        text.setString(oss.str());
        text.setCharacterSize(20);
        text.setPosition(origin.x + x * scale, origin.y + 5);
        window.draw(text);
    }

    // Y-axis labels
    for (int y = -10; y <= 10; ++y) {
        ostringstream oss;
        oss << -y;
        text.setString(oss.str());
        text.setCharacterSize(20);
        text.setPosition(origin.x + 5, origin.y - y * scale);
        window.draw(text);
    }
}

int main() {
    const int WIDTH = 800;
    const int HEIGHT = 600;
    const float SCALE = 50.0f;  // Pixels per unit

    RenderWindow window(VideoMode(WIDTH, HEIGHT), "2D Graphing Calculator");
    window.setFramerateLimit(60);

    Vector2f origin(WIDTH / 2.0f, HEIGHT / 2.0f);

    cout << "Enter a mathematical function to plot (e.g., sin(x), cos(x), x*x): ";
    string inputFunction;
    getline(cin, inputFunction);

    // Simple map of function names to actual lambda expressions
    map<string, function<float(float)>> functions = {
        {"sin", [](float x) { return sin(x); }},
        {"cos", [](float x) { return cos(x); }},
        {"x*x", [](float x) { return x * x; }},
        {"x", [](float x) { return x; }}
    };

    function<float(float)> chosenFunction;

    if (functions.find(inputFunction) != functions.end()) {
        chosenFunction = functions[inputFunction];
    } else {
        cout << "Function not recognized, defaulting to sin(x)." << endl;
        chosenFunction = functions["sin"];
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(Color::White);

        // Draw grid
        drawGrid(window, SCALE);

        // Draw axes
        VertexArray xAxis(Lines, 2);
        xAxis[0].position = Vector2f(0, origin.y);
        xAxis[1].position = Vector2f(WIDTH, origin.y);
        xAxis[0].color = Color::Black;
        xAxis[1].color = Color::Black;

        VertexArray yAxis(Lines, 2);
        yAxis[0].position = Vector2f(origin.x, 0);
        yAxis[1].position = Vector2f(origin.x, HEIGHT);
        yAxis[0].color = Color::Black;
        yAxis[1].color = Color::Black;

        window.draw(xAxis);
        window.draw(yAxis);

        // Draw axis labels
        drawAxisLabels(window, SCALE, origin);

        // Plot graph of the chosen function
        plotGraph(window, chosenFunction, Color::Red, SCALE, origin);

        window.display();
    }

    return 0;
}