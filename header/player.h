#pragma once
#include<SFML/Graphics.hpp>
#include"paddle.h"
#include <iostream>
class player {
private: 
	sf::Texture balltex; 
	sf::Sprite ballsprite; 
	float movement_x, movement_y; 
	void manageballboundariescondition(); 
	int counter; 
public:
	bool ball_should_move;
	player();
	void update(paddle &pad);
	void makedirectionchange();

	void render(sf::RenderTarget* target); 
	sf::FloatRect getbounds(); 
	sf::Vector2f getpos();
	void setposition(float x, float y); 
	//float getmovement(); 
};