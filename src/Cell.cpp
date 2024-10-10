#include "Cell.h"

Cell::Cell(bool alive, float cellSize, sf::Vector2f position) {
    isAlive = alive;
    size = cellSize;
    shape.setPosition(position);
    shape.setSize(sf::Vector2f(size, size));
    shape.setFillColor(isAlive ? sf::Color::Green : sf::Color::Black);
}

sf::Vector2f Cell::getPosition() {
    return shape.getPosition();
}

void Cell::toggle() {
    isAlive = !isAlive;
    shape.setFillColor(isAlive ? sf::Color::Green : sf::Color::Black);
}

void Cell::draw(sf::RenderWindow &window) {
    window.draw(shape);
}
