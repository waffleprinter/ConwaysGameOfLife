#include "Board.h"

Board::Board(float cellSizeParam, int widthParam, int heightParam) {
    cells = std::vector<std::vector<Cell>>();

    cellSize = cellSizeParam;
    width = widthParam;
    height = heightParam;

    // Create grid of cells
    for (int row = 0; row < height; row++) {
        std::vector cellsRow = std::vector<Cell>();

        for (int col = 0; col < width; col++) {
            float cellX = col * (cellSize + 1);
            float cellY = row * (cellSize + 1) ;

            Cell cell = Cell(true, cellSize, sf::Vector2f(cellX, cellY));
            cellsRow.push_back(cell);
        }

        cells.push_back(cellsRow);
    }
}

void Board::update() {

}

void Board::draw(sf::RenderWindow &window) {
    for (std::vector<Cell>& row : cells) {
        for (Cell& cell : row) {
            cell.draw(window);
        }
    }
}
