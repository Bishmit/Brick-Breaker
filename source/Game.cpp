#include "../header/Game.h"

Game::Game()
{
    initWindow();

    // background image 
    if (!bgtex.loadFromFile("Assets/Images/background.jpg")) {
        std::cout << "background not loaded" << "\n"; 
    }
    bgsprite.setTexture(bgtex);
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
    makeBallStickToPaddle(); 
}

void Game::render() {
    window->clear();
    window->draw(bgsprite); 
    p.render(window);
    b.render(window,ball); 
    ball.render(window); 
    window->display();
}

void Game::makeBallStickToPaddle() {
    if (ball.ball_should_move == false) {
        ball.setposition(p.getpos().x + p.getbound().width/2.5f, p.getpos().y-p.getbound().height);
    }
}