#ifndef CONWAYSGAMEOFLIFE_BOARD_H
#define CONWAYSGAMEOFLIFE_BOARD_H

#include <vector>
#include <Cell.h>


class Board {
private:
    std::vector<std::vector<Cell>> cells;
    int width;
    int height;
    sf::Vector2f position;

    int getLiveNeighbors(std::vector<std::vector<bool>> &cellStates, int row, int col) const;

public:
    float cellSize;

    Board(float cellSizeParam, int widthParam, int heightParam, sf::Vector2f pos);

    sf::Vector2f getPosition();
    void toggleCell(int row, int col);
    void clear();
    void update();
    void draw(sf::RenderWindow &window);
};


#endif //CONWAYSGAMEOFLIFE_BOARD_H
