#pragma once
#include<SFML/Graphics.hpp>
#include "../header/player.h"
#include<iostream>

class bricks {
private: 
	const static int ROWS = 4; 
	const static int COLS = 5; 

	const int MATRIX[ROWS][COLS] = {
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1}
	}; 

	sf::Sprite blocks[ROWS][COLS]; 
	sf::Texture bricktexture;  

public: 
	bricks(); 

	void update(player& ba); 
	void render(sf::RenderWindow *window); 
};
