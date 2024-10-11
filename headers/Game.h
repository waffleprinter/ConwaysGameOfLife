#ifndef CONWAYSGAMEOFLIFE_GAME_H
#define CONWAYSGAMEOFLIFE_GAME_H

#include <SFML/Graphics.hpp>
#include "Board.h"

class Game {
private:
    sf::RenderWindow window;
    sf::VideoMode videoMode;
    sf::Event event{};
    Board board = Board(0, 0, 0, sf::Vector2f(0, 0));

    bool isPaused = true;

    void initWindow();
    void initBoard();

    void pollEvents();
    void update();
    void draw();

public:
    Game();

    void run();
};


#endif //CONWAYSGAMEOFLIFE_GAME_H
