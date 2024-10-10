#ifndef CONWAYSGAMEOFLIFE_BOARD_H
#define CONWAYSGAMEOFLIFE_BOARD_H

#include <vector>
#include <Cell.h>


class Board {
private:
    std::vector<std::vector<Cell>> cells;
    float cellSize;
    int width;
    int height;
    sf::Vector2f position;

public:
    Board(float cellSizeParam, int widthParam, int heightParam, sf::Vector2f pos);
    int getLiveNeighbors(std::vector<std::vector<bool>> &cellStates, int row, int col) const;
    void update();
    void draw(sf::RenderWindow &window);
};


#endif //CONWAYSGAMEOFLIFE_BOARD_H
