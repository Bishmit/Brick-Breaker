#pragma once
#include<SFML/Graphics.hpp>

class player {
private: 
	sf::Texture balltex; 
	sf::Sprite ballsprite; 
public:
	player();

	void update(); 
	void render(sf::RenderTarget* target); 

};