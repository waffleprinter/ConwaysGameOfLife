#include "Game.h"

Game::Game() {
    initWindow();
    initBoard();
}

void Game::initWindow() {
    videoMode.width = 720;
    videoMode.height = 480;

    window.create(videoMode, "Conway's Game of Life", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initBoard() {
    float cellSize = 5.0f;
    float cellSizeWithPadding = cellSize + 1;
    int rows = videoMode.height / cellSizeWithPadding;
    int cols = videoMode.width / cellSizeWithPadding;

    board = Board(cellSize, cols, rows, sf::Vector2f(0, 0));
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
                else if (event.key.code == sf::Keyboard::Right && isPaused) {
                    isPaused = false;
                    update();
                    isPaused = true;
                }
                break;

            case(sf::Event::MouseButtonPressed):
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    float cellSizeWithPadding = board.cellSize + 1;
                    int col = mousePos.x / cellSizeWithPadding;
                    int row = mousePos.y / cellSizeWithPadding;

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


