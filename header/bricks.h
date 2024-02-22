#pragma once
#include<SFML/Graphics.hpp>
#include "../header/player.h"
#include<iostream>

class bricks {
private: 
	const static int ROWS = 4; 
	const static int COLS = 7; 

	int MATRIX[ROWS][COLS] = {
		{1, 1, 1, 1, 1, 1, 1 },
		{1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1}
	}; 

	sf::Sprite blocks[ROWS][COLS];
	sf::Texture bricktexture;  

	bool flag; 
	int score, store; 

	sf::Text text;
	sf::Font font;
public: 
	bricks(); 

	void update(player& ba); 
	void render(sf::RenderWindow *window, player& ba); 
};
