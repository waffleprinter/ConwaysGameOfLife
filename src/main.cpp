#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Cell.h"

int main() {
    // Window
    sf::RenderWindow window(sf::VideoMode(720, 480), "SFML Test", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

    Cell cell = Cell(false, sf::Vector2f(360, 240));

    // Game loop
    while (window.isOpen()) {
        // Event polling
        while (window.pollEvent(event)) {
            switch (event.type) {
                case (sf::Event::Closed):
                    window.close();
                    break;

                case (sf::Event::KeyPressed):
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
            }
        }

        // Update
        cell.toggle();

        // Render
        window.clear();

        cell.draw(window);

        window.display();
    }

    return 0;
}