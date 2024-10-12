#include "Game.h"

Game::Game() {
    initWindow();
    initBoard();
}

void Game::initWindow() {
    videoMode.width = 1080;
    videoMode.height = 720;

    window.create(videoMode, "Conway's Game of Life", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initBoard() {
    float cellSize = 10.0f;
    float cellPadding = 1.0f;
    int rows = 50;
    int cols = 50;

    sf::Vector2f windowCenter;
    windowCenter.x = ((float)videoMode.width - (cellSize + cellPadding) * (float)cols) / 2;
    windowCenter.y = ((float)videoMode.height - (cellSize + cellPadding) * (float)rows) / 2;

    board = Board(cellSize, cols, rows, windowCenter);
}

void Game::pollEvents() {
    while (window.pollEvent(event)) {
        switch (event.type) {
            case (sf::Event::Closed):
                window.close();
                break;

            case (sf::Event::KeyPressed):
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                else if (event.key.code == sf::Keyboard::Space)
                    isPaused = !isPaused;
                else if (event.key.code == sf::Keyboard::C)
                    board.clear();
                else if (event.key.code == sf::Keyboard::Right && isPaused) {
                    isPaused = false;
                    update();
                    isPaused = true;
                }
                break;

            case(sf::Event::MouseButtonPressed):
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f boardPos = board.getPosition();

                    float cellSizeWithPadding = board.cellSize + 1;
                    int col = (mousePos.x - boardPos.x) / cellSizeWithPadding;
                    int row = (mousePos.y - boardPos.y) / cellSizeWithPadding;

                    board.toggleCell(row, col);
                }
                break;
        }
    }
}

void Game::update() {
    if (isPaused) return;

    board.update();
}

void Game::draw() {
    window.clear(sf::Color::White);

    board.draw(window);

    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        pollEvents();
        update();
        draw();
    }
}


