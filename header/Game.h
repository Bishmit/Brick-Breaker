#pragma once
#include <SFML/Graphics.hpp>
#include "../header/paddle.h"
#include "../header/bricks.h"
#include "../header/player.h"
#include <iostream>

class Game {
private:
    sf::RenderWindow* window;
    sf::Event event;
    paddle p; 
    bricks b; 
    player ball;
    sf::Texture bgtex; 
    sf::Sprite bgsprite;  
    void initWindow();
    void initFont();
    void pollEvent();

public:
    Game();
    ~Game();

    const bool isGameRunning() const;
    void update();
    void render();
    void makeBallStickToPaddle();
};