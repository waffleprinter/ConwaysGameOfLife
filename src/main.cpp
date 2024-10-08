#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    // Window
    sf::RenderWindow window(sf::VideoMode(720, 480), "SFML Test", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

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
    }

    // Update

    // Render
    window.clear(); // Clear old frame

    // Draw game

    window.display(); // Tells app that window is done drawing

    // End of application
    return 0;
}