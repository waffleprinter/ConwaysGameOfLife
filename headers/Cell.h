#ifndef CONWAYSGAMEOFLIFE_CELL_H
#define CONWAYSGAMEOFLIFE_CELL_H

#include <SFML/Graphics.hpp>

class Cell {
private:
    float size;
    sf::RectangleShape shape;

public:
    bool isAlive;

    Cell(bool alive, float cellSize, sf::Vector2f position);
    void toggle();
    void draw(sf::RenderWindow &window);
};


#endif //CONWAYSGAMEOFLIFE_CELL_H
