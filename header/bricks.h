#pragma once
#include<SFML/Graphics.hpp>
#include "../header/player.h"
#include<iostream>
#include<vector>

class bricks {
private: 
	const static int ROWS = 4; 
	const static int COLS = 7; 

	std::vector<std::vector<int>>MATRIX= {
		{1, 1, 1, 1, 1, 1, 1 },
		{1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1}
	}; 

	std::vector<std::vector<sf::Sprite>> blocks;
	sf::Texture bricktexture;  

	bool flag; 
	int score, store; 
public: 
	bricks(); 

	void update(player& ba); 
	void render(sf::RenderWindow *window, player& ba); 
};
