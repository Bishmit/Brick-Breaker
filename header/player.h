#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
class player {
private: 
	sf::Texture balltex; 
	sf::Sprite ballsprite; 
	float movement; 
	void manageballboundariescondition(); 
public:
	bool ball_should_move, should_move_downward;
	player();

	void update(); 
	void render(sf::RenderTarget* target); 
	sf::FloatRect getbounds(); 
	sf::Vector2f getpos();
	void setposition(float x, float y); 
	float getmovement(); 
};