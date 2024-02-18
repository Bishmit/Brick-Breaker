#include "../header/bricks.h"

bricks::bricks()
{
	if (!bricktexture.loadFromFile("Assets/Images/brick.png")) {
		std::cout << "Error loading brick" << "\n"; 
	}

	// defining the block properties
	int blockwidth = 50; 
	int blockheight = 30; 
	int startX = 100; 
	int startY = 100; 

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			if (MATRIX[row][col] == 1) {
				sf::Vector2f position(startX + col * blockwidth, startY + row * blockheight); 
				blocks[row][col].setTexture(bricktexture);
				blocks[row][col].setPosition(position);
				blocks[row][col].setScale(sf::Vector2f(0.5f, 0.5f)); 
			}
		}
	}
}

void bricks::update()
{
	// logic of bricks 
}

void bricks::render(sf::RenderWindow *window)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			if (MATRIX[row][col] == 1)
			{
				window->draw(blocks[row][col]);
			}
		}
	}
}
