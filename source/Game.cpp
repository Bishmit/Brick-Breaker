#include "../header/Game.h"

Game::Game()
{
    initWindow();
}

Game::~Game()
{
    delete window;
}

void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(500, 600), "BreakOut");
    window->setFramerateLimit(60);
}

void Game::pollEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            window->close();
        }
    }
}

const bool Game::isGameRunning() const {
    return window->isOpen();
}

void Game::update() {
    pollEvent();
    p.update(window);
    b.update(ball); 
    ball.update(p); 
}

void Game::render() {
    window->clear();
    p.render(window);
    b.render(window); 
    ball.render(window); 
    window->display();
}
