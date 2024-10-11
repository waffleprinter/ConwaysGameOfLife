#include "Board.h"

Board::Board(float cellSizeParam, int widthParam, int heightParam, sf::Vector2f pos) {
    cells = std::vector<std::vector<Cell>>();

    cellSize = cellSizeParam;
    width = widthParam;
    height = heightParam;
    position = pos;

    // Create grid of cells
    for (int row = 0; row < height; row++) {
        std::vector cellsRow = std::vector<Cell>();

        for (int col = 0; col < width; col++) {
            float cellX = col * (cellSize + 1) + position.x;
            float cellY = row * (cellSize + 1) + position.y;

            Cell cell = Cell(true, cellSize, sf::Vector2f(cellX, cellY));
            cellsRow.push_back(cell);
        }

        cells.push_back(cellsRow);
    }
}

int Board::getLiveNeighbors(std::vector<std::vector<bool>> &cellStates, int row, int col) const {
    int liveNeighbors = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighborRow = row + i;
            int neighborCol = col + j;

            if (neighborRow == row && neighborCol == col)
                continue;

            if (0 <= neighborRow && neighborRow < height && 0 <= neighborCol && neighborCol < width) {
                if (cellStates[neighborRow][neighborCol])
                    liveNeighbors++;
            }
        }
    }

    return liveNeighbors;
}

void Board::toggleCell(int row, int col) {
    cells[row][col].toggle();
}

void Board::update() {
    // Temporary variable so that all later cell state changes will be done at the same time,
    // and will not accidentally be affected by changes done to other cells while iterating.
    std::vector<std::vector<bool>> cellStates;

    for (int row = 0; row < height; row++) {
        std::vector<bool> newRow;

        for (int col = 0; col < width; col++) {
            newRow.push_back(cells[row][col].isAlive);
        }

        cellStates.push_back(newRow);
    }

    // Changes cell states according to cellStates, since all changes should be done at the same time.
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int liveNeighbors = getLiveNeighbors(cellStates, row, col);

            if (cells[row][col].isAlive) {
                if (liveNeighbors < 2 || liveNeighbors > 3)
                    cells[row][col].toggle();
            } else {
                if (liveNeighbors == 3)
                    cells[row][col].toggle();
            }
        }
    }
}

void Board::draw(sf::RenderWindow &window) {
    for (std::vector<Cell>& row : cells) {
        for (Cell& cell : row) {
            cell.draw(window);
        }
    }
}
