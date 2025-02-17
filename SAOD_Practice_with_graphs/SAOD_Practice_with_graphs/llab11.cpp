#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace sf;
using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float SCALE_X = 50.0f;
const float SCALE_Y = 100.0f;


float function(float x) {
    return std::sin(x); // График синуса
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Graph Plotter");
    window.setFramerateLimit(60);

    sf::VertexArray axes(sf::Lines, 4);
    axes[0].position = sf::Vector2f(WINDOW_WIDTH / 2, 0);
    axes[1].position = sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT);
    axes[2].position = sf::Vector2f(0, WINDOW_HEIGHT / 2);
    axes[3].position = sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT / 2);

    for (int i = 0; i < 4; i++) {
        axes[i].color = sf::Color::White;
    }

    std::vector<sf::Vertex> points;
    for (float x = -WINDOW_WIDTH / (2 * SCALE_X); x < WINDOW_WIDTH / (2 * SCALE_X); x += 0.01f) {
        float y = function(x);
        points.emplace_back(
            sf::Vector2f(WINDOW_WIDTH / 2 + x * SCALE_X, WINDOW_HEIGHT / 2 - y * SCALE_Y),
            sf::Color::Red
        );
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(axes);
        window.draw(&points[0], points.size(), sf::LineStrip);
        window.display();
    }

    return 0;
}
