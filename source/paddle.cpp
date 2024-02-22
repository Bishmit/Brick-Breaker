#include "../header/paddle.h"

paddle::paddle() : speed(5)
{
    if (!paddleTex.loadFromFile("Assets/Images/paddle.png")) {
        std::cout << "paddle not loaded" << "\n";
    }
    paddleSprite.setTexture(paddleTex);
    paddleSprite.setPosition(500.f / 2.f, 600.f - 10.f);

}

void paddle::update(sf::RenderTarget* target)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->paddleSprite.move(-this->speed, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->paddleSprite.move(this->speed, 0);
    }

    updateWallCollsion(target);
}

void paddle::updateWallCollsion(sf::RenderTarget *window) {
    if (paddleSprite.getGlobalBounds().left <= 0.f) {
        paddleSprite.setPosition(0.f, window->getSize().y - 10.f);
    }

    if (paddleSprite.getGlobalBounds().left + paddleSprite.getGlobalBounds().width >= window->getSize().x) {
        paddleSprite.setPosition(window->getSize().x - paddleSprite.getGlobalBounds().width, window->getSize().y - 10.f);
    }
}

void paddle::render(sf::RenderTarget* target)
{
    target->draw(paddleSprite);
}

sf::Vector2f paddle::getpos()
{
    return paddleSprite.getPosition();
}

sf::FloatRect paddle::getbound()
{
    return paddleSprite.getGlobalBounds();
}

