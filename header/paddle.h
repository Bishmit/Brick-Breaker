#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class paddle {
private: 
    sf::Texture paddleTex;
    sf::Sprite paddleSprite;
    float speed;
public:
    paddle();
    void update(sf::RenderTarget* target);
    void updateWallCollsion(sf::RenderTarget* window);
    void render(sf::RenderTarget* target);

    sf::Vector2f getpos();
    sf::FloatRect getbound(); 

};